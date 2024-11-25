#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Servo.h>

// DHT 센서 설정
#define DHTPIN 2        // DHT 데이터 핀
#define DHTTYPE DHT11   // DHT 유형: DHT11 또는 DHT22 사용 가능
DHT dht(DHTPIN, DHTTYPE);

// I2C LCD 설정 (주소: 0x27 또는 0x3F, LCD 크기: 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// L9110 팬 제어 핀
#define FAN_INA 5
#define FAN_INB 6

// 서보모터 핀 설정
#define SERVO_PIN 9
Servo servo; // 서보 객체 생성

// 팬 속도 설정 (0~255)
#define FAN_SPEED 80 // 약한 속도로 설정 (기존 150에서 80으로 변경)

void setup() {
  // LCD 초기화
  lcd.init();
  lcd.backlight();

  // DHT 센서 초기화
  dht.begin();

  // 팬 제어 핀 설정
  pinMode(FAN_INA, OUTPUT);
  pinMode(FAN_INB, OUTPUT);

  // 서보모터 초기화
  servo.attach(SERVO_PIN);
  servo.write(90); // 초기 위치 (중립: 멈춤)

  // 초기 메시지 출력
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  delay(2000);
}

void loop() {
  // 온도와 습도 값 읽기
  float temperature = dht.readTemperature(); // 섭씨 온도
  float humidity = dht.readHumidity();

  // 센서 읽기 실패 시 처리
  if (isnan(temperature) || isnan(humidity)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error   ");
    lcd.setCursor(0, 1);
    lcd.print("Try Again...   ");
    // 팬과 서보모터 OFF
    analogWrite(FAN_INA, 0); // 팬 OFF
    digitalWrite(FAN_INB, LOW);
    servo.write(90); // 서보 정지
    delay(2000);
    return;
  }

  // LCD에 온도와 습도 값 표시
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C    "); // 공백 추가로 남은 글자 지우기

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %    ");

  // 팬 및 서보모터 제어 조건 (온도 > 28도 또는 습도 > 80%)
  if (temperature > 28 || humidity > 80) {
    // 팬 ON (속도 설정)
    analogWrite(FAN_INA, FAN_SPEED); // FAN_SPEED 값으로 팬 속도 조절
    digitalWrite(FAN_INB, LOW);

    // 서보모터 360도 정방향 회전 (속도 설정)
    servo.write(180); // 최대 정방향 속도
  } else {
    // 팬 OFF
    analogWrite(FAN_INA, 0); // 팬 정지
    digitalWrite(FAN_INB, LOW);

    // 서보모터 -360도 역방향 회전 (속도 설정)
    servo.write(0); // 최대 역방향 속도
  }

  // 2초 대기 후 업데이트
  delay(2000);
}
