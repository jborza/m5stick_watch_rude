#include "M5StickC.h"

RTC_TimeTypeDef RTC_TimeStruct;
RTC_DateTypeDef RTC_DateStruct;

void setup() {
M5.begin();
//horizontal rotation
M5.Lcd.setRotation(3);
M5.Lcd.fillScreen(BLACK);
M5.Lcd.setTextSize(1);
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

char buffer[64];

char *simple_digits[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR","FIVE",
  "SIX", "SEVEN", "EIGHT", "NINE", "TEN", 
  "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", 
  "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN", "TWENTY"};

char *tens_digits[] = {"", "", "TWENTY", "THIRTY", "FORTY", "FIFTY",
                              "SIXTY", "SEVENTY", "EIGHTY", "NINETY"};
                              
void formatNumber(int number){
  if(number < 20){
    sprintf(buffer, "%s", simple_digits[number]);
    return;
  }
  else{
    int tens = number / 10;
    int remainder = number % 10;
    if(remainder == 0)
      sprintf(buffer,"%s", tens_digits[tens]);
    else
      sprintf(buffer, "%s%s", tens_digits[tens], simple_digits[remainder]);
    return;
  }
}

int i = 0;
int lastMinute = -1;

#define CENTER 80
#define FONT 1

void loop() {
M5.Rtc.GetTime(&RTC_TimeStruct);
//refresh screen only if the text changes
if(RTC_TimeStruct.Minutes != lastMinute){
  M5.Lcd.fillScreen(BLACK);  
}
M5.Lcd.setTextDatum(TC_DATUM);
lastMinute = RTC_TimeStruct.Minutes;

M5.Lcd.drawString("Holy shit, it's already", CENTER, 6);

M5.Lcd.setTextSize(2);
formatNumber(RTC_TimeStruct.Hours);
M5.Lcd.drawString(buffer, CENTER, 17);

M5.Lcd.setTextSize(1);
M5.Lcd.drawString("FUCKING", CENTER, 36);

M5.Lcd.setTextSize(2);
formatNumber(RTC_TimeStruct.Minutes);
M5.Lcd.drawString(buffer, CENTER, 48);

M5.Lcd.setTextSize(1);
M5.Lcd.drawString("MOTHERFUCKER!", CENTER, 66);

//draw a frame around the text
M5.Lcd.setCursor(0, 0);
M5.Lcd.drawRoundRect(2,2,150,76,4,RED);
delay(1000);
}
