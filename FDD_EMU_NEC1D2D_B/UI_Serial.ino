// ｼﾘｱﾙ開始ﾒｯｾｰｼﾞ ------------------------------------------------
void Serial_Start_msg() {
  // ArduinoIDEのｼﾘｱﾙﾓﾆﾀやﾀｰﾐﾅﾙｿﾌﾄにﾒｯｾｰｼﾞ送信
  // 初期画面
  Serial.println();
  line_asterisk();
//Serial.println(F("********************************************************"));
  Serial.println(F("* Hardware : Arduino MEGA/MEGA 2560/MEGA ADK           *"));
  Serial.println(F("* Software : FDD Emulator [NEC 1D,2D]                  *"));
  Serial.println(F("* Create   : yana(2021/03/20) Ver0.01                  *"));
  line_asterisk();
}


// ｼﾘｱﾙFDDｴﾐｭﾚｰﾀ開始ﾒｯｾｰｼﾞ ------------------------------------------------
void Serial_EMU_start_msg() {
  Serial.println();
  Serial.println();
  line_Slash();
//Serial.println(F("////////////////////////////////////////////////////////"));
  Serial.println(F("//////////// FDD Emulator [NEC 1D,2D] start ////////////"));
  line_Slash();
  Serial.println();
  Serial.println();
}


// ｼﾘｱﾙUI処理 ------------------------------------------------
void Serial_UI_rtn() {
//Serial.println("UI_rtn();");
  EMU_start_flg = false;                                      // FDDｴﾐｭﾚｰﾀを停止
//DSP.Fill_Screen(GRAY);                                      // ﾀｯﾁｽｸﾘｰﾝ暗転
  if (EMU_practicable_flg == false) {                         // SDｶｰﾄﾞに[EMU]ﾎﾙﾀﾞｰがなければ
    Serial_SD_Init_rtn();                                     // SDｶｰﾄﾞ準備(ｼﾘｱﾙ)
  }
  while(true) {                                               // 指示確定まで繰り返す
    Serial_Function_Select();                                 // 機能選択
    
    switch (Select_No) {
    case 1:
      Drv_fd_link_load();                                     // ﾄﾞﾗｲﾌﾞ・FDｲﾒｰｼﾞ紐づけﾌｧｲﾙ読込み
      Serial_EMU_start_msg();                                 // ｼﾘｱﾙFDDｴﾐｭﾚｰﾀ開始ﾒｯｾｰｼﾞ
      Select_No = 0;                                          // 選択番号
      EMU_start_flg = true;                                   // FDDｴﾐｭﾚｰﾀを開始
      FDD_Emulator_rtn();                                     // FDDｴﾐｭﾚｰﾀ画像
      Serial_Function_print();                                // ｼﾘｱﾙ機能選択印字
      return;
    case 2:
      Serial_FD_change_rtn();                                 // ﾄﾞﾗｲﾌﾞでFDｲﾒｰｼﾞを交換
      break;
    case 3:
      Serial_FD_protect_rtn();                                // FDｲﾒｰｼﾞを書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)
      break;
    case 4:
      Serial_FD_output_rtn();                                 // FDｲﾒｰｼﾞを出力
    }
    Serial_Function_print();                                  // ｼﾘｱﾙ機能選択印字
  }
}


// ｼﾘｱﾙ機能選択印字 ------------------------------------------------
void Serial_Function_print() {
//Serial.println("Serial_Function_print();");
  line_asterisk();
//Serial.println(F("********************************************************"));
  Serial.println(F("* FDDｴﾐｭﾚｰﾀ ｾｯﾃｲ ｻｷﾞｮｳ ﾒﾆｭｰ                              *"));
  line_asterisk();
  Serial.println(F(" 1:[FDDｴﾐｭﾚｰﾀ ｷﾄﾞｳ]  FDDｴﾐｭﾚｰﾀ ｦ ｷﾄﾞｳ ｼﾏｽ｡"));
//Serial.println(F("........................................................"));
  line_period();
  Serial.println(F(" 2:[FDｲﾒｰｼﾞ ｻｼｶｴ]    FDﾄﾞﾗｲﾌﾞ ﾉ FDｲﾒｰｼﾞ ｦ ｻｼｶｴﾏｽ｡"));
  line_period();
  Serial.println(F(" 3:[ﾗｲﾄﾌﾟﾛﾃｸﾄ ﾍﾝｺｳ]  FDｲﾒｰｼﾞ ﾉ ﾗｲﾄﾌﾟﾛﾃｸﾄ ｦ ｶｹﾀﾘ ﾊｽﾞｼﾀﾘ ｼﾏｽ｡"));
  Serial.println(F("                    ( ﾃﾞﾌｫﾙﾄ ﾃﾞﾊ ﾗｲﾄﾌﾟﾛﾃｸﾄ ｶﾞ ｶｶｯﾃ ｲﾏｽ｡ )"));
  line_period();
  Serial.println(F(" 4:[FDｲﾒｰｼﾞ ｼｭﾂﾘｮｸ]  [FD_OUT]ﾌｫﾙﾀﾞｰ ﾆ ｼｭｳｾｲ ｻﾚﾀ FDｲﾒｰｼﾞ ｶﾞ"));
  Serial.println(F("                                              ｼｭﾂﾘｮｸ ｻﾚﾏｽ｡"));
  line_equal();
//Serial.println(F("========================================================"));
  Serial.println(F(" ｷﾉｳ ｦ ｾﾝﾀｸ ｼﾃｸﾀﾞｻｲ (1-4) ?"));
  Serial.println(F("( FDDｴﾐｭﾚｰﾀ ﾊ ｻｷﾞｮｳ ﾁｭｳ ｲﾁｼﾞ ﾃｲｼ ｼﾏｽ｡ )"));
  Serial.println(F("( ﾀｯﾁﾊﾟﾈﾙ ｦ ｿｳｻ ｼﾃｲﾙ ﾄﾁｭｳ ﾊ Serial ｶﾞﾜ ﾊ ﾂｶｴﾏｾﾝ｡ )"));
}


// ｼﾘｱﾙ機能選択 ------------------------------------------------
void Serial_Function_Select() {
//Serial.println("Serial_Function_Select();");
  while(true){
    UI_3_digits();                                            // 改行記号までの文字列をため3桁数値にする

    if ((Select_No >= 1) && (Select_No <= 4)) {
      break;
    }
  }
}


// ﾄﾞﾗｲﾌﾞでFDｲﾒｰｼﾞを交換 ------------------------------------------------
void Serial_FD_change_rtn() {
//Serial.println("Serial_FD_set_rtn();");
  int cnt, Plus_No;                                           // ｶｳﾝﾀｰ
  line_Slash();
//Serial.println(F("////////////////////////////////////////////////////////"));
  Serial.println(F("/// [FDｲﾒｰｼﾞ ｻｼｶｴ] //////////////////////////////////////"));
  line_Slash();

  File_TBL_create();                                          // [FD_IN]ﾌｫﾙﾀﾞｰのﾌｧｲﾙﾘｽﾄ作成
//Serial.print(F("File_count : "));Serial.println(File_count);  // debug
  Insert_File_TBL(DUMMY_Name, File_count);                    // File_TBL[]に文字列を挿入する
  while(true) {                                               // 変更するﾄﾞﾗｲﾌﾞの数だけ繰り返す
    while(true) {                                             // ﾄﾞﾗｲﾌﾞの指定
      S_line_asterisk();
//    Serial.println(F("********************************"));
      Serial.println(F("* FDﾄﾞﾗｲﾌﾞ ﾆ ｾｯﾄ ｻﾚﾀ FDｲﾒｰｼﾞ     *"));
      S_line_asterisk();
      Drv_fd_link_load();                                     // ﾄﾞﾗｲﾌﾞ・FDｲﾒｰｼﾞ紐づけﾌｧｲﾙ読込み
      for ( cnt = 0 ; cnt <= 3 ; cnt++ ) {
        // ﾄﾞﾗｲﾌﾞごとのFDｲﾒｰｼﾞﾌｧｲﾙ名
        Serial.print(F(" ﾄﾞﾗｲﾌﾞ"));
        Plus_No = cnt + 1;
        Serial.print(Plus_No, DEC);
        Serial.print(F(" : "));
        Insert_File_Name(Drv_FD_Name[cnt]);                   // ﾌｧｲﾙ名
        Serial.print(File_Name);                              // ﾌｧｲﾙ名
        Space_print(File_Name);                               // 空白で文字列の長さを揃える
        FD_info_TBL_NM_read(File_Name);                       // FDｲﾒｰｼﾞﾌｧｲﾙ情報ﾃｰﾌﾞﾙ読込み(名前検索)
        if (FD_protect == 1) {
          Serial.print(F("[ﾗｲﾄﾌﾟﾛﾃｸﾄ]"));
        } else {
          Serial.print(F("           "));
        }
        if (FD_update == 1) {                         // 更新区分(0:なし, 1:あり)
          Serial.print(F("[ｺｳｼﾝ ｱﾘ]"));
        } else {
          Serial.print(F("         "));
        }
        Serial.println();
      }
      line_equal();
      Serial.println(F(" ﾍﾝｺｳ ｽﾙ FDﾄﾞﾗｲﾌﾞNo. ｦ ｼﾃｲ ｼﾃｸﾀﾞｻｲ (1-4, 9:ｵﾜﾘ) ?"));
      Serial.println(F("( [********.***] ﾊ ﾄﾞﾗｲﾌﾞ ﾆ FD ｶﾞ ﾊｲｯﾃ ｲﾏｾﾝ｡ )"));

      UI_3_digits();                                          // 改行記号までの文字列をため3桁数値にする

      if ((Select_No >= 1) && (Select_No <= 4)) {
        break;
      }
      if (Select_No == 9) {
        return;
      }
    }
    Drive_cnt = Select_No - 1;
    while(true) {                                             // FDｲﾒｰｼﾞの指定
      line_minus();
//  Serial.println(F("--------------------------------------------------------"));
      Serial.print(F(" ﾄﾞﾗｲﾌﾞ"));
      Plus_No = Drive_cnt + 1;
      Serial.print(Plus_No ,DEC);
      Serial.println(F(" ( ｾｯﾄ ﾉ ｾｯﾃｲ ｦ ﾍﾝｺｳ ｼﾏｽ｡ )"));
      line_minus();
      line_asterisk();
//    Serial.println(F("********************************************************"));
      Serial.println(F("*   FDｲﾒｰｼﾞﾌｧｲﾙ ｲﾁﾗﾝ                                     *"));
      line_asterisk();
      for ( cnt = 0 ; cnt <= File_count ; cnt++ ) {
//      File_Name = File_TBL[cnt];                            // ﾌｧｲﾙ名
        Insert_File_Name(File_TBL[cnt]);                      // ﾌｧｲﾙ名
        if (cnt < 10) {
          Serial.print(' ');
        }
        if (cnt < 100) {
          Serial.print(' ');
        }
        Serial.print(cnt, DEC); 
        Serial.print(": ");
        Serial.print(File_Name);
        Space_print(File_Name);                               // 空白で文字列の長さを揃える
        FD_info_TBL_read(cnt);                                // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
//      FD_link_drv(File_Name);                               // FDｲﾒｰｼﾞﾌｧｲﾙに紐づけされたﾄﾞﾗｲﾌﾞ番号
        FD_link_drv();                                        // FDｲﾒｰｼﾞﾌｧｲﾙに紐づけされたﾄﾞﾗｲﾌﾞ番号
        if ((FD_drv_No != 9) && (cnt < File_count)) {         // ﾄﾞﾗｲﾌﾞ番号(9:対象外)
          Serial.print(F(" ( ﾄﾞﾗｲﾌﾞ"));
          Plus_No = FD_drv_No + 1;
          Serial.print(Plus_No);
          Serial.print(F(" )"));
        }
        if ((FD_format == 9) && (File_Name[0] != '*')) {      // ﾌｫｰﾏｯﾄ区分(9:対象外)
          Serial.print(F(" <- NG(ﾌｧｲﾙｻｲｽﾞ ｶﾞ ﾁｶﾞｳ ﾀﾒ ﾂｶｴﾏｾﾝ)"));
        }
        Serial.println();
        if ( ( cnt + 1 ) % 5 == 0 ) {
          line_minus_space();
//Serial.println(F("- - - - - - - - - - - - - - - - - - - - - - - - - - - - "));
        }
      }
      cnt--;
      line_equal();
      Serial.print(F("ﾌｧｲﾙ ﾊﾞﾝｺﾞｳ ｦ ｾﾝﾀｸ ｼﾃｲ ｼﾃｸﾀﾞｻｲ (0-"));
      Serial.print(cnt, DEC);
      Serial.println(F(", 99:ｵﾜﾘ) ?"));
      Serial.println(F("( [********.***] ｦ ｴﾗﾌﾞﾄ ﾄﾞﾗｲﾌﾞ ｶﾗ FDｲﾒｰｼﾞ ｦ ﾊｽﾞｼﾏｽ｡ )"));

      UI_3_digits();                                          // 改行記号までの文字列をため3桁数値にする

      if (Select_No == 99) {
        break;
      }
      if ((Select_No >= 0) && (Select_No <= File_count)) {

        Insert_File_Name(File_TBL[Select_No]);                // ﾌｧｲﾙ名

        if (File_Name[0] != '*') {                            // "********.***"以外ﾁｪｯｸ
//        FD_info_read(File_Name);                            // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
          FD_info_read();                                     // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
          FD_info_TBL_read(Select_No);                        // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
          if (FD_format == 9) {                               // ﾌｫｰﾏｯﾄ区分(9:対象外)
            line_sharp();
//          Serial.println(F("########################################################"));
            Serial.println(F("######  ｺﾉ FDｲﾒｰｼﾞ ﾊ ﾌｧｲﾙｻｲｽﾞ ｶﾞ ﾁｶﾞｳ ﾀﾒ ﾂｶｴﾏｾﾝ !!   ######"));
            Serial.println(F("######  ﾄﾞﾗｲﾌﾞ ﾆ ｾｯﾄ ｻﾚﾏｾﾝﾃﾞｼﾀ !!                   ######"));
            line_sharp();
            break;
          }
        }
//      Drv_fd_link_crt(File_Name, Drive_cnt);                // ﾄﾞﾗｲﾌﾞにFDｲﾒｰｼﾞ紐づけﾌｧｲﾙ作成
        Drv_fd_link_crt();                                    // ﾄﾞﾗｲﾌﾞにFDｲﾒｰｼﾞ紐づけﾌｧｲﾙ作成
        line_minus();
//    Serial.println(F("--------------------------------------------------------"));
        Serial.print(F(" ﾄﾞﾗｲﾌﾞ"));
        Plus_No = Drive_No + 1;
        Serial.print(Plus_No ,DEC);
        Serial.println(F(" ( ﾄﾞﾗｲﾌﾞ ﾆ ｾｯﾄ ｻﾚﾏｼﾀ｡ )"));
        line_minus();
        break;
      }
    }
  }
}


// FDｲﾒｰｼﾞを書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ) ------------------------------------------------
void Serial_FD_protect_rtn() {
//Serial.println("Serial_FD_protect_rtn();");
  int cnt, Plus_No;                                           // ｶｳﾝﾀｰ
  line_Slash();
//Serial.println(F("////////////////////////////////////////////////////////"));
  Serial.println(F("/// [ﾗｲﾄﾌﾟﾛﾃｸﾄ ﾍﾝｺｳ] ////////////////////////////////////"));
  line_Slash();
// FDｲﾒｰｼﾞの一覧表示(書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ),紐づけﾄﾞﾗｲﾌﾞ番号が分かるように)
  File_TBL_create();                                          // SDｶｰﾄﾞのﾌｧｲﾙﾘｽﾄ作成

  while(true) {
    line_asterisk();
//  Serial.println(F("********************************************************"));
    Serial.println(F("*   FDｲﾒｰｼﾞﾌｧｲﾙ ｲﾁﾗﾝ                                     *"));
    line_asterisk();
    for ( cnt = 0 ; cnt < File_count ; cnt++ ) {
      Insert_File_Name(File_TBL[cnt]);                        // ﾌｧｲﾙ名
      if (cnt < 10) {
        Serial.print(' ');
      }
      if (cnt < 100) {
        Serial.print(' ');
      }
      Serial.print(cnt, DEC); 
      Serial.print(F(": "));
      Serial.print(File_Name);
      Space_print(File_Name);                                 // 空白で文字列の長さを揃える
      FD_info_TBL_read(cnt);                                  // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
//    FD_link_drv(File_Name);                                 // FDｲﾒｰｼﾞﾌｧｲﾙに紐づけされたﾄﾞﾗｲﾌﾞ番号
      FD_link_drv();                                          // FDｲﾒｰｼﾞﾌｧｲﾙに紐づけされたﾄﾞﾗｲﾌﾞ番号
      if (FD_protect == 1) {
        Serial.print(F("[ﾗｲﾄﾌﾟﾛﾃｸﾄ]"));
      } else {
        Serial.print(F("           "));
      }
      if ((FD_format == 9) && (File_Name[0] != '*')) {        // ﾌｫｰﾏｯﾄ区分(9:対象外)
        Serial.print(F(" <- NG"));
      }
      if (FD_drv_No != 9) {                                   // ﾄﾞﾗｲﾌﾞ番号(9:対象外)
        Serial.print(F(" ﾄﾞﾗｲﾌﾞ"));
        Plus_No = FD_drv_No + 1;
        Serial.print(Plus_No, DEC);
      }
      Serial.println();
      if ( ( cnt + 1 ) % 5 == 0 ) {
        line_minus_space();
//Serial.println(F("- - - - - - - - - - - - - - - - - - - - - - - - - - - - "));
      }
    }
    // FDｲﾒｰｼﾞの指定
    cnt--;
    line_equal();
    Serial.print(F("ﾌｧｲﾙ ﾊﾞﾝｺﾞｳ ｦ ｾﾝﾀｸ ｼﾃｲ ｼﾃｸﾀﾞｻｲ (0-"));
    Serial.print(cnt, DEC);
    Serial.println(F(", 99:ｵﾜﾘ) ?"));
      
    UI_3_digits();                                            // 改行記号までの文字列をため3桁数値にする

    if (Select_No == 99) {
      break;
    }
    if ((Select_No >= 0) && (Select_No < File_count)) {
      Insert_File_Name(File_TBL[Select_No]);                  // ﾌｧｲﾙ名
      FD_info_TBL_read(Select_No);                            // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
      line_equal();
      Serial.println(F("ﾗｲﾄﾌﾟﾛﾃｸﾄ ﾉ ｾｯﾃｲ ｦ ﾍﾝｺｳ ｼﾏｽｶ ? ( 1: Yes , 0: No )"));
      Judgment_of_Yes ();                                     // Yes判定
      if (Yes_No == 0) {
        return;
      }
      if (Yes_No == 1) {
        if (FD_protect == 0) {                                // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし, 1:あり)
          // FDｲﾒｰｼﾞﾌｧｲﾙ情報を更新(ｲﾒｰｼﾞﾌｧｲﾙ名, 書込み保護, 更新区分, 出力区分)
//        FD_info_rewrite(File_Name, 1, 9, 9);                // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(1:あり)
          FD_info_rewrite(1, 9, 9);                           // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(1:あり)
          FD_info_TBL_rewrite(FD_No, 1, 9, 9);                // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(1:あり)
        } else if (FD_protect == 1) {
          // FDｲﾒｰｼﾞﾌｧｲﾙ情報を更新(ｲﾒｰｼﾞﾌｧｲﾙ名, 書込み保護, 更新区分, 出力区分)
//        FD_info_rewrite(File_Name, 0, 9, 9);                // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし)
          FD_info_rewrite(0, 9, 9);                           // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし)
          FD_info_TBL_rewrite(FD_No, 0, 9, 9);                // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし)
        }
      }
    }
  }
}


// FDｲﾒｰｼﾞを出力 ------------------------------------------------
void Serial_FD_output_rtn() {
//Serial.println("Serial_FD_eject_rtn();");
  int cnt, Plus_No;                                           // ｶｳﾝﾀｰ
  line_Slash();
//Serial.println(F("////////////////////////////////////////////////////////"));
  Serial.println(F("/// [FDｲﾒｰｼﾞ ｼｭﾂﾘｮｸ] ////////////////////////////////////"));
  line_Slash();

  // FDｲﾒｰｼﾞの一覧表示(更新あり、出力済、紐づけﾄﾞﾗｲﾌﾞ番号が分かるように)
  File_TBL_create();                                          // SDｶｰﾄﾞのﾌｧｲﾙﾘｽﾄ作成

  while(true) {
    line_asterisk();
//  Serial.println(F("********************************************************"));
    Serial.println(F("*   FDｲﾒｰｼﾞﾌｧｲﾙ ｲﾁﾗﾝ                                     *"));
    line_asterisk();
    for ( cnt = 0 ; cnt < File_count ; cnt++ ) {
      Insert_File_Name(File_TBL[cnt]);                        // ﾌｧｲﾙ名
      if (cnt < 10) {
        Serial.print(' ');
      }
      if (cnt < 100) {
        Serial.print(' ');
      }
      Serial.print(cnt, DEC); 
      Serial.print(F(": "));
      Serial.print(File_Name);
      Space_print(File_Name);                                 // 空白で文字列の長さを揃える
      FD_info_TBL_read(cnt);                                  // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
//    FD_link_drv(File_Name);                                 // FDｲﾒｰｼﾞﾌｧｲﾙに紐づけされたﾄﾞﾗｲﾌﾞ番号
      FD_link_drv();                                          // FDｲﾒｰｼﾞﾌｧｲﾙに紐づけされたﾄﾞﾗｲﾌﾞ番号
      if (FD_update == 1) {                                   // 更新区分(0:なし, 1:あり)
        Serial.print(F("[ｺｳｼﾝ ｱﾘ]"));
      } else {
        Serial.print(F("         "));
      }
      if (FD_output == 1) {                                   // 出力区分(0:なし, 1:あり)
        Serial.print(F(" [Outputｽﾞﾐ]"));
      } else {
        Serial.print(F("            "));
      }
      if ((FD_format == 9) && (File_Name[0] != '*')) {        // ﾌｫｰﾏｯﾄ区分(9:対象外)
        Serial.print(F(" <- NG"));
      }
      if (FD_drv_No != 9) {                                   // ﾄﾞﾗｲﾌﾞ番号(9:対象外)
        Serial.print(F(" ﾄﾞﾗｲﾌﾞ"));
        Plus_No = FD_drv_No + 1;
        Serial.print(Plus_No, DEC);
      }
      Serial.println();
      if ( ( cnt + 1 ) % 5 == 0 ) {
        line_minus_space();
//Serial.println(F("- - - - - - - - - - - - - - - - - - - - - - - - - - - - "));
      }
    }
// FDｲﾒｰｼﾞの指定
    cnt--;
    line_equal();
    Serial.print(F("ﾌｧｲﾙ ﾊﾞﾝｺﾞｳ ｦ ｾﾝﾀｸ ｼﾃｲ ｼﾃｸﾀﾞｻｲ (0-"));
    Serial.print(cnt, DEC);
    Serial.println(F(", 99:ｵﾜﾘ) ?"));
      
    UI_3_digits();                                            // 改行記号までの文字列をため3桁数値にする

    if (Select_No == 99) {
      break;
    }
    if ((Select_No >= 0) && (Select_No < File_count)) {
      Insert_File_Name(File_TBL[Select_No]);                  // ﾌｧｲﾙ名
      FD_info_TBL_read(Select_No);                            // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
      S_line_minus();
//    Serial.println(F("--------------------------------"));
      Serial.println(F(" *** FDｲﾒｰｼﾞ ｼｭﾂﾘｮｸ ｼｮﾘ ｶｲｼ ***"));
      Serial.println(F(" ( ｼｮﾘ ﾆ 2D ﾃﾞ ﾔｸ 30 ﾋﾞｮｳ ｶｶﾘﾏｽ｡ )"));
      S_line_minus();
      // 出力処理
      Serial.println(F("(ｶﾝﾘｮｳ ｼﾀ ﾄﾗｯｸ ﾉ ｼﾞｮｳｷｮｳ)"));
      Serial.println(F("***20***40***60***80"));
      // ﾌｫｰﾏｯﾄ区分(1:d88(1D 35ﾄﾗｯｸ), 2:d88(1D 40ﾄﾗｯｸ), 3:d88(2D), 4:予備)
      if ((FD_format >= 1) && (FD_format <= 4)) {
//      D88_write_rtn(File_Name, FD_format);
        D88_write_rtn(FD_format);
      }
      // ﾌｫｰﾏｯﾄ区分(5:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 35ﾄﾗｯｸ), 6:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 40ﾄﾗｯｸ), 7:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(2D), 8:予備)
      if ((FD_format >= 5) && (FD_format <= 8)) {
//      Plane_img_write_rtn(File_Name, FD_format);
        Plane_img_write_rtn(FD_format);
      }
      Insert_File_Name(File_TBL[Select_No]);                  // ﾌｧｲﾙ名
//    FD_info_rewrite(File_Name, 9, 0, 1);                    // FDｲﾒｰｼﾞﾌｧｲﾙ情報を更新
      FD_info_rewrite(9, 0, 1);                               // FDｲﾒｰｼﾞﾌｧｲﾙ情報を更新
      Serial.println();
      S_line_minus();
//    Serial.println(F("--------------------------------"));
      Serial.println(F(" *** FDｲﾒｰｼﾞ ｼｭﾂﾘｮｸ ｼｮﾘ ｼｭｳﾘｮｳ ***"));
      S_line_minus();
    }
  }
}


// SDｶｰﾄﾞ準備ﾒｯｾｰｼﾞ(ｼﾘｱﾙ) ------------------------------------------------
void Serial_SD_Init_msg() {
//Serial.println("Initialize_SD_msg();");
  line_Slash();
//Serial.println(F("////////////////////////////////////////////////////////"));
  Serial.println(F("/// [SDｶｰﾄﾞ ｼﾞｭﾝﾋﾞ] /////////////////////////////////////"));
  line_Slash();

  // rootのﾌｧｲﾙとﾃﾞｨﾚｸﾄﾘを全て表示
  Serial_root_Path_List();                                    // rootのﾃﾞｨﾚｸﾄﾘとﾌｧｲﾙを表示(ｼﾘｱﾙ版)

  // 実行確認
  line_equal();
  Serial.println(F("FDDｴﾐｭﾚｰﾀ ｶﾞ ﾂｶｴﾙ ﾖｳﾆ ｼﾞｭﾝﾋﾞ ﾉ ｼｮﾘ ｦ ｼﾃ ｲｲﾃﾞｽｶ ?"));
  Serial.println(F("                            (Yes:1, No:Enter)"));
}


// SDｶｰﾄﾞ準備(ｼﾘｱﾙ) ------------------------------------------------
void Serial_SD_Init_rtn() {
//Serial.println("Initialize_SD_rtn();");
  // ﾌｧｲﾙとﾃﾞｨﾚｸﾄﾘを全て表示
  // 実行確認
  // ﾃﾞｨﾚｸﾄﾘとﾌｧｲﾙを全て削除
  // ﾃﾞｨﾚｸﾄﾘを作成
  //// ｾｸﾀ(256KB)を80×16個に分けたﾌｧｲﾙを入れるﾃﾞｨﾚｸﾄﾘを作成
  //// (ﾃﾞｨﾚｸﾄﾘの階層 : /EMU/FD/FDｲﾒｰｼﾞﾌｧｲﾙ名/Tnn_Snn.HEX)
  //// FDｲﾒｰｼﾞを入れるﾃﾞｨﾚｸﾄﾘを作成(ﾃﾞｨﾚｸﾄﾘ : /FD_IN , /FD_OUT)
  // ﾄﾞﾗｲﾌﾞにFDｲﾒｰｼﾞ紐づけﾌｧｲﾙ作成(ﾃﾞｨﾚｸﾄﾘ : /EMU/CONFIG/DRV_FD.USE)
  // /EMU/CONFIG/DRV_n_FD.USE <- ﾄﾞﾗｲﾌﾞn(0-3)はどのFDｲﾒｰｼﾞﾌｧｲﾙを使うのか
  // /EMU/CONFIG/FD/FDｲﾒｰｼﾞﾌｧｲﾙ名 <- 0: ﾌｫｰﾏｯﾄ, 1: 更新区分, 2: 出力区分, 3: ﾄﾞﾗｲﾌﾞ番号

  Judgment_of_Yes();                                          // Yes判定
  if (Yes_No == true) {
    S_line_minus();
//  Serial.println(F("--------------------------------"));
    Serial.println(F(" *** ﾌｫﾙﾀﾞｰ(ﾌｧｲﾙ) ｻｸｾｲ ｶｲｼ ***"));
    Serial.println(F(" ( ｼｮﾘ ﾆ 30 ﾋﾞｮｳ ｶｶﾘﾏｽ｡ )"));
    S_line_minus();
  } else {
    line_sharp();
//  Serial.println(F("########################################################"));
    Serial.println(F("# SDｶｰﾄﾞ ｦ ﾏﾁｶﾞｴﾀ ﾊﾞｱｲ､                                 #"));
    Serial.println(F("#       arduino MEGA ﾉ ﾃﾞﾝｹﾞﾝ ｦ ｷﾘ､SDｶｰﾄﾞ ｦ ｲﾚｶｴﾃｸﾀﾞｻｲ｡  #"));
    line_sharp();
    return;
  }
  Directory_making_rtn();                                     // ﾃﾞｨﾚｸﾄﾘを作成

  Drv_fd_link_use_bundle();                                   // ﾄﾞﾗｲﾌﾞにFDｲﾒｰｼﾞ紐づけﾌｧｲﾙ作成(一括)

  WORK0000_IMG_create(5);                                     // /FD_IN/WK1D0000.IMGを作成
  WORK0000_IMG_create(7);                                     // /FD_IN/WK2D0000.IMGを作成

  readme_txt_create();                                        // readme.txt作成

  S_line_minus();
//Serial.println(F("--------------------------------"));
  Serial.println(F(" *** ﾌｫﾙﾀﾞｰ(ﾌｧｲﾙ) ｻｸｾｲ ｼｭｳﾘｮｳ ***"));
  S_line_minus();
  // ﾌｧｲﾙとﾃﾞｨﾚｸﾄﾘを全て表示
  Serial_root_Path_List();                                    // ﾊﾟｽ内のﾃﾞｨﾚｸﾄﾘとﾌｧｲﾙを表示(ｼﾘｱﾙ)

  line_asterisk();
//Serial.println(F("********************************************************"));
  Serial.println(F("*  arduino MEGA ﾉ ﾃﾞﾝｹﾞﾝ ｦ ｷﾘ SDｶｰﾄﾞ ｦ ﾄﾘﾀﾞｼﾃｸﾀﾞｻｲ｡       *"));
  line_asterisk();
  Serial.println(F(" SDｶｰﾄﾞ ﾉ ﾅｶﾆ [FD_IN],[FD_OUT],[EMU] ﾄ ﾌｫﾙﾀﾞｰ ｶﾞ ｱﾘﾏｽ｡"));
  line_period();
//Serial.println(F("........................................................"));
  Serial.println(F(" [FD_IN]ﾌｫﾙﾀﾞｰ ﾆ ﾂｶｲﾀｲ FDｲﾒｰｼﾞﾌｧｲﾙ ｦ ｲﾚﾏｽ｡(MAX:64)"));
  line_period();
  Serial.println(F(" [FD_OUT]ﾌｫﾙﾀﾞｰ ﾊ ｼｭｳｾｲ ｼﾀ FDｲﾒｰｼﾞﾌｧｲﾙ ｦ ﾄﾘﾀﾞｽﾉﾆ ﾂｶｲﾏｽ｡"));
  line_period();
  Serial.println(F(" [EMU]ﾌｫﾙﾀﾞｰ ﾆﾊ ｼｽﾃﾑ ﾆ ﾋﾂﾖｳ ﾅ ﾌｧｲﾙ ｶﾞ ﾊｲｯﾃ ｲﾏｽ｡"));
  line_period();
  Serial.println(F(" ﾂｶｴﾙ FDｲﾒｰｼﾞﾌｧｲﾙ ﾊ (1D 35ﾄﾗｯｸ)(1D 40ﾄﾗｯｸ)(2D 80ﾄﾗｯｸ) ﾃﾞｽ｡"));
  Serial.println(F(" ｶｸﾁｮｳｼ[D88] ﾄ､ﾌﾟﾚｰﾝｲﾒｰｼﾞ(ｶｸﾁｮｳｼ[DSK][IMG]ﾅﾄﾞ) ﾃﾞｽ｡"));
  line_period();
  Serial.println(F(" ﾌｧｲﾙ ﾒｲ ﾊ 8+3(8ﾓｼﾞ + '.' + ｶｸﾁｮｳｼ([D88][DSK][IMG]ﾅﾄﾞ))ﾃﾞｽ｡"));
  line_asterisk();
  Serial.println(F(" ｸﾜｼｸ ﾊ SDｶｰﾄﾞ ﾉ ﾅｶﾉ README.TXT ｦ ｵﾖﾐ ｸﾀﾞｻｲ｡"));
  line_asterisk();
  Serial.println();
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("##################### ｼｽﾃﾑ ﾃｲｼ ｼﾏｼﾀ #####################"));
  line_sharp();
  Waiting_for_reset();                                        // 処理中止
}


// Yes判定 ------------------------------------------------
void Judgment_of_Yes() {
//Serial.println("Judgment_of_Yes();");

  Yes_No = 0;
  char Str_Num[5];
  Str_Num[0] = ' ';Str_Num[1] = ' ';Str_Num[2] = ' ';Str_Num[3] = ' ';

  for ( int i = 0 ; i < 2 ; i++ ) {                           // max:2文字ためる
    while(Serial.available() == 0) {
      delay(50);// 0.05秒待つ
    }
    Str_Num[i] = Serial.read();
    Serial.write(Str_Num[i]);
    if ((Str_Num[i] == LF) || (Str_Num[i] == CR)) {
      break;
    }
  }
  String_trim(Str_Num);                                       // 文字列のｽﾍﾟｰｽを取って文字配列にｺﾋﾟｰする
  Str_DEC_conversion(Copy_Str);                               // 文字列を数値(10進数)に変換する
  Yes_No = Str_DEC;
  while(Serial.available() > 0) {
    char Not_needed = Serial.read();
    Serial.write(Not_needed);
  }
  Serial.println();
}


// 改行記号までの文字列をため3桁数値にする ------------------------------------------------
void UI_3_digits() {
//Serial.println("UI_3_digits();");

  Select_No = 0;                                              // 選択番号
  char Str_Num[5];
  Str_Num[0] = ' ';Str_Num[1] = ' ';Str_Num[2] = ' ';Str_Num[3] = ' ';

  for ( int i = 0 ; i < 2 ; i++ ) {                           // max:2文字ためる
    while(Serial.available() == 0) {
      delay(50);// 0.05秒待つ
    }
    Str_Num[i] = Serial.read();
    Serial.write(Str_Num[i]);
    if ((Str_Num[i] == LF) || (Str_Num[i] == CR)) {
      break;
    }
  }
  String_trim(Str_Num);                                       // 文字列のｽﾍﾟｰｽを取って文字配列にｺﾋﾟｰする
  Str_DEC_conversion(Copy_Str);                               // 文字列を数値(10進数)に変換する
  Select_No = Str_DEC;
  while(Serial.available() > 0) {
    char Not_needed = Serial.read();
    Serial.write(Not_needed);
  }
  Serial.println();
}


// 空白で文字列の長さを揃える ------------------------------------------------
void Space_print(char * _Name) {

  String_length(_Name);                                       // 文字列の長さを求める

  for (int i = 12 ; i > Str_length ; i--) {
    Serial.print(' ');
  }
}


// 線 ------------------------------------------------
void line_minus() {
  Serial.println(F("--------------------------------------------------------"));
}


// 線 ------------------------------------------------
void line_minus_space() {
  Serial.println(F("- - - - - - - - - - - - - - - - - - - - - - - - - - - - "));
}


// 線 ------------------------------------------------
void line_equal() {
  Serial.println(F("========================================================"));
}


// 線 ------------------------------------------------
void line_period() {
  Serial.println(F("........................................................"));
}


// 線 ------------------------------------------------
void line_Slash() {
  Serial.println(F("////////////////////////////////////////////////////////"));
}


// 線 ------------------------------------------------
void line_asterisk() {
  Serial.println(F("********************************************************"));
}


// 線 ------------------------------------------------
void line_sharp() {
  Serial.println(F("########################################################"));
}


// 短い線 ------------------------------------------------
void S_line_minus() {
  Serial.println(F("--------------------------------"));
}


// 短い線 ------------------------------------------------
void S_line_minus_space() {
  Serial.println(F("- - - - - - - - - - - - - - - - "));
}


// 短い線 ------------------------------------------------
void S_line_equal() {
  Serial.println(F("================================"));
}


// 短い線 ------------------------------------------------
void S_line_period() {
  Serial.println(F("................................"));
}


// 短い線 ------------------------------------------------
void S_line_Slash() {
  Serial.println(F("////////////////////////////////"));
}


// 短い線 ------------------------------------------------
void S_line_asterisk() {
  Serial.println(F("********************************"));
}


// 短い線 ------------------------------------------------
void S_line_sharp() {
  Serial.println(F("################################"));
}


//
