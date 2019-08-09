
#define PERIOD ((uint32)1000000) // microsec

void flash() {
  static boolean output = HIGH;
  digitalWrite(BOARD_LED_PIN, output);
  output = !output;
}

void setup() {

  pinMode(BOARD_LED_PIN, OUTPUT);
  // タイマ1設定
  //// channeは1を使う
  const int channel = 1;
  //// タイマ停止
  Timer1.pause();
  //// 周期設定
  Timer1.setPeriod(PERIOD);
  //// コンペアチャンネルの設定
  Timer1.setCompare(channel, Timer1.getOverflow());
  //// 割り込み関数設定
  Timer1.attachInterrupt(channel, flash);
  //// タイマのリフレッシュ(設定の適応)
  Timer1.refresh();
  //// タイマ再開
  Timer1.resume();
}

void loop() {

}