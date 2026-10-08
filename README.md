# ESP32 Dual LED Control with OneButton Library

Dự án điều khiển 2 LED (LED Built-in và LED ngoại vi) thông qua 1 nút bấm duy nhất sử dụng vi điều khiển ESP32 và thư viện OneButton trên nền tảng PlatformIO.

Tính năng chính
- Double Click (Nhấn 2 lần): Chuyển đổi đối tượng điều khiển giữa LED 1(Built-in) và LED 2(Ngoại vi).
- Single Click (Nhấn 1 lần): Bật/Tắt con LED đang được chọn.
- Hold (Nhấn giữ >1s): Chuyển con LED đang được chọn sang chế độ Nhấp nháy liên tục (200ms/lần).
- Tự động lọc nhiễu nút bấm (Debounce) và điều khiển bất đồng bộ (Non-blocking) không dùng `delay()`.

Sơ đồ kết nối phần cứng
- LED 1 (Built-in LED): Chân GPIO 2 trên devboard (Active HIGH).
- LED 2 (Ngoại vi trên test board):
  - Anode (+) -> Điện trở 1k -> Nguồn 3.3V
  - Cathode (-) -> Chân GPIO 5 (Active LOW)
- Nút bấm (Button):
  - Chân 1 -> Chân GPIO 22
  - Chân 2 -> Chân GND (Active LOW)

Hướng dẫn biên dịch & Nạp code
1. Mở dự án trong VS Code với extension PlatformIO IDE.
2. Nhấn biểu tượng Build để biên dịch.
3. Kết nối ESP32 vào máy tính và bấm Upload để nạp code.