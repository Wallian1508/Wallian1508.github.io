#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int SENSOR_PIN = A0;

int count = 0;
int threshold = 500;

unsigned long lightStart = 0;
unsigned long darkStart = 0;

bool isLight = false;

String currentMorse = "";
String result = "";

String decodeMorse(String code) {

  if (code == ".-") return "A";
  if (code == "-...") return "B";
  if (code == "-.-.") return "C";
  if (code == "-..") return "D";
  if (code == ".") return "E";
  if (code == "..-.") return "F";
  if (code == "--.") return "G";
  if (code == "....") return "H";
  if (code == "..") return "I";
  if (code == ".---") return "J";
  if (code == "-.-") return "K";
  if (code == ".-..") return "L";
  if (code == "--") return "M";
  if (code == "-.") return "N";
  if (code == "---") return "O";
  if (code == ".--.") return "P";
  if (code == "--.-") return "Q";
  if (code == ".-.") return "R";
  if (code == "...") return "S";
  if (code == "-") return "T";
  if (code == "..-") return "U";
  if (code == "...-") return "V";
  if (code == ".--") return "W";
  if (code == "-..-") return "X";
  if (code == "-.--") return "Y";
  if (code == "--..") return "Z";

  if (code == "-----") return "0";
  if (code == ".----") return "1";
  if (code == "..---") return "2";
  if (code == "...--") return "3";
  if (code == "....-") return "4";
  if (code == ".....") return "5";
  if (code == "-....") return "6";
  if (code == "--...") return "7";
  if (code == "---..") return "8";
  if (code == "----.") return "9";

  if (code == "-...-") return " ";
  if (code == ".-.-.-") return ".";
  if (code == "---...") return ":";
  if (code == "--..--") return ",";
  if (code == "-.-.-.") return ";";
  if (code == "..--..") return "?";
  if (code == "-...-") return "=";
  if (code == ".----.") return "'";
  if (code == "-..-.") return "/";
  if (code == "-.-.--") return "!";
  if (code == "-....-") return "-";
  if (code == "..--.-") return "_";
  if (code == ".-..-.") return "\"";
  if (code == "-.--.") return "(";
  if (code == "-.--.-") return ")";
  if (code == "...-..-") return "$";
  if (code == ".-...") return "&";
  if (code == ".--.-.") return "@";
  if (code == ".-.-.") return "+";
  if (code == "......." || code == "........" || code == ".........")
  {
    lcd.setCursor((count - 1) % 16, (count - 1) / 16);
    count-=2;
    return " ";
  }

  return "?";
}

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  Serial.begin(9600);

  int value = analogRead(SENSOR_PIN);

  isLight = value > threshold;

  if (isLight) {
    lightStart = millis();
  } else {
    darkStart = millis();
  }
}

void loop()
  {

  int value = analogRead(SENSOR_PIN);
  if(count < 0)
    count = 0;

  lcd.setCursor(count % 16, count / 16);

  //lcd.print(value);
  //lcd.setCursor(0, 0);

  bool newLight = value > threshold;
  unsigned long darkTime = millis() - darkStart;

  if (darkTime >= 1000 && currentMorse.length() > 0)
  {
    String letter = decodeMorse(currentMorse);
    Serial.print(letter);
    lcd.print(letter);
    count++;
    if(count < 0)
      count = 0;
    lcd.setCursor(count % 16, count / 16);
    currentMorse = "";
  }

  // 暗 → 亮
  if (!isLight && newLight)
  {
    // 暗太久 → 結束一個字母
    lightStart = millis();
    isLight = true;
  }

  // 亮 → 暗
  if (isLight && !newLight) {

    unsigned long lightTime = millis() - lightStart;

    if (lightTime < 200) {
      currentMorse += ".";
      Serial.print(".");
    }
    else {
      currentMorse += "-";
      Serial.print("-");
    }

    darkStart = millis();
    isLight = false;
  }
}
