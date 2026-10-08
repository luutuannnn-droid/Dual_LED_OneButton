#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

#define LED1_PIN 2      // GPIO 2 (Built-in LED)
#define LED1_ACT HIGH   // Active HIGH

#define LED2_PIN 5      // GPIO 5 (LED ngoại vi trên test board)
#define LED2_ACT LOW    // Active LOW

#define BTN_PIN 22      // GPIO 22 (Nút bấm)
#define BTN_ACT LOW     // Active LOW (nhấn nối GND)

LED led1(LED1_PIN, LED1_ACT);
LED led2(LED2_PIN, LED2_ACT);

// Con trỏ chỉ tới LED đang được chọn để điều khiển (Mặc định chọn LED 1)
LED* activeLed = &led1;
int activeLedIndex = 1;

// Khởi tạo OneButton (activeLow = true)
OneButton button(BTN_PIN, !BTN_ACT);

void btnPush();
void btnHold();
void btnDoubleClick();

void setup()
{
    Serial.begin(115200);

    led1.off();
    led2.off();
    button.attachClick(btnPush);                 // Single click -> Bật/Tắt LED đang chọn
    button.attachDoubleClick(btnDoubleClick);   // Double click -> Đổi LED điều khiển
    button.attachLongPressStart(btnHold);       // Hold -> Nhấp nháy 200ms LED đang chọn

    Serial.println("System Ready! Default controlling LED 1 (Built-in).");
}

void loop()
{
    led1.loop();
    led2.loop();
    button.tick();
}

// 1. Single click: Bật/Tắt LED đang được chọn
void btnPush()
{
    activeLed->flip();
    Serial.printf("Single Click: Switched LED %d state\n", activeLedIndex);
}

// 2. Double click: Chuyển quyền điều khiển giữa LED 1 và LED 2
void btnDoubleClick()
{
    if (activeLedIndex == 1) {
        activeLed = &led2;
        activeLedIndex = 2;
    } else {
        activeLed = &led1;
        activeLedIndex = 1;
    }
    Serial.printf("Double Click: Active control switched to LED %d\n", activeLedIndex);
}

// 3. Hold (>1s): Chuyển sang nhấp nháy 200ms con LED đang chọn
void btnHold()
{
    activeLed->blink(200);
    Serial.printf("Hold: LED %d blinking (200ms)\n", activeLedIndex);
}