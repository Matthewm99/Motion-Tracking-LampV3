import cv2
import numpy as np
import requests
import time

ESP_IP = "192.168.4.1"

url = f"http://{ESP_IP}:81/stream"
cap = cv2.VideoCapture(url)

lower_pink = np.array([140, 50, 50])
upper_pink = np.array([180, 255, 255])

history = []
SMOOTH_N = 5

last_send = 0
prev_y = None

print("Tracking started")

while True:
    ret, frame = cap.read()
    if not ret:
        continue

    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    mask = cv2.inRange(hsv, lower_pink, upper_pink)

    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    if contours:
        c = max(contours, key=cv2.contourArea)
        (x, y), radius = cv2.minEnclosingCircle(c)

        if radius > 5:
            y = int(y)

            history.append(y)
            if len(history) > SMOOTH_N:
                history.pop(0)
            y_smooth = sum(history) / len(history)
            if prev_y is None or abs(y_smooth - prev_y) > 20:
                if time.time() - last_send > 0.25:
                    try:
                        requests.get(
                            f"http://{ESP_IP}:82/servo?y={y_smooth}",
                            timeout=0.05
                        )
                        last_send = time.time()
                        prev_y = y_smooth
                    except:
                        pass

            # 🔥 ONLY SEND IF MEANINGFUL CHANGE
            # if prev_y is None or abs(y - prev_y) > 10:
            #     # 🔥 LIMIT RATE (MOST IMPORTANT FIX)
            #     if time.time() - last_send > 0.15:
            #         try:
            #             requests.get(
            #                 f"http://{ESP_IP}:82/servo?y={y}",
            #                 timeout=0.03
            #             )
            #             last_send = time.time()
            #             prev_y = y
            #         except:
            #             pass

            cv2.circle(frame, (int(x), int(y)), int(radius), (0,255,0), 2)

    cv2.imshow("Camera", frame)
    cv2.imshow("Mask", mask)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()