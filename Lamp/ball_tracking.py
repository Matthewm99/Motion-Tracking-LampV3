import cv2              # OpenCV for video + image processing
import numpy as np      # numerical operations (arrays)
import socket           # UDP communication
import time             # timing for rate limiting

ESP_IP = "192.168.4.1"     # ESP32 IP (WiFi AP)
UDP_PORT = 4210            # UDP port (must match ESP32)

# Create UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# MJPEG stream from ESP32 camera
url = f"http://{ESP_IP}:81/stream"
cap = cv2.VideoCapture(url)

# If stream fails → exit
if not cap.isOpened():
    print("❌ Failed to open stream")
    exit()

# HSV range for detecting pink object
lower_pink = np.array([140, 50, 50])
upper_pink = np.array([180, 255, 255])

# Store recent positions for smoothing
history = []
SMOOTH_N = 3   # lower = more responsive

last_send = 0  # time of last UDP send
prev_y = None

print("✅ Tracking started")

while True:
    ret, frame = cap.read()

    # Skip bad frames
    if not ret or frame is None:
        continue

    # Convert to HSV color space (better for color detection)
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Create mask for pink color
    mask = cv2.inRange(hsv, lower_pink, upper_pink)

    # Find contours (blobs)
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    if contours:
        # Get largest blob
        c = max(contours, key=cv2.contourArea)

        # Fit circle around it
        (x, y), radius = cv2.minEnclosingCircle(c)

        if radius > 5:
            y = int(y)

            # ===== SMOOTHING =====
            history.append(y)
            if len(history) > SMOOTH_N:
                history.pop(0)

            # Average for smoother motion
            y_smooth = int(sum(history) / len(history))
            y_smooth = 240 - y_smooth # invert y axis

            # ===== SEND VIA UDP (HARD THROTTLE) =====
            now = time.time()

            if now - last_send > 0.2: # 5 Hz max (Very safe for ESP32)
                sock.sendto(str(y_smooth).encode(), (ESP_IP, UDP_PORT))
                last_send = now
                prev_y = y_smooth
            # if prev_y is None or abs(y_smooth - prev_y) > 15:
            #     if time.time() - last_send > 0.15:
            #         sock.sendto(str(y_smooth).encode(), (ESP_IP, UDP_PORT))
            #         last_send = time.time()
            #         prev_y = y_smooth

            # Draw tracking circle
            cv2.circle(frame, (int(x), int(y)), int(radius), (0,255,0), 2)

    # Show camera + mask
    cv2.imshow("Camera", frame)
    cv2.imshow("Mask", mask)

    # Press q to quit
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()