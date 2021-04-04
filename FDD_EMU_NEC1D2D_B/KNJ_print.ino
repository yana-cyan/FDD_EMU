///////////////////////////////////////////////////////////////////////////////////////////
//////////////////// ﾎﾟｲﾝﾀｰはよくわからない(その時、理解してもすぐに忘れる) ///////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// RGBｽｸﾘｰﾝ出力(美咲ﾌｫﾝﾄ) ------------------------------------------------
void KNJ_print(char * INP_String, int x, int y, int csize, uint16_t TXT_Color) {
  int i, X1, Y1, PX, len;
  uint8_t row, col;
  char font[8];                                                // ﾌｫﾝﾄ格納buffer
  char * str = INP_String;                                     // 文字列
  PX = x;
  while(*str) {                                                // 文字列分loop
    str = getFontData(font, str);                              // 1文字分のﾌｫﾝﾄ取得
//  if (!str) {
    if (str == false) {
      break;                                                   // エラーの場合は終了
    }
    switch (csize) { // 文字の大きさでﾄﾞｯﾄを変える
    case 1:
      // Draw_Pixel(X1, Y1);// ﾄﾞｯﾄが点
      for ( row = 0 ; row < 8 ; row++ ) {                      // 行数
        for ( col = 0 ; col < 8 ; col++ ) {                    // 列数
          if ((B10000000 >> col) & font[row]) {                // 対象ﾋﾞｯﾄが[1]ならﾄﾞｯﾄを打つ
            X1 = PX + col;
            Y1 = y + row;
            DSP.drawPixel(X1, Y1, TXT_Color);
          }
        }
      }
      PX = PX + 8;
      break;
    case 2:
      // Draw_Rectangle(X1, Y1, X2, Y2);// ﾄﾞｯﾄが四角の外枠
      for ( row = 0 ; row < 8 ; row++ ) {                      // 行数
        for ( col = 0 ; col < 8 ; col++ ) {                    // 列数
          if ((B10000000 >> col) & font[row]) {                // 対象ﾋﾞｯﾄが[1]ならﾄﾞｯﾄを打つ
            X1 = PX + 2 * col;
            Y1 = y + 2 * row;
            DSP.drawRect(X1, Y1, 2, 2, TXT_Color);
          }
        }
      }
      PX = PX + 16;
      break;
    default:
      // Fill_Rectangle(X1, Y1, X2, Y2);// ﾄﾞｯﾄが四角の塗りつぶし
      for ( row = 0 ; row < 8 ; row++ ) {                     // 行数
        for ( col = 0 ; col < 8 ; col++ ) {                   // 列数
          if ((B10000000 >> col) & font[row]) {               // 対象ﾋﾞｯﾄが[1]ならﾄﾞｯﾄを打つ
            X1 = PX + csize * col;
            Y1 = y + csize * row;
            DSP.fillRect(X1, Y1, csize, csize, TXT_Color);
          }
        }
      }
      PX = PX + csize * 8;
    }
  }
}


//
