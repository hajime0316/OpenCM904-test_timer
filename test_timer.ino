
#define PERIOD ((uint32)1000000) // microsec

void timer1_interrupt_handler() {
  static boolean output = HIGH;
  digitalWrite(BOARD_LED_PIN, output);
  digitalWrite(6, output);
  output = !output;
}

void setup() {
  pinMode(BOARD_LED_PIN, OUTPUT);
  pinMode(6, OUTPUT);

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
  Timer1.attachInterrupt(channel, timer1_interrupt_handler);
  //// タイマのリフレッシュ(設定の適応)
  Timer1.refresh();
  //// タイマ再開
  Timer1.resume();
}

void loop() {

}