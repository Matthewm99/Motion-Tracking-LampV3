# Motion Tracking Lamp

## Project Description

What it is, what it does, and how it works
A lamp that follows your motion using an ESP32 Cam Module to detect motion, translating to servo-driven movements to adjust position and orientation according to y-coordinate.

The ESP32 detects pink colour, so using my pink highlighter/sticky note I can have the lamp rotate up and down depending on where it is located. 

The system uses an ESP32-CAM to stream live video over WiFi, while a Python script processes the video feed using OpenCV to detect the position of the object. The detected position is then sent wirelessly via UDP to the ESP32, which controls a servo motor to physically move the lamp head.

The system uses an ESP32-CAM to stream live video over WiFi, while a Python script processes the video feed using OpenCV to detect the position of the object. The detected position is then sent wirelessly via UDP to the ESP32, which controls a servo motor to physically move the lamp head.

![alt text](/Images/Final_Project.mov)
![alt text](/Images/Final_Project_Base.JPG)
**Figure 1:** Here's a video of my final project 

## Bill of Materials

To create my project I used the following items. In the table each item is listed and a link to the source is included. If items were used that were not purchased (e.g., items from the DEN) then an equivalent item available for purchase is included. 

**Table 1:** Bill of Materials 

| Quantity | Description | Source | Cost ($) |
| ----------- | ----------- | ----------- | ----------- |
| 1 |  Freenove ESP32 CAM Dev Board Kit | [Amazon](https://www.amazon.ca/Freenove-Dual-core-Microcontroller-Projects-Tutorial/dp/B0CJJHXD1W/ref=asc_df_B0CJJHXD1W?mcid=c10407f91dba3e2e9642fb3028576d0f&tag=googleshopc0c-20&linkCode=df0&hvadid=706738331967&hvpos=&hvnetw=g&hvrand=12129328956890550102&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9001027&hvtargid=pla-2268075661878&hvocijid=12129328956890550102-B0CJJHXD1W-&hvexpln=0&gad_source=1&th=1) | 25.95 |
| 1 | 10pcs Small LED Light | [Amazon](https://www.amazon.ca/dp/B0GCNP8B3S/ref=sspa_dk_detail_1?pd_rd_i=B0GCNP8B3S&pd_rd_w=qq5x5&content-id=amzn1.sym.516c2169-755e-413a-a38a-68230f4ab66f&pf_rd_p=516c2169-755e-413a-a38a-68230f4ab66f&pf_rd_r=74XEQRFB8Y670TGV6E8Q&pd_rd_wg=qQFFg&pd_rd_r=856c79df-800b-4fa6-8a85-499ca1105ec8&s=hi&sp_csd=d2lkZ2V0TmFtZT1zcF9kZXRhaWw&th=1) | 8.99 |
| 1 | 3D Prints | [RPC/Friend] | 10 |
| 1 | SG90 Motor | [Amazon] (https://www.amazon.ca/Fixed-Wing-Controls-Airplane-Aeroplane-Helicopter/dp/B0G4VJCZGM/ref=asc_df_B0G4VJCZGM?mcid=6e92fd76695d34c2ab3dcc96109a18f4&tag=googleshopc0c-20&linkCode=df0&hvadid=774764310124&hvpos=&hvnetw=g&hvrand=377654382843507648&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9001027&hvtargid=pla-2473807653334&hvocijid=377654382843507648-B0G4VJCZGM-&hvexpln=0&gad_source=1&th=1) | 4.68 |

**Total Cost:** $49.62

## A Reflection on the Process
In this project, I built a real-time motion tracking system that integrates computer vision with physical actuation. The process involved configuring the ESP32 camera, setting up a wireless video stream, writing a Python script for color-based object tracking, and implementing UDP communication for low-latency control. One of the biggest challenges was debugging issues related to servo control, freezing, and hardware instability. Initially, the system experienced lag and crashes due to excessive processing on the ESP32, which I resolved by offloading computation to the laptop. Later, I encountered issues with servo movement, which were ultimately traced back to wiring and power distribution mistakes, including incorrectly connecting GPIO pins to power rails. Fixing these issues significantly improved system stability and performance.

### What
In this project, I built a real-time motion tracking system that integrates computer vision with physical actuation. The process involved configuring the ESP32 camera, setting up a wireless video stream, writing a Python script for color-based object tracking, and implementing UDP communication for low-latency control. One of the biggest challenges was debugging issues related to servo control, freezing, and hardware instability. Initially, the system experienced lag and crashes due to excessive processing on the ESP32, which I resolved by offloading computation to the laptop. Later, I encountered issues with servo movement, which were ultimately traced back to wiring and power distribution mistakes, including incorrectly connecting GPIO pins to power rails. Fixing these issues significantly improved system stability and performance.
### So What 
The importance of system-level thinking when working with embedded systems. It highlights how software, hardware, and networking must all work together correctly for a system to function. Even small mistakes in wiring or power delivery can completely break an otherwise correct program. Additionally, the project shows the benefit of distributing computation efficiently — using the ESP32 for streaming while leveraging a more powerful computer for vision processing resulted in a much smoother and more reliable system. This type of architecture is widely used in real-world robotics and IoT applications.

### Now What 
If I were to extend this project, I would add horizontal tracking using a second servo to create a full pan-tilt system. I could also improve the object detection by using more advanced techniques (e.g., machine learning instead of simple color thresholding) to make tracking more robust under different lighting conditions. Another improvement would be designing a proper power system using a dedicated external supply instead of relying on the bench, which would make the system more reliable and portable. Finally, I could integrate everything into a standalone system without requiring a laptop by optimizing or upgrading the embedded processing capabilities.
