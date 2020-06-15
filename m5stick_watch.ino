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

void loop() {
// put your main code here, to run repeatedly:

M5.Rtc.GetTime(&RTC_TimeStruct);
if(RTC_TimeStruct.Minutes != lastMinute){
  M5.Lcd.fillScreen(BLACK);  
}
lastMinute = RTC_TimeStruct.Minutes;

M5.Lcd.setCursor(10, 5);
M5.Lcd.println("Holy shit, it's already");
//M5.Lcd.printf("Time: %02d : %02d : %02d\n",RTC_TimeStruct.Hours, RTC_TimeStruct.Minutes, RTC_TimeStruct.Seconds);

M5.Lcd.setTextSize(2);
M5.Lcd.setCursor(10,16);
formatNumber(RTC_TimeStruct.Hours);
M5.Lcd.println(buffer);
//M5.Lcd.println("     SIX");

M5.Lcd.setTextSize(1);
M5.Lcd.setCursor(0,34);
M5.Lcd.println("        FUCKING  ");

M5.Lcd.setTextSize(2);
M5.Lcd.setCursor(10,46);
formatNumber(RTC_TimeStruct.Minutes);
M5.Lcd.println(buffer);
//M5.Lcd.println(" TWENTYEIGHT");

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

//frame
M5.Lcd.setCursor(0, 0);

M5.Lcd.drawRoundRect(2,2,150,76,4,RED);
delay(1000);
} 
