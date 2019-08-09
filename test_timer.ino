// Toggle LED on pin 13 each second

void flash() {
  static boolean output = HIGH;
  digitalWrite(BOARD_LED_PIN, output);
  output = !output;
}

void setup() {
  // タイマ1設定
  const int channel = 1;    // channeは1を使う
  Timer1.pause();
  Timer1.setPeriod(1000);   // 周期1000msec
  Timer1.setCompare(channel, Timer1.getOverflow());
  Timer1.attachInterrupt(channel, flash); // 割り込み関数設定
  Timer1.refresh();
  Timer1.resume();
}

void loop() {
  
}