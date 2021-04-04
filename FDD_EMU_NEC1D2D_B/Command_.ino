// ｲﾆｼｬﾗｲｽﾞ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command00_rtn() {
//Serial.println("Command00_rtn();");

    // 何もしない

  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ﾗｲﾄﾃﾞｨｽｸ・ｺﾏﾝﾄﾞ開始 ---------------------------------------------
// Sector_qt;                                                 // ｾｸﾀの数量(Sector quantity)
// Drive_No;                                                  // ﾄﾞﾗｲﾌﾞ番号
// Track_No;                                                  // ﾄﾗｯｸ番号
// Sector_No;                                                 // ｾｸﾀ番号
void Command01_start() {
//Serial.println("Command01_rtn();");
// 受信ﾃﾞｰﾀを読み書ﾊﾞｯﾌｧｰに格納し、受信が終わったら、SDｶｰﾄﾞのFDｲﾒｰｼﾞに書込む
// RW_Buffer[0][256];                                         // 読み書ﾊﾞｯﾌｧｰ

  Rcv_data_flg = true;                                        // true : PCから後続ﾃﾞｰﾀあり
  Comm_sts = 3;                                               // 3:ﾃﾞｰﾀｾｯﾄ
  Drive_cnt = Drive_No;                                       // 0-3
  Track_cnt = Track_No;                                       // 0-79
  Insert_File_Name(Drv_FD_Name[Drive_cnt]);                   // ﾌｧｲﾙ名

  if ((VM_Drive != Drive_cnt) || (VM_Track != Track_cnt)) {
//  Track_file_write(File_Name, Track_cnt);                   // ﾄﾗｯｸﾌｧｲﾙ書込み
    Track_file_write();                                       // ﾄﾗｯｸﾌｧｲﾙ書込み
  }
  Sector_cnt = Sector_No;                                     // 1-16
  RW_Sector_cnt = 0;                                          // 読み書きｾｸﾀ処理件数
  Byte_cnt = 0;                                               // ｾｸﾀ内の何ﾊﾞｲﾄ目(0-255)を処理しているのか
}


// ﾗｲﾄﾃﾞｨｽｸ・ｺﾏﾝﾄﾞ ---------------------------------------------
// Sector_qt;                                                 // ｾｸﾀの数量(Sector quantity)
// Drive_No;                                                  // ﾄﾞﾗｲﾌﾞ番号
// Track_No;                                                  // ﾄﾗｯｸ番号
// Sector_No;                                                 // ｾｸﾀ番号
void Command01_rtn() {
//Serial.println("Command01_rtn();");
// 受信ﾃﾞｰﾀを読み書ﾊﾞｯﾌｧｰに格納し、受信が終わったら、SDｶｰﾄﾞのFDｲﾒｰｼﾞに書込む
// RW_Buffer[0][256];                                         // 読み書ﾊﾞｯﾌｧｰ

  RW_Buffer[0][Byte_cnt] = Rcv_data;
  Byte_cnt++;                                                 // ｾｸﾀ内の何ﾊﾞｲﾄ目(0-255)を処理しているのか

  if (Byte_cnt == 0) {
//Serial.print(F("Drive_cnt = "));Serial.print(Drive_cnt);      // debug
//Serial.print(F(", Track_cnt = "));Serial.print(Track_cnt);    // debug
//Serial.print(F(", Sector_cnt = "));Serial.println(Sector_cnt);// debug
//  SD_card_write(Sector_cnt);                                // SDｶｰﾄﾞ書込み
    SD_card_write();                                          // SDｶｰﾄﾞ書込み
    Sector_cnt++;                                             // 何番のｾｸﾀを処理しているのか
    RW_Sector_cnt++;                                          // 読み書きｾｸﾀ処理件数
    if (RW_Sector_cnt == Sector_qt) {
      // FDｲﾒｰｼﾞﾌｧｲﾙ情報を更新(ｲﾒｰｼﾞﾌｧｲﾙ名, 書込み保護, 更新区分, 出力区分)、
//    FD_info_rewrite(File_Name, 9, 1, 0);                    // 9:変更しない
      FD_info_rewrite(9, 1, 0);                               // 9:変更しない

      Rcv_data_flg = false;                                   // true : PCから後続ﾃﾞｰﾀあり
      Result_status = B10000000;                              // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
      Comm_sts = 9;                                           // ｺﾏﾝﾄﾞ終了
    }
  }
}


// ﾘｰﾄﾞﾃﾞｨｽｸ・ｺﾏﾝﾄﾞ ---------------------------------------------
// Sector_qt;                                                 // ｾｸﾀの数量(Sector quantity)
// Drive_No;                                                  // ﾄﾞﾗｲﾌﾞ番号
// Track_No;                                                  // ﾄﾗｯｸ番号
// Sector_No;                                                 // ｾｸﾀ番号
void Command02_rtn() {
//Serial.println("Command02_rtn();");
// SDｶｰﾄﾞのFDｲﾒｰｼﾞから読み書ﾊﾞｯﾌｧｰに入れ、送信できるようにする
// RW_Buffer[0][256];                                         // 読み書ﾊﾞｯﾌｧｰ

  Drive_cnt = Drive_No;                                       // 0-3
  Track_cnt = Track_No;                                       // 0-79
  Sector_cnt = Sector_No;                                     // 1-16
//Drv_fd_link_load();                                         // ﾄﾞﾗｲﾌﾞ・FDｲﾒｰｼﾞ紐づけﾌｧｲﾙ読込み
  if (Drv_FD_Name[Drive_cnt][0] == '*') {                     // ﾄﾞﾗｲﾌﾞにFDｲﾒｰｼﾞなし
    // Bit7 : I/O動作終了ﾌﾗｸﾞ
    // Bit6 : 1=ﾘｰﾄﾞﾊﾞｯﾌｧにﾃﾞｰﾀ有り、0=ﾘｰﾄﾞﾊﾞｯﾌｧにﾃﾞｰﾀ無し
    // Bit0 : 1=ｴﾗｰ有り、0=ｴﾗｰ無し
    Result_status = B10000000;                                // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
    Comm_sts = 9;                                             // ｺﾏﾝﾄﾞ終了
    return;
  }
  // Bit7 : I/O動作終了ﾌﾗｸﾞ
  // Bit6 : 1=ﾘｰﾄﾞﾊﾞｯﾌｧにﾃﾞｰﾀ有り、0=ﾘｰﾄﾞﾊﾞｯﾌｧにﾃﾞｰﾀ無し
  // Bit0 : 1=ｴﾗｰ有り、0=ｴﾗｰ無し
  Result_status = B00000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Snd_data_Buffer = Result_status;
  PORTC = Snd_data_Buffer;                                    // ﾃﾞｰﾀ送信(PC7～PC0)

  Insert_File_Name(Drv_FD_Name[Drive_cnt]);                   // ﾌｧｲﾙ名
//SD_card_read(File_Name, Track_cnt, Sector_cnt, TBL_cnt);    // SDｶｰﾄﾞ読込み
  SD_card_read(0);                                            // RW_Buffer[0]にｾｯﾄする

  // Bit7 : I/O動作終了ﾌﾗｸﾞ
  // Bit6 : 1=ﾘｰﾄﾞﾊﾞｯﾌｧにﾃﾞｰﾀ有り、0=ﾘｰﾄﾞﾊﾞｯﾌｧにﾃﾞｰﾀ無し
  // Bit0 : 1=ｴﾗｰ有り、0=ｴﾗｰ無し
  Result_status = B11000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Snd_data_Buffer = Result_status;
  PORTC = Snd_data_Buffer;                                    // ﾃﾞｰﾀ送信(PC7～PC0)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ｾﾝﾄﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ開始 ---------------------------------------------
void Command03_start() {
//Serial.println("Command03_start();");
// 読み書ﾊﾞｯﾌｧｰを送信する前処理

  // Bit7 : I/O動作終了ﾌﾗｸﾞ
  // Bit6 : 1=ﾘｰﾄﾞﾊﾞｯﾌｧにﾃﾞｰﾀ有り、0=ﾘｰﾄﾞﾊﾞｯﾌｧにﾃﾞｰﾀ無し
  // Bit0 : 1=ｴﾗｰ有り、0=ｴﾗｰ無し
  Result_status = B11000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(未送信ﾃﾞｰﾀあり)
//Snd_data_Buffer = Result_status;
//PORTC = Snd_data_Buffer;                                    // ﾃﾞｰﾀ送信(PC7～PC0)
  Comm_sts = 3;                                               // 3:ﾃﾞｰﾀｾｯﾄ
  Byte_cnt = 0;                                 // ｾｸﾀ内の何ﾊﾞｲﾄ目(0-255)を処理しているのか
  RW_Sector_cnt = 1;                            // 読み書きｾｸﾀ処理件数(すでにCommand02で1ｾｸﾀ読んでいるから[1])
}


// ｾﾝﾄﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command03_rtn() {
//Serial.println("Command03_rtn();");
// 読み書ﾊﾞｯﾌｧｰを送信する

  Snd_data_Buffer = RW_Buffer[0][Byte_cnt];

  Byte_cnt++;                                                 // ｾｸﾀ内の何ﾊﾞｲﾄ目を処理しているのか

  if ((Byte_cnt == 0) && (Sector_qt > 1)) {
    if (RW_Sector_cnt < Sector_qt) {
      Sector_cnt++;                                           // 何番のｾｸﾀを処理しているのか
//    SD_card_read(File_Name, Track_cnt, Sector_cnt, TBL_cnt);// SDｶｰﾄﾞ読込み
      SD_card_read(0);                                        // RW_Buffer[0]にｾｯﾄする
   }
    RW_Sector_cnt++;                                          // 読み書きｾｸﾀ処理件数
  }
}


// ｺﾋﾟｰ・ｺﾏﾝﾄﾞ ---------------------------------------------
// Sector_qt;                                                 // ｾｸﾀの数量(Sector quantity)
// Drive_sou;                                                 // copy source Drive
// Track_sou;                                                 // copy source Track
// Sector_sou;                                                // copy source Sector
// Drive_dest;                                                // copy destination Drive
// Track_dest;                                                // copy destination Track
// Sector_dest;                                               // copy destination Sector
void Command04_rtn() {
//Serial.println(F("Command04_rtn();"));
// RW_Buffer[0][256];                                         // 読み書ﾊﾞｯﾌｧｰ
// FD読込みﾊﾞｯﾌｧｰにｺﾋﾟｰ元ﾄﾞﾗｲﾌﾞの指定ﾄﾗｯｸ・指定ｾｸﾀのﾃﾞｰﾀを読込み、、
// ｺﾋﾟｰ先ﾄﾞﾗｲﾌﾞの指定ﾄﾗｯｸ・指定ｾｸﾀにﾃﾞｰﾀを書込む

  // Bit7 : I/O動作終了ﾌﾗｸﾞ
  // Bit6 : 1=ﾘｰﾄﾞﾊﾞｯﾌｧにﾃﾞｰﾀ有り、0=ﾘｰﾄﾞﾊﾞｯﾌｧにﾃﾞｰﾀ無し
  // Bit0 : 1=ｴﾗｰ有り、0=ｴﾗｰ無し
  Result_status = B00000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Snd_data_Buffer = Result_status;
  PORTC = Snd_data_Buffer;                                    // ﾃﾞｰﾀ送信(PC7～PC0)

  for ( int i = 0 ; i < Sector_qt ; i++ ) {
    Drive_cnt  = Drive_sou;                                   // 0-3
    Track_cnt  = Track_sou;                                   // ｺﾋﾟｰ元ﾄﾗｯｸ番号
    Sector_cnt = Sector_sou + i;                              // ｺﾋﾟｰ元ｾｸﾀ番号
    Insert_File_Name(Drv_FD_Name[Drive_cnt]);                 // ﾌｧｲﾙ名
//  SD_card_read(File_Name, Track_cnt, Sector_cnt, TBL_cnt);  // SDｶｰﾄﾞ読込み
    SD_card_read(0);                                          // RW_Buffer[0]にｾｯﾄする

    Drive_cnt  = Drive_dest;                                  // 0-3
    Track_cnt  = Track_dest;                                  // ｺﾋﾟｰ先ﾄﾗｯｸ番号
    Sector_cnt = Sector_dest + i;                             // ｺﾋﾟｰ先ｾｸﾀ番号
    if (i == 0) {
      if ((VM_Drive != Drive_cnt) || (VM_Track != Track_cnt)) {
        Insert_File_Name(Drv_FD_Name[Drive_cnt]);             // ﾌｧｲﾙ名
//      Track_file_write(File_Name, Track_cnt);               // ﾄﾗｯｸﾌｧｲﾙ書込み
        Track_file_write();                                   // ﾄﾗｯｸﾌｧｲﾙ書込み
        Sector_cnt = Sector_dest + i;                         // ｺﾋﾟｰ先ｾｸﾀ番号
      }
    }
//  SD_card_write(Sector_cnt);                                // SDｶｰﾄﾞ書込み
    SD_card_write();                                          // SDｶｰﾄﾞ書込み
  }
  // FDｲﾒｰｼﾞﾌｧｲﾙ情報を更新(ｲﾒｰｼﾞﾌｧｲﾙ名, 書込み保護, 更新区分, 取出し区分)、
  Insert_File_Name(Drv_FD_Name[Drive_cnt]);                   // ﾌｧｲﾙ名
//FD_info_rewrite(File_Name, 9, 1, 0);                        // 9:変更しない
  FD_info_rewrite(9, 1, 0);                                   // 9:変更しない

  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ﾌｫｰﾏｯﾄ・ｺﾏﾝﾄﾞ ---------------------------------------------
// Track_No;                                                  // ﾄﾗｯｸ番号
void Command05_rtn() {
//Serial.println(F("Command05_rtn();"));
// SD書込みﾊﾞｯﾌｧｰを全て0xFFにして、/FD_IN/FDｲﾒｰｼﾞﾌｧｲﾙの全ｾｸﾀを書き換える

  // Bit7 : I/O動作終了ﾌﾗｸﾞ
  // Bit6 : 1=ﾘｰﾄﾞﾊﾞｯﾌｧにﾃﾞｰﾀ有り、0=ﾘｰﾄﾞﾊﾞｯﾌｧにﾃﾞｰﾀ無し
  // Bit0 : 1=ｴﾗｰ有り、0=ｴﾗｰ無し
  Result_status = B00000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Snd_data_Buffer = Result_status;
  PORTC = Snd_data_Buffer;                                    // ﾃﾞｰﾀ送信(PC7～PC0)

  Drive_cnt = Drive_No;                                       // 0-3
  Insert_File_Name(Drv_FD_Name[Drive_cnt]);                   // ﾌｧｲﾙ名

//Format_rtn(File_Name);                                      // ﾌｫｰﾏｯﾄ
  Format_rtn();                                               // ﾌｫｰﾏｯﾄ
//Quick_Format_rtn(File_Name);                                // ｸｲｯｸ･ﾌｫｰﾏｯﾄ
//Quick_Format_rtn();                                         // ｸｲｯｸ･ﾌｫｰﾏｯﾄ
  // FDｲﾒｰｼﾞﾌｧｲﾙ情報を更新(ｲﾒｰｼﾞﾌｧｲﾙ名, 書込み保護, 更新区分, 出力区分)、
//FD_info_rewrite(File_Name, 9, 1, 0);                        // 9:変更しない
  FD_info_rewrite(9, 1, 0);                                   // 9:変更しない

  
  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command06_rtn() {
//Serial.println("Command06_rtn();");
// Bit7 : I/O動作終了ﾌﾗｸﾞ
// Bit6 : 1=ﾘｰﾄﾞﾊﾞｯﾌｧにﾃﾞｰﾀ有り、0=ﾘｰﾄﾞﾊﾞｯﾌｧにﾃﾞｰﾀ無し
// Bit5 : －
// Bit4 : －
// Bit3 : －
// Bit2 : －
// Bit1 : －
// Bit0 : 1=ｴﾗｰ有り、0=ｴﾗｰ無し

  // Comm_BK : 前のｺﾏﾝﾄﾞ種別
  if ((Comm_BK == 3) || (Comm_BK == 18)) { // ｾﾝﾄﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ
    Result_status = B10000000;                                // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
    Comm_sts = 9;                                             // ｺﾏﾝﾄﾞ終了
  }
  Snd_data_Buffer = Result_status;
  
  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ﾄﾞﾗｲﾌﾞ・ｽﾃｰﾀｽ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command07_rtn() {
//Serial.println("Command07_rtn();");
// Bit7 : ﾄﾞﾗｲﾌﾞ3接続　
// Bit6 : ﾄﾞﾗｲﾌﾞ2接続　
// Bit5 : ﾄﾞﾗｲﾌﾞ1接続　
// Bit4 : ﾄﾞﾗｲﾌﾞ0接続　
// Bit3 : ﾄﾞﾗｲﾌﾞ3 ﾃﾞｨｽｸｾｯﾄﾌﾗｸﾞ (常に1)
// Bit2 : ﾄﾞﾗｲﾌﾞ2 ﾃﾞｨｽｸｾｯﾄﾌﾗｸﾞ (常に1)
// Bit1 : ﾄﾞﾗｲﾌﾞ1 ﾃﾞｨｽｸｾｯﾄﾌﾗｸﾞ (常に1)
// Bit0 : ﾄﾞﾗｲﾌﾞ0 ﾃﾞｨｽｸｾｯﾄﾌﾗｸﾞ (常に1)

//Drive_status = B11111111;
  Drive_status = B11111111;
  Snd_data_Buffer = Drive_status;

  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ﾃｽﾄﾒﾓﾘ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command08_rtn() {
//Serial.println("Command08_rtn();");

  Snd_data_Buffer = 0x80;                                     // ｴﾗｰなし(送信ﾃﾞｰﾀ)

  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ｾﾝﾄﾞ・ﾒﾓﾘﾃﾞｰﾀ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command09_rtn() {
//Serial.println("Command09_rtn();");

  Snd_data_Buffer = 0x00;

  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ﾎﾟｰﾄ・ｱｳﾄﾌﾟｯﾄ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command10_rtn() {
//Serial.println("Command10_rtn();");

    // 何もしない

  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ｾﾝﾄﾞ・ﾒﾓﾘﾃﾞｰﾀ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command11_rtn() {
//Serial.println("Command11_rtn();");

  Snd_data_Buffer = 0x00;
  if ((H_address == 0x07) && (L_address == 0x5F)) {
    Snd_data_Buffer = 0x77;
  }
  if ((H_address == 0x07) && (L_address == 0xEF)) {
    Snd_data_Buffer = 0xEF;
  }
  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ﾚｼｰﾌﾞ・ﾒﾓﾘﾃﾞｰﾀ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command12_rtn() {
//Serial.println("Command12_rtn();");

    // 何もしない

  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ｴｸﾞｾﾞｷｭｰﾄ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command13_rtn() {
//Serial.println("Command13_rtn();");

    // 何もしない

  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ﾛｰﾄﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command14_rtn() {
//Serial.println("Command14_rtn();");

    // 何もしない

  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ｾｰﾌﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command15_rtn() {
//Serial.println("Command15_rtn();");

    // 何もしない

  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ﾛｰﾄﾞ ｱﾝﾄﾞ ｺﾞｰ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command16_rtn() {
//Serial.println("Command16_rtn();");

    // 何もしない

  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ﾗｲﾄﾃﾞｨｽｸ・ｺﾏﾝﾄﾞ開始(高速転送) ---------------------------------------------
void Command17_start() {
//Serial.println("Command17_rtn();");
  // ﾗｲﾄﾃﾞｨｽｸ・ｺﾏﾝﾄﾞ
  Command01_start();
}


// ﾗｲﾄﾃﾞｨｽｸ・ｺﾏﾝﾄﾞ(高速転送) ---------------------------------------------
void Command17_rtn() {
//Serial.println("Command17_rtn();");
  // ﾗｲﾄﾃﾞｨｽｸ・ｺﾏﾝﾄﾞ
  Command01_rtn();
}


// ｾﾝﾄﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ開始(高速転送) ---------------------------------------------
void Command18_start() {
//Serial.println("Command18_rtn();");
  // ｾﾝﾄﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ開始
  Command03_start();
}


// ｾﾝﾄﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ(高速転送) ---------------------------------------------
void Command18_rtn() {
//Serial.println("Command18_rtn();");
  // ｾﾝﾄﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ
  Command03_rtn();
}


// ｴﾗｰｽﾃｰﾀｽ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command19_rtn() {
//Serial.println("Command19_rtn();");

  Snd_data_Buffer = 0x00;

  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ﾃﾞﾊﾞｲｽｽﾃｰﾀｽ・ｺﾏﾝﾄﾞ ---------------------------------------------
// Drive_No;                                    // ﾄﾞﾗｲﾌﾞ番号
void Command20_rtn() {
//Serial.println("Command20_rtn();");
// Bit7 : ?
// Bit6 : WRITE PROTECT(書込み保護)
// Bit5 : ?
// Bit4 : ?
// Bit3 : ?
// Bit2 : ?
// Bit1 : ?
// Bit0 : ?
//Snd_data_Buffer = 0x29;                                     // PC-80S31(gotek)をﾛｼﾞｱﾅで調べたら
//Snd_data_Buffer = B00101001;                                // 書込み保護解除
//Snd_data_Buffer = B01101001;                                // 書込み保護

  Drive_cnt = Drive_No;                                       // 0-3
  Drv_fd_link_load();                                         // ﾄﾞﾗｲﾌﾞ・FDｲﾒｰｼﾞ紐づけﾌｧｲﾙ読込み
  Insert_File_Name(Drv_FD_Name[Drive_cnt]);                   // ﾌｧｲﾙ名
//FD_info_read(File_Name);                                    // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
  FD_info_read();                                             // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
  if (FD_protect == 1) {                                      // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし, 1:あり)
    Snd_data_Buffer = B01101001;                              // 書込み保護
  } else {
    Snd_data_Buffer = B00101001;                              // 書込み保護解除
  }
  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ｾﾝﾄﾞ・ﾒﾓﾘﾃﾞｰﾀ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command21_rtn() {
//Serial.println("Command21_rtn();");

  Snd_data_Buffer = 0x00;

  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ﾚｼｰﾌﾞ・ﾒﾓﾘﾃﾞｰﾀ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command22_rtn() {
//Serial.println("Command22_rtn();");

    // 何もしない

  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ﾓｰﾄﾞﾁｪﾝｼﾞ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command23_rtn() {
//Serial.println("Command23_rtn();");
// Bit7 : －
// Bit6 : －
// Bit5 : －
// Bit4 : －
// Bit3 : ﾄﾞﾗｲﾌﾞ3 1=両面、0=片面
// Bit2 : ﾄﾞﾗｲﾌﾞ2 1=両面、0=片面
// Bit1 : ﾄﾞﾗｲﾌﾞ1 1=両面、0=片面
// Bit0 : ﾄﾞﾗｲﾌﾞ0 1=両面、0=片面

  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


// ｾﾝﾄﾞ・ﾓｰﾄﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ ---------------------------------------------
void Command24_rtn() {
//Serial.println("Command24_rtn();");
// Bit7 : －
// Bit6 : －
// Bit5 : －
// Bit4 : －
// Bit3 : ﾄﾞﾗｲﾌﾞ3 1=両面、0=片面
// Bit2 : ﾄﾞﾗｲﾌﾞ2 1=両面、0=片面
// Bit1 : ﾄﾞﾗｲﾌﾞ1 1=両面、0=片面
// Bit0 : ﾄﾞﾗｲﾌﾞ0 1=両面、0=片面
// ﾌｫｰﾏｯﾄ区分(1:d88(1D 35ﾄﾗｯｸ), 2:d88(1D 40ﾄﾗｯｸ), 3:d88(2D), 4:予備)
// ﾌｫｰﾏｯﾄ区分(5:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 35ﾄﾗｯｸ), 6:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 40ﾄﾗｯｸ), 7:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(2D), 8:予備)
//Mode_data = B00001111;
  Mode_data = B00000000;
  for ( int i = 0 ; i <= 3 ; i++ ) {
    Insert_File_Name(Drv_FD_Name[i]);                         // ﾌｧｲﾙ名
    FD_info_read();                                           // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
    // ﾌｫｰﾏｯﾄ区分(3:d88(2D), 7:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(2D))
    if ((FD_format == 3) || (FD_format == 7)) {
      Mode_data += B00000001 << i;
    }
  }
  Snd_data_Buffer = Mode_data;

  Result_status = B10000000;                                  // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
  Comm_sts = 9;                                               // ｺﾏﾝﾄﾞ終了
}


//
