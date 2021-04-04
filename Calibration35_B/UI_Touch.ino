////////////////////////////////////////////////////////////////////////////////////////////
/// 処理部 //////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// ﾀｯﾁの取得 ------------------------------------------------
void Get_touch() {
  while (true) {
    Touch_flg = false;                                     // 画面に触ってない
    TSPoint p = TS.getPoint();
    DDRF |= YPXM_PORT;
    if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      switch (Scr_Angle) {                                 // 1=90度右に回転,2=180度,3=270度,0=0度
      case 0:
        Th_X = map(p.x, TS_LEFT, TS_RIGHT, 0, 320);
        Th_Y = map(p.y, TS_UP, TS_DOWN, 0, 480);
        break;
      case 1:
        Th_X = map(p.y, TS_UP, TS_DOWN, 0, 480);
        Th_Y = map(p.x, TS_RIGHT, TS_LEFT, 0, 320);
        break;
      case 2:
        Th_X = map(p.x, TS_RIGHT, TS_LEFT, 0, 320);
        Th_Y = map(p.y, TS_DOWN, TS_UP, 0, 480);
        break;
      case 3:
        Th_X = map(p.y, TS_DOWN, TS_UP, 0, 480);
        Th_Y = map(p.x, TS_LEFT, TS_RIGHT, 0, 320);
      }
      if ((Th_X > 0) && (Th_Y > 0)) {
//Serial.print(F("p.x = "));Serial.print(p.x);               // debug
//Serial.print(F("\tp.y = "));Serial.print(p.y);             // debug
//Serial.print(F("\tTh_X = "));Serial.print(Th_X);           // debug
//Serial.print(F("\tTh_Y = "));Serial.println(Th_Y);         // debug
//      delay (50);
        Touch_flg = true;                                  // 画面に触った
        return;
      }
    }
  }
}


// そのﾎﾞﾀﾝが押されたかﾁｪｯｸ ------------------------------------------------
void Touch_check(int X1, int Y1, int X2, int Y2) {

  int X3 = X1 + X2;
  int Y3 = Y1 + Y2;
  
  if ((Th_X == 0) || (Th_Y == 0)) {
    Touch_flg = false;
    return;
  }
  if (((X1 <= Th_X)&&(Th_X <= X3))&&((Y1 <= Th_Y)&&(Th_Y <= Y3))) {
    Touch_flg = true;
  } else {
    Touch_flg = false;
  }
}


// EEPROMからﾀｯﾁｸﾘｰﾝのｷｬﾘﾌﾞﾚｰｼｮﾝ設定を読込む ------------------------------------------------
void Calibration_EEPROM_read() {

  byte byte_LowByte, byte_HighByte;
  int int_LowByte, int_HighByte;
  // 0x10-0x11:TS_LEFT
  byte_LowByte  = EEPROM.read(0x10);
  byte_HighByte = EEPROM.read(0x11);
  int_LowByte   = byte_LowByte;
  int_HighByte  = byte_HighByte;
  TS_LEFT = int_HighByte * 256 + int_LowByte;
  if (TS_LEFT == 0) {
    TS_LEFT = DTS_LEFT;
  }
  // 0x12-0x13:TS_RIGHT
  byte_LowByte  = EEPROM.read(0x12);
  byte_HighByte = EEPROM.read(0x13);
  int_LowByte   = byte_LowByte;
  int_HighByte  = byte_HighByte;
  TS_RIGHT = int_HighByte * 256 + int_LowByte;
  if (TS_RIGHT == 0) {
    TS_RIGHT = DTS_RIGHT;
  }
  // 0x14-0x15:TS_UP
  byte_LowByte  = EEPROM.read(0x14);
  byte_HighByte = EEPROM.read(0x15);
  int_LowByte   = byte_LowByte;
  int_HighByte  = byte_HighByte;
  TS_UP = int_HighByte * 256 + int_LowByte;
  if (TS_UP == 0) {
    TS_UP = DTS_UP;
  }
  // 0x16-0x17:TS_DOWN
  byte_LowByte  = EEPROM.read(0x16);
  byte_HighByte = EEPROM.read(0x17);
  int_LowByte   = byte_LowByte;
  int_HighByte  = byte_HighByte;
  TS_DOWN = int_HighByte * 256 + int_LowByte;
  if (TS_DOWN == 0) {
    TS_DOWN = DTS_DOWN;
  }
}


//
