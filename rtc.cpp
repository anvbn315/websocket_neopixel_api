#include "rtc.h"

#include <RTClib.h>

RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {
  "Sunday",
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday"
};

void setup_rtc() {
  // Serial.begin(115200);
  // Kiểm tra DS1307 có kết nối hay không
  if (!rtc.begin()) {
    Serial.println("Không tìm thấy DS1307, kiểm tra kết nối!");
  }

  // Thiết lập thời gian mới (cập nhật mỗi khi nạp code)
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println("Đã cập nhật thời gian cho DS1307!");

  // Kiểm tra nếu DS1307 đang chạy
  // if (!rtc.isrunning()) {
  //   Serial.println("DS1307 không chạy, khởi động lại!");
  //   rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // }
}

void print_now() {
  DateTime now = rtc.now();
  Serial.print("Date & Time: ");
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);

  delay(1000);  // delay 1 seconds
}

DateTime get_now() {
  return rtc.now();
}