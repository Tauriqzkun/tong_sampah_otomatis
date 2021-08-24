#include <Servo.h> // memanggil library servo
#include <NewPing.h> // memanggil library sensor ultrasonic

Servo myservo; // inisialisasi myservo
#define TRIGGER_PIN 2 // Pin Trigger dihubungkan ke Pin Digital 5 Arduino
#define ECHO_PIN 3 // Pin Echo dihubungkan ke pin Digital 6 Arduino
#define MAX_DISTANCE 50 // Batas jarak pengukuran sensor ultrasonic 
#define pinservo 4
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
  myservo.attach(pinservo); // Pin Out Servo dihubungkan ke Pin Digital 2 Arduino
  Serial.begin(9600);
}

void loop() {
delay(50); 
int jarak = sonar.ping_cm(); // Variabel "Jarak" untuk menampung hasil pengukuran jarak
Serial.println(jarak);
if((jarak>0)&&(jarak<=100))
  {
  delay(50); // jeda waktu 50 ms
  myservo.write(10); // Membuat servo berputar 10° (membuka kotak sampah)
  delay(2000); // jeda waktu kotak sampah terbuka 2 detik
  myservo.write(120); // Membuat servo berputar 120° (menutup kotak sampah)
  delay(1500); //jeda waktu kotak sampah tertutup 1,5 detik 
  }
}
