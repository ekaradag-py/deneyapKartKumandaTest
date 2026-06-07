// --- KUMANDA (ALICI) TEST KODU ---
// Flysky FS-i6'dan gelen PWM sinyallerini test etmek icindir.

const int RX_AIL_PIN = D4;  // CH1 - Roll (Aileron)
const int RX_ELE_PIN = D5;  // CH2 - Pitch (Elevator)
const int RX_RUD_PIN = D6;  // CH4 - Yaw (Rudder)

void setup() {
  Serial.begin(115200);

  pinMode(RX_AIL_PIN, INPUT);
  pinMode(RX_ELE_PIN, INPUT);
  pinMode(RX_RUD_PIN, INPUT);

  Serial.println("Kumanda test modu baslatildi...");
  Serial.println("Aileron(CH1) | Elevator(CH2) | Rudder(CH4)");
  Serial.println("------------------------------------------");
}

void loop() {
  // pulseIn ile sinyalleri oku (20ms timeout ile)
  unsigned long rx_ail = pulseIn(RX_AIL_PIN, HIGH, 20000);
  unsigned long rx_ele = pulseIn(RX_ELE_PIN, HIGH, 20000);
  unsigned long rx_rud = pulseIn(RX_RUD_PIN, HIGH, 20000);

  // Sinyal koparsa (kumanda kapalıysa) veya kablo temassızsa uyarı ver
  if (rx_ail == 0 && rx_ele == 0 && rx_rud == 0) {
    Serial.println("UYARI: Alicidan sinyal alinamiyor! Baglantilari kontrol edin.");
  } else {
    // ESP32'nin printf destegi ile temiz bir konsol ciktisi olustur
    Serial.printf("Aileron: %4lu us | Elevator: %4lu us | Rudder: %4lu us\n", rx_ail, rx_ele, rx_rud);
  }

  delay(100);  // Konsolun okunabilirligi icin 100ms gecikme
}