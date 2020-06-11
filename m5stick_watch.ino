#include "M5StickC.h"

RTC_TimeTypeDef RTC_TimeStruct;
RTC_DateTypeDef RTC_DateStruct;

void setup() {
// put your setup code here, to run once:
M5.begin();
M5.Lcd.setRotation(3);
M5.Lcd.fillScreen(BLACK);
M5.Lcd.setTextSize(1);
//M5.Lcd.setCursor(40, 0, 2);
//M5.Lcd.println("RTC TEST");

}

void set_time(){
RTC_TimeTypeDef TimeStruct;
TimeStruct.Hours = 17;
TimeStruct.Minutes = 52;
TimeStruct.Seconds = 00;
M5.Rtc.SetTime(&TimeStruct);
RTC_DateTypeDef DateStruct;
DateStruct.WeekDay = 3;
DateStruct.Month = 6;
DateStruct.Date = 11;
DateStruct.Year = 2020;
M5.Rtc.SetData(&DateStruct);
}

void loop() {
// put your main code here, to run repeatedly:

M5.Rtc.GetTime(&RTC_TimeStruct);
M5.Lcd.setCursor(10, 5);
M5.Lcd.println("Holy shit, it's already");

M5.Lcd.setTextSize(2);
M5.Lcd.setCursor(0,16);
M5.Lcd.println("     SIX");

M5.Lcd.setTextSize(1);
M5.Lcd.setCursor(0,34);
M5.Lcd.println("         FUCKING  ");

M5.Lcd.setTextSize(2);
M5.Lcd.setCursor(0,46);
M5.Lcd.println(" TWENTYEIGHT");

//goot position
M5.Lcd.setTextSize(1);
M5.Lcd.setCursor(0,66);
M5.Lcd.println("      MOTHERFUCKER!");
//M5.Rtc.GetData(&RTC_DateStruct);
//M5.Lcd.setCursor(0, 15);
//M5.Lcd.printf("Date: %04d-%02d-%02d\n",RTC_DateStruct.Year, RTC_DateStruct.Month,RTC_DateStruct.Date);
//M5.Lcd.setTextColor(TFT_YELLOW);
//M5.Lcd.printf("Week: %d\n",RTC_DateStruct.WeekDay);
//M5.Lcd.printf("Time: %02d : %02d : %02d\n",RTC_TimeStruct.Hours, RTC_TimeStruct.Minutes, RTC_TimeStruct.Seconds);

M5.Lcd.setCursor(0, 0);
M5.Lcd.drawRoundRect(2,2,150,76,4,RED);
delay(500);
} 
