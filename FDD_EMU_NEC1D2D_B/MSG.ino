////////////////////////////////////////////////////////////////////////////////////////////
/// ﾌﾗｯｼｭﾒﾓﾘ･ﾃﾞｰﾀ部 //////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// ﾒｯｾｰｼﾞ(SDｶｰﾄﾞ準備案内) ------------------------------------------------
const char Data_SD_Init[4][64] PROGMEM = {
"このＳＤカードをエミュレータ用に設定して",
"いいですか？",
"【実行】で確定、処理時間は約３０秒です。",
"ちがう場合、電源を切り、かえてください。"
};
const char * const Str_SD_Init[] PROGMEM = {
Data_SD_Init[0],
Data_SD_Init[1],
Data_SD_Init[2],
Data_SD_Init[3]
};


// ﾒｯｾｰｼﾞ(SDｶｰﾄﾞ準備案内) ------------------------------------------------
const char Data_SD_Init_wait[4][64] PROGMEM = {
"●●●●● お待ちください ●●●●●",
"約３０秒で終わります。",
"終わるまで電源は切らないでください。"
};
const char * const Str_SD_Init_wait[] PROGMEM = {
Data_SD_Init_wait[0],
Data_SD_Init_wait[1],
Data_SD_Init_wait[2]
};


// ﾘｽﾄへﾒｯｾｰｼﾞ出力(FDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ案内) ------------------------------------------------
const char Data_FD_set[20][64] PROGMEM = {
"ＳＤカードにフォルダが新たにできています",
"［ＦＤ＿ＩＮ］はＦＤイメージを入れます。",
"［ＦＤ＿ＯＵＴ］は修正したＦＤイメージが",
"出力されます。［ＥＭＵ］はシステム用です",
"使えるのはＤ８８とプレーンイメージです。",
"名前は半角英数字８＋３文字までです。",
"  ",
"  ",
"  ",
"  ",
"くわしくはＳＤカードの",
"ＲＥＡＤＭＥ．ＴＸＴを、お読みください。",
"  ",
"  ",
"  ",
"  ",
"●●●●●説明をお読みください●●●●●",
"その後、電源を切り、ＳＤカードを取出し、",
"ＳＤカードにＦＤイメージを入れてください",
"※ 現在、タッチパネルは反応しません。"
};
const char * const Str_FD_set[] PROGMEM = {
Data_FD_set[0],
Data_FD_set[1],
Data_FD_set[2],
Data_FD_set[3],
Data_FD_set[4],
Data_FD_set[5],
Data_FD_set[6],
Data_FD_set[7],
Data_FD_set[8],
Data_FD_set[9],
Data_FD_set[10],
Data_FD_set[11],
Data_FD_set[12],
Data_FD_set[13],
Data_FD_set[14],
Data_FD_set[15],
Data_FD_set[16],
Data_FD_set[17],
Data_FD_set[18],
Data_FD_set[19]
};


// ﾒｯｾｰｼﾞ(機能選択案内) ------------------------------------------------
const char Data_Init[4][64] PROGMEM = {
"ＦＤ差しかえ：ＦＤをドライブに入れる。",
"ライトプロテクト：設定と解除を切かえる。",
"イメージ出力：修正後のイメージを作る。",
"【▲】【▼】でイメージを選んでください。"
};
const char * const Str_Init[] PROGMEM = {
Data_Init[0],
Data_Init[1],
Data_Init[2],
Data_Init[3]
};


// ﾒｯｾｰｼﾞ(FD差替え選択案内) ------------------------------------------------
const char Data_CHANGE_select[3][64] PROGMEM = {
"■■■■ＦＤ差しかえが選ばれました■■■■",// [0]
"【▲】【▼】でドライブを選んでください。",  // [1]
"【実行】で確定、【中止】でやめます。"      // [2]
};
const char * const Str_CHANGE_select[] PROGMEM = {
Data_CHANGE_select[0],
Data_CHANGE_select[1],
Data_CHANGE_select[2]
};


// ﾒｯｾｰｼﾞ(ﾄﾞﾗｲﾌﾞ選択案内) ------------------------------------------------
const char Data_Drive_select[3][64] PROGMEM = {
"■■■■ ドライブが選ばれました ■■■■",  // [0]
"【▲】【▼】でイメージを選んでください。",  // [1]
"【実行】で確定、【中止】でやめます。"      // [2]
};
const char * const Str_Drive_select[] PROGMEM = {
Data_Drive_select[0],
Data_Drive_select[1],
Data_Drive_select[2]
};


// ﾒｯｾｰｼﾞ(ﾗｲﾄﾌﾟﾛﾃｸﾄ選択案内) ------------------------------------------------
const char Data_PROTECT_select[3][64] PROGMEM = {
"■■ライトプロテクトが選ばれました■■",
"今の設定を変えるなら、【実行】で確定、",
"【中止】でやめます。"
};
const char * const Str_PROTECT_select[] PROGMEM = {
Data_PROTECT_select[0],
Data_PROTECT_select[1],
Data_PROTECT_select[2]
};


// ﾒｯｾｰｼﾞ(ｲﾒｰｼﾞ出力選択案内) ------------------------------------------------
const char Data_OUTPUT_select[3][64] PROGMEM = {
"■■■イメージ出力が選ばれました■■■",
"【実行】で確定します。",
"【中止】でやめます。"
};
const char * const Str_OUTPUT_select[] PROGMEM = {
Data_OUTPUT_select[0],
Data_OUTPUT_select[1],
Data_OUTPUT_select[2]
};


// ﾒｯｾｰｼﾞ(処理実行中案内) ------------------------------------------------
const char Data_OUTPUT_wait[3][64] PROGMEM = {
"●●●●● お待ちください ●●●●●",
"処理時間は約３０秒です。",
"終わるまで電源は切らないでください。"
};
const char * const Str_OUTPUT_wait[] PROGMEM = {
Data_OUTPUT_wait[0],
Data_OUTPUT_wait[1],
Data_OUTPUT_wait[2]
};


// ﾒｯｾｰｼﾞ(FD差しかえ終了) ------------------------------------------------
const char Data_CHANGE_end[2][64] PROGMEM = {
"□□□□□□ ＦＤ差しかえ □□□□□□",
"ドライブにＦＤがセットされました。"
};
const char * const Str_CHANGE_end[] PROGMEM = {
Data_CHANGE_end[0],
Data_CHANGE_end[1]
};


// ﾒｯｾｰｼﾞ(ﾗｲﾄﾌﾟﾛﾃｸﾄ終了) ------------------------------------------------
const char Data_PROTECT_end[2][64] PROGMEM = {
"□□□□□ ライトプロテクト □□□□□",
"ライトプロテクトを切りかえました。"
};
const char * const Str_PROTECT_end[] PROGMEM = {
Data_PROTECT_end[0],
Data_PROTECT_end[1]
};


// ﾒｯｾｰｼﾞ(ｲﾒｰｼﾞ出力終了) ------------------------------------------------
const char Data_OUTPUT_end[3][64] PROGMEM = {
"□□□□□□ イメージ出力 □□□□□□",
"［ＦＤ＿ＯＵＴ］フォルダにファイルが",
"できています。"
};
const char * const Str_OUTPUT_end[] PROGMEM = {
Data_OUTPUT_end[0],
Data_OUTPUT_end[1],
Data_OUTPUT_end[2]
};


// ｴﾗｰﾒｯｾｰｼﾞ(SDカードの初期読込みができない) ------------------------------------------------
const char Data_Err_SD_init[4][64] PROGMEM = {
"※※※※ ＳＤカード エラー ※※※※",
"ＳＤとリーダーを調査してください。",
"電源を切り、ＳＤの配線を確認して",
"ください。"
};
const char * const Str_Err_SD_init[] PROGMEM = {
Data_Err_SD_init[0],
Data_Err_SD_init[1],
Data_Err_SD_init[2],
Data_Err_SD_init[3]
};


// ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが読込みﾓｰﾄﾞで開けない) ------------------------------------------------
const char Data_Err_File_read_open[4][64] PROGMEM = {
"※※※※ ＳＤファイル エラー ※※※※",
"ファイルを読みこみモードで開けません。",
"電源を入れ直してください。ダメなら、",
"ＳＤをフォーマットしてください。"
};
const char * const Str_Err_File_read_open[] PROGMEM = {
Data_Err_File_read_open[0],
Data_Err_File_read_open[1],
Data_Err_File_read_open[2],
Data_Err_File_read_open[3]
};


// ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない) ------------------------------------------------
const char Data_Err_File_write_open[4][64] PROGMEM = {
"※※※※ ＳＤファイル エラー ※※※※",
"ファイルが書きこみモードで開けません。",
"電源を入れ直してください。ダメなら、",
"ＳＤをフォーマットしてください。"
};
const char * const Str_Err_File_write_open[] PROGMEM = {
Data_Err_File_write_open[0],
Data_Err_File_write_open[1],
Data_Err_File_write_open[2],
Data_Err_File_write_open[3]
};


// ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない) ------------------------------------------------
const char Data_Err_File_write[4][64] PROGMEM = {
"※※※※ ＳＤファイル エラー ※※※※",
"ファイルに書きこみできません！！",
"電源を入れ直してください。ダメなら、",
"ＳＤをフォーマットしてください。"
};
const char * const Str_Err_File_write[] PROGMEM = {
Data_Err_File_write[0],
Data_Err_File_write[1],
Data_Err_File_write[2],
Data_Err_File_write[3]
};


// ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常) ------------------------------------------------
const char Data_Err_System[4][64] PROGMEM = {
"※※※※※ ／ＥＭＵ エラー ※※※※※",
"システムに不整合が起きています！！",
"電源を切り、ＳＤをＰＣでフォーマットし、",
"再度、イニシャライズをしてください。"
};
const char * const Str_Err_System[] PROGMEM = {
Data_Err_System[0],
Data_Err_System[1],
Data_Err_System[2],
Data_Err_System[3]
};


// 警告ﾒｯｾｰｼﾞ([FD_IN]ﾌｫﾙﾀﾞｰがない) ------------------------------------------------
const char Data_Warning_FD_IN[4][64] PROGMEM = {
"※※※※ ＳＤファイル エラー ※※※※",
"［ＦＤ＿ＩＮ］フォルダがありません！！",
"電源を切り、ＳＤをＰＣでフォーマットし、",
"再度、イニシャライズをしてください。"
};
const char * const Str_Warning_FD_IN[] PROGMEM = {
Data_Warning_FD_IN[0],
Data_Warning_FD_IN[1],
Data_Warning_FD_IN[2],
Data_Warning_FD_IN[3]
};


// 警告ﾒｯｾｰｼﾞ(FDｲﾒｰｼﾞﾌｧｲﾙが読込みできない) ------------------------------------------------
const char Data_Warning_FD_img[4][64] PROGMEM = {
"※※※※ ＳＤファイル エラー ※※※※",
"［ＦＤ＿ＩＮ］フォルダにファイルが",
"ありません！！ 電源を切り、",
"ＳＤにＦＤイメージを入れてください。"
};
const char * const Str_Warning_FD_img[] PROGMEM = {
Data_Warning_FD_img[0],
Data_Warning_FD_img[1],
Data_Warning_FD_img[2],
Data_Warning_FD_img[3]
};


// 警告ﾒｯｾｰｼﾞ([FD_IN]ﾌｫﾙﾀﾞｰの最大ﾌｧｲﾙ数ｵｰﾊﾞｰ) ------------------------------------------------
const char Data_Warning_Max_file[4][64] PROGMEM = {
"※※※※ ＳＤファイル エラー ※※※※",
"［ＦＤ＿ＩＮ］フォルダにファイルが",
"多すぎます！！ 電源を切り、",
"６４個以下に減らしてください。"
};
const char * const Str_Warning_Max_file[] PROGMEM = {
Data_Warning_Max_file[0],
Data_Warning_Max_file[1],
Data_Warning_Max_file[2],
Data_Warning_Max_file[3]
};


// 警告ﾒｯｾｰｼﾞ(ﾌｫｰﾏｯﾄ区分(9:対象外)) ------------------------------------------------
const char Data_Warning_format[3][64] PROGMEM = {
"※※※※※ 選べません！！ ※※※※※",
"ファイルサイズがちがいます。",
"これは、使えないＦＤフォーマットです。"
};
const char * const Str_Warning_format[] PROGMEM = {
Data_Warning_format[0],
Data_Warning_format[1],
Data_Warning_format[2]
};


// 警告ﾒｯｾｰｼﾞ("********.***"はﾄﾞﾗｲﾌﾞからFD取出し用) ------------------------------------------------
const char Data_Warning_DUMMY_Name[3][64] PROGMEM = {
"※※※※※ 選べません！！ ※※※※※",
"これは、ドライブからＦＤ取出し用です。",
"［ＦＤ差しかえ］の時だけ使えます。"
};
const char * const Str_Warning_DUMMY_Name[] PROGMEM = {
Data_Warning_DUMMY_Name[0],
Data_Warning_DUMMY_Name[1],
Data_Warning_DUMMY_Name[2]
};


// ﾒｯｾｰｼﾞ編集用 ------------------------------------------------
const char Data_MSG_edit[5][64] PROGMEM = {
" [",               // [0]
"[ﾄﾞﾗｲﾌﾞNo,",        // [1]
"] ",               // [2]
"が処理対象です。",    // [3]
"は不可です。"        // [4]
};
const char * const Str_MSG_edit[] PROGMEM = {
Data_MSG_edit[0],
Data_MSG_edit[1],
Data_MSG_edit[2],
Data_MSG_edit[3],
Data_MSG_edit[4]
};


////////////////////////////////////////////////////////////////////////////////////////////
/// 処理部 //////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// ﾒｯｾｰｼﾞ(SDｶｰﾄﾞ準備案内) ------------------------------------------------
void MSG_SD_Init() {
  int i, j;
  DSP.fillRect(MSG_SQ, WHITE);                                   // ﾒｯｾｰｼﾞ欄
  for (i = 0; i <= 3; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_SD_Init[i])));
    j = i * 20 + 402;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
}


// ﾒｯｾｰｼﾞ(SDｶｰﾄﾞ準備案内) ------------------------------------------------
void MSG_SD_Init_wait() {
  int i, j;
  DSP.fillRect(MSG_SQ, WHITE);                                   // ﾒｯｾｰｼﾞ欄
  for (i = 0; i <= 2; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_SD_Init_wait[i])));
    j = i * 20 + 402;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
}


// ﾘｽﾄへﾒｯｾｰｼﾞ出力(FDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ案内) ------------------------------------------------
void MSG_FD_set() {
  int i, j, k;
  DSP.fillRect(LIST2_SQ, WHITE);
  for (i = 0; i <= 15; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_FD_set[i])));
    j = i * 20 + 40;
    KNJ_print(Edit_Str, 0, j, 2, BLACK);
  }
  DSP.fillRect(MSG_SQ, WHITE);                                  // ﾒｯｾｰｼﾞ欄
  for (i = 0; i <= 3; i++) {
    k = i + 16;
    j = i * 20 + 402;
    strcpy_P(Edit_Str, pgm_read_word(&(Str_FD_set[k])));
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
}


// ﾒｯｾｰｼﾞ(機能選択案内) ------------------------------------------------
void MSG_Init() {
  int i, j;
  DSP.fillRect(MSG_SQ, WHITE);                                 // ﾒｯｾｰｼﾞ欄
  for (i = 0; i <= 3; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Init[i])));
    j = i * 20 + 402;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
}


// ﾒｯｾｰｼﾞ(FD差替え選択案内) ------------------------------------------------
void MSG_CHANGE_select() {
  int i, j;
  DSP.fillRect(MSG_SQ, WHITE);                                 // ﾒｯｾｰｼﾞ欄
  strcpy_P(Edit_Str, pgm_read_word(&(Str_CHANGE_select[0])));
  KNJ_print(Edit_Str, MSG_1_ST, BLACK);
//Insert_Edit_Str(" [");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_MSG_edit[0])));
  Connect_Edit_Str(File_Name);                                // Edit_Strに文字列を連結する
//Connect_Edit_Str("] ");
  strcpy_P(Short_Str, pgm_read_word(&(Str_MSG_edit[2])));
  Connect_Edit_Str(Short_Str);                                // Edit_Strに文字列を連結する
  ANK_print(Edit_Str, MSG_2_ST, BLACK);                       // FDｲﾒｰｼﾞﾌｧｲﾙ名を表示する
//Insert_Edit_Str("が処理対象です。");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_MSG_edit[3])));
  KNJ_print(Edit_Str, 192, 422, 2, BLACK);
  for (i = 1; i <= 2; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_CHANGE_select[i])));
    j = i * 20 + 422;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
}


// ﾒｯｾｰｼﾞ(ﾄﾞﾗｲﾌﾞ選択案内) ------------------------------------------------
void MSG_Drive_select() {
  byte Edit_No;
  int i, j;
  DSP.fillRect(MSG_SQ, WHITE);                                 // ﾒｯｾｰｼﾞ欄
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Drive_select[0])));
  KNJ_print(Edit_Str, 5, 402, 2, BLACK);
//Insert_Edit_Str("[ﾄﾞﾗｲﾌﾞNo,");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_MSG_edit[1])));
  Edit_No = Drv_No + 1;
  DEC_Str_conversion(Edit_No);                                // 数値を文字列に変換する
  Connect_Edit_Str(DEC_Str);                                  // Edit_Strに文字列を連結する
//Connect_Edit_Str("] ");                                     // Edit_Strに文字列を連結する
  strcpy_P(Short_Str, pgm_read_word(&(Str_MSG_edit[2])));
  Connect_Edit_Str(Short_Str);                                // Edit_Strに文字列を連結する
  ANK_print(Edit_Str, MSG_2_ST, BLACK);                       // ﾄﾞﾗｲﾌﾞ番号を表示する
//Insert_Edit_Str("が処理対象です。");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_MSG_edit[3])));
  KNJ_print(Edit_Str, 192, 422, 2, BLACK);
  for (i = 1; i <= 2; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Drive_select[i])));
    j = i * 20 + 422;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
}


// ﾒｯｾｰｼﾞ(ﾗｲﾄﾌﾟﾛﾃｸﾄ選択案内) ------------------------------------------------
void MSG_PROTECT_select() {
  int i, j;
  DSP.fillRect(MSG_SQ, WHITE);                                 // ﾒｯｾｰｼﾞ欄
  strcpy_P(Edit_Str, pgm_read_word(&(Str_PROTECT_select[0])));
  KNJ_print(Edit_Str, MSG_1_ST, BLACK);
//Insert_Edit_Str(" [");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_MSG_edit[0])));
  Connect_Edit_Str(File_Name);                                // Edit_Strに文字列を連結する
//Connect_Edit_Str("] ");
  strcpy_P(Short_Str, pgm_read_word(&(Str_MSG_edit[2])));
  Connect_Edit_Str(Short_Str);                                // Edit_Strに文字列を連結する
  ANK_print(Edit_Str, MSG_2_ST, BLACK);                       // FDｲﾒｰｼﾞﾌｧｲﾙ名を表示する
//Insert_Edit_Str("が処理対象です。");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_MSG_edit[3])));
  KNJ_print(Edit_Str, 192, 422, 2, BLACK);
  for (i = 1; i <= 2; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_PROTECT_select[i])));
    j = i * 20 + 422;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
}


// ﾒｯｾｰｼﾞ(ｲﾒｰｼﾞ出力選択案内) ------------------------------------------------
void MSG_OUTPUT_select() {
  int i, j;
  DSP.fillRect(MSG_SQ, WHITE);                                 // ﾒｯｾｰｼﾞ欄
  strcpy_P(Edit_Str, pgm_read_word(&(Str_OUTPUT_select[0])));
  KNJ_print(Edit_Str, MSG_1_ST, BLACK);
//Insert_Edit_Str(" [");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_MSG_edit[0])));
  Connect_Edit_Str(File_Name);                                // Edit_Strに文字列を連結する
//Connect_Edit_Str("] ");
  strcpy_P(Short_Str, pgm_read_word(&(Str_MSG_edit[2])));
  Connect_Edit_Str(Short_Str);                                // Edit_Strに文字列を連結する
  ANK_print(Edit_Str, MSG_2_ST, BLACK);                       // FDｲﾒｰｼﾞﾌｧｲﾙ名を表示する
//Insert_Edit_Str("が処理対象です。");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_MSG_edit[3])));
  KNJ_print(Edit_Str, 192, 422, 2, BLACK);
  for (i = 1; i <= 2; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_OUTPUT_select[i])));
    j = i * 20 + 422;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
}


// ﾒｯｾｰｼﾞ(処理実行中案内) ------------------------------------------------
void MSG_OUTPUT_wait() {
  int i, j;
  DSP.fillRect(MSG_SQ, WHITE);                                 // ﾒｯｾｰｼﾞ欄
  for (i = 0; i <= 2; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_OUTPUT_wait[i])));
    j = i * 20 + 402;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
}


// ﾒｯｾｰｼﾞ(FD差しかえ終了) ------------------------------------------------
void MSG_CHANGE_end() {
  int i, j;
  DSP.fillRect(MSG_SQ, WHITE);                                 // ﾒｯｾｰｼﾞ欄
  for (i = 0; i <= 1; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_CHANGE_end[i])));
    j = i * 20 + 402;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
}


// ﾒｯｾｰｼﾞ(ﾗｲﾄﾌﾟﾛﾃｸﾄ終了) ------------------------------------------------
void MSG_PROTECT_end() {
  int i, j;
  DSP.fillRect(MSG_SQ, WHITE);                                 // ﾒｯｾｰｼﾞ欄
  for (i = 0; i <= 1; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_PROTECT_end[i])));
    j = i * 20 + 402;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
}


// ﾒｯｾｰｼﾞ(ｲﾒｰｼﾞ出力終了) ------------------------------------------------
void MSG_OUTPUT_end() {
  int i, j;
  DSP.fillRect(MSG_SQ, WHITE);                                 // ﾒｯｾｰｼﾞ欄
  for (i = 0; i <= 2; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_OUTPUT_end[i])));
    j = i * 20 + 402;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
}


// ｴﾗｰﾒｯｾｰｼﾞ(SDカードの初期読込みができない) ------------------------------------------------
void Error_MSG_SD_init() {
  int i, j;
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("# SDｶｰﾄﾞ ﾉ ｼｮｷｶ ﾆ ｼｯﾊﾟｲ ｼﾏｼﾀ !!                          #"));
  line_sharp();
  Serial.println(F("# SDｶｰﾄﾞ ﾄ SDﾘｰﾀﾞｰ ｦ ﾁｮｳｻ ｼﾃ ｸﾀﾞｻｲ｡                       #"));
  Serial.println(F("# ﾃﾞﾝｹﾞﾝ ｦ ｷｯﾃ､ SDｶｰﾄﾞ ﾉ ﾊｲｾﾝ ｦ ｶｸﾆﾝ ｼﾃ ｸﾀﾞｻｲ｡             #"));
  line_sharp();
  Serial.println(F("# ｾｯﾃｲ ｻｷﾞｮｳ ｦ ｽﾙ ﾊﾞｱｲ ﾊ､ｶﾗﾉ SDｶｰﾄﾞ ｦ ｲﾚﾃ ｸﾀﾞｻｲ｡           #"));
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("##################### ｼｽﾃﾑ ﾃｲｼ ｼﾏｼﾀ #####################"));
  line_sharp();
  DSP.setRotation(2);                                        // 1=90度右に回転：2=180度：3=270度
  DSP.fillScreen(GRAY);
  DSP.fillRect(MSG_SQ, RED);                                  // ﾒｯｾｰｼﾞ欄
  for (i = 0; i <= 3; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Err_SD_init[i])));
    j = i * 20 + 402;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
  Waiting_for_reset();                                        // 処理中止
}


// ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが読込みﾓｰﾄﾞで開けない) ------------------------------------------------
void Error_MSG_File_read_open(char * Error_path) {
  int i, j;
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("# ﾌｧｲﾙ ｶﾞ ﾖﾐｺﾐ ﾓｰﾄﾞ ﾃﾞ ﾋﾗｹﾏｾﾝ !!                          #"));
  line_sharp();
  Serial.println(Error_path);
  line_sharp();
  Serial.println(F("# ﾃﾞﾝｹﾞﾝ ｦ ｲﾚﾅｵｼﾃ ｸﾀﾞｻｲ｡                                 #"));
  Serial.println(F("# ﾀﾞﾒﾅ ﾊﾞｱｲ SDｶｰﾄﾞ ｦ ｺｳｶﾝ ｽﾙ ｶ ｸｲｯｸ ﾌｫｰﾏｯﾄ ｼﾃ ｸﾀﾞｻｲ｡       #"));
  line_sharp();
  Serial.println(F("# ﾓｼ FDｲﾒｰｼﾞ ｦ ﾍﾝｺｳ ｼﾃｲﾙ ﾊﾞｱｲ /EMU/FD ﾉ ﾅｶﾆ ｻﾌﾞﾝ ﾃﾞｰﾀ ｶﾞ   #"));
  Serial.println(F("# ｱﾘﾏｽ｡ ｱﾀﾗｼｲ SDｶｰﾄﾞ ﾆ ｺﾋﾟｰ ｽﾚﾊﾞ ﾍﾝｺｳｺﾞ ﾉ ｼﾞｮｳﾀｲ ﾆ ﾓﾄﾞｾﾏｽ｡  #"));
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("##################### ｼｽﾃﾑ ﾃｲｼ ｼﾏｼﾀ #####################"));
  line_sharp();
  MsTimer2::stop();                                           // PD7(D38)(buzzer) : OFF
  PORTD &= B01111111;                                         // PD7(D38)(buzzer) : LOW
  DSP.setRotation(2);                                        // 1=90度右に回転：2=180度：3=270度
  DSP.fillScreen(GRAY);
  DSP.fillRect(MSG_SQ, RED);                                  // ﾒｯｾｰｼﾞ欄
  for (i = 0; i <= 3; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Err_File_read_open[i])));
    j = i * 20 + 402;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
  Waiting_for_reset();                                        // 処理中止
}


// ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない) ------------------------------------------------
void Error_MSG_File_write_open(char * Error_path) {
  int i, j;
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("# ﾌｧｲﾙ ｶﾞ ｶｷｺﾐ ﾓｰﾄﾞ ﾃﾞ ﾋﾗｹﾏｾﾝ !!                          #"));
  line_sharp();
  Serial.println(Error_path);
  line_sharp();
  Serial.println(F("# ﾃﾞﾝｹﾞﾝ ｦ ｲﾚﾅｵｼﾃ ｸﾀﾞｻｲ｡                                 #"));
  Serial.println(F("# ﾀﾞﾒﾅ ﾊﾞｱｲ SDｶｰﾄﾞ ｦ ｺｳｶﾝ ｽﾙ ｶ ｸｲｯｸ ﾌｫｰﾏｯﾄ ｼﾃ ｸﾀﾞｻｲ｡       #"));
  line_sharp();
  Serial.println(F("# ﾓｼ FDｲﾒｰｼﾞ ｦ ﾍﾝｺｳ ｼﾃｲﾙ ﾊﾞｱｲ /EMU/FD ﾉ ﾅｶﾆ ｻﾌﾞﾝ ﾃﾞｰﾀ ｶﾞ   #"));
  Serial.println(F("# ｱﾘﾏｽ｡ ｱﾀﾗｼｲ SDｶｰﾄﾞ ﾆ ｺﾋﾟｰ ｽﾚﾊﾞ ﾍﾝｺｳｺﾞ ﾉ ｼﾞｮｳﾀｲ ﾆ ﾓﾄﾞｾﾏｽ｡  #"));
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("##################### ｼｽﾃﾑ ﾃｲｼ ｼﾏｼﾀ #####################"));
  line_sharp();
  MsTimer2::stop();                                           // PD7(D38)(buzzer) : OFF
  PORTD &= B01111111;                                         // PD7(D38)(buzzer) : LOW
  DSP.setRotation(2);                                        // 1=90度右に回転：2=180度：3=270度
  DSP.fillScreen(GRAY);
  DSP.fillRect(MSG_SQ, RED);                                  // ﾒｯｾｰｼﾞ欄
  for (i = 0; i <= 3; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Err_File_write_open[i])));
    j = i * 20 + 402;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
  Waiting_for_reset();                                        // 処理中止
}


// ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない) ------------------------------------------------
void Error_MSG_File_write(char * Error_path) {
  int i, j;
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("# ﾌｧｲﾙ ｶﾞ ｶｷｺﾐ ﾃﾞｷﾏｾﾝ !!                                 #"));
  line_sharp();
  Serial.println(Error_path);
  line_sharp();
  Serial.println(F("# ﾃﾞﾝｹﾞﾝ ｦ ｲﾚﾅｵｼﾃ ｸﾀﾞｻｲ｡                                 #"));
  Serial.println(F("# ﾀﾞﾒﾅ ﾊﾞｱｲ SDｶｰﾄﾞ ｦ ｺｳｶﾝ ｽﾙ ｶ ｸｲｯｸ ﾌｫｰﾏｯﾄ ｼﾃ ｸﾀﾞｻｲ｡       #"));
  line_sharp();
  Serial.println(F("# ﾓｼ FDｲﾒｰｼﾞ ｦ ﾍﾝｺｳ ｼﾃｲﾙ ﾊﾞｱｲ /EMU/FD ﾉ ﾅｶﾆ ｻﾌﾞﾝ ﾃﾞｰﾀ ｶﾞ   #"));
  Serial.println(F("# ｱﾘﾏｽ｡ ｱﾀﾗｼｲ SDｶｰﾄﾞ ﾆ ｺﾋﾟｰ ｽﾚﾊﾞ ﾍﾝｺｳｺﾞ ﾉ ｼﾞｮｳﾀｲ ﾆ ﾓﾄﾞｾﾏｽ｡  #"));
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("##################### ｼｽﾃﾑ ﾃｲｼ ｼﾏｼﾀ #####################"));
  line_sharp();
  MsTimer2::stop();                                           // PD7(D38)(buzzer) : OFF
  PORTD &= B01111111;                                         // PD7(D38)(buzzer) : LOW
  DSP.setRotation(2);                                        // 1=90度右に回転：2=180度：3=270度
  DSP.fillScreen(GRAY);
  DSP.fillRect(MSG_SQ, RED);                                  // ﾒｯｾｰｼﾞ欄
  for (i = 0; i <= 3; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Err_File_write[i])));
    j = i * 20 + 402;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
  Waiting_for_reset();                                        // 処理中止
}


// ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常) ------------------------------------------------
void Error_MSG_System() {
  int i, j;
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("# /EMU ｴﾗｰ !!                                           #"));
  line_sharp();
  Serial.println(F("# ｼｽﾃﾑ ﾆ ﾌｾｲｺﾞｳ ｶﾞ ｵｷﾃｲﾏｽ !!                             #"));
  Serial.println(F("# SDｶｰﾄﾞ ｦ ｺｳｶﾝ ｽﾙ ｶ ｸｲｯｸ ﾌｫｰﾏｯﾄ ｼﾃ ｸﾀﾞｻｲ｡                #"));
  line_sharp();
  Serial.println(F("# ﾓｼ FDｲﾒｰｼﾞ ｦ ﾍﾝｺｳ ｼﾃｲﾙ ﾊﾞｱｲ /EMU/FD ﾉ ﾅｶﾆ ｻﾌﾞﾝ ﾃﾞｰﾀ ｶﾞ   #"));
  Serial.println(F("# ｱﾘﾏｽ｡ ｱﾀﾗｼｲ SDｶｰﾄﾞ ﾆ ｺﾋﾟｰ ｽﾚﾊﾞ ﾍﾝｺｳｺﾞ ﾉ ｼﾞｮｳﾀｲ ﾆ ﾓﾄﾞｾﾏｽ｡  #"));
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("##################### ｼｽﾃﾑ ﾃｲｼ ｼﾏｼﾀ #####################"));
  line_sharp();
  MsTimer2::stop();                                           // PD7(D38)(buzzer) : OFF
  PORTD &= B01111111;                                         // PD7(D38)(buzzer) : LOW
  DSP.setRotation(2);                                        // 1=90度右に回転：2=180度：3=270度
  DSP.fillScreen(GRAY);
  DSP.fillRect(MSG_SQ, RED);                                  // ﾒｯｾｰｼﾞ欄
  for (i = 0; i <= 3; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Err_System[i])));
    j = i * 20 + 402;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
Serial.print(F("Path_String : "));Serial.println(Path_String);// debug
Serial.print(F("Track_path  : "));Serial.println(Track_path); // debug
Serial.print(F("Sector_path : "));Serial.println(Sector_path);// debug
Serial.print(F("FD_IN_path  : "));Serial.println(FD_IN_path); // debug
Serial.print(F("OUTPUT_path : "));Serial.println(OUTPUT_path);// debug
  Waiting_for_reset();                                        // 処理中止
}


// 警告ﾒｯｾｰｼﾞ([FD_IN]ﾌｫﾙﾀﾞｰがない) ------------------------------------------------
void Warning_MSG_FD_IN() {
  int i, j;
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("# ﾌｧｲﾙ ｶﾞ ﾖﾐｺﾐ ﾃﾞｷﾏｾﾝ !!                                 #"));
  line_sharp();
  Serial.println(F("# [FD_IN]ﾌｫﾙﾀﾞｰ ｶﾞ ｱﾘﾏｾﾝ !!                              #"));
  Serial.println(F("# SDｶｰﾄﾞ ｦ ｸｲｯｸ ﾌｫｰﾏｯﾄ ｼﾃ ｸﾀﾞｻｲ｡                          #"));
  line_sharp();
  Serial.println(F("# ﾓｼ FDｲﾒｰｼﾞ ｦ ﾍﾝｺｳ ｼﾃｲﾙ ﾊﾞｱｲ /EMU/FD ﾉ ﾅｶﾆ ｻﾌﾞﾝ ﾃﾞｰﾀ ｶﾞ   #"));
  Serial.println(F("# ｱﾘﾏｽ｡ ｱﾀﾗｼｲ SDｶｰﾄﾞ ﾆ ｺﾋﾟｰ ｽﾚﾊﾞ ﾍﾝｺｳｺﾞ ﾉ ｼﾞｮｳﾀｲ ﾆ ﾓﾄﾞｾﾏｽ｡  #"));
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("##################### ｼｽﾃﾑ ﾃｲｼ ｼﾏｼﾀ #####################"));
  line_sharp();
  DSP.fillRect(MSG_SQ, YELLOW);                                  // ﾒｯｾｰｼﾞ欄
  for (i = 0; i <= 3; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Warning_FD_IN[i])));
    j = i * 20 + 402;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
  Waiting_for_reset();                                        // 処理中止
}


// 警告ﾒｯｾｰｼﾞ(FDｲﾒｰｼﾞﾌｧｲﾙが読込みできない) ------------------------------------------------
void Warning_MSG_FD_img() {
  int i, j;
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("# ﾌｧｲﾙ ｶﾞ ﾖﾐｺﾐ ﾃﾞｷﾏｾﾝ !!                                 #"));
  line_sharp();
  Serial.println(F("# [FD_IN]ﾌｫﾙﾀﾞｰ ﾆ ﾌｧｲﾙ ｶﾞ ｱﾘﾏｾﾝ !!                       #"));
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("##################### ｼｽﾃﾑ ﾃｲｼ ｼﾏｼﾀ #####################"));
  line_sharp();
  DSP.fillRect(MSG_SQ, YELLOW);                                  // ﾒｯｾｰｼﾞ欄
  for (i = 0; i <= 3; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Warning_FD_img[i])));
    j = i * 20 + 402;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
  Waiting_for_reset();                                        // 処理中止
}


// 警告ﾒｯｾｰｼﾞ([FD_IN]ﾌｫﾙﾀﾞｰの最大ﾌｧｲﾙ数ｵｰﾊﾞｰ) ------------------------------------------------
void Warning_MSG_Max_file() {
  int i, j;
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("# ﾌｧｲﾙ ﾉ ｶｽﾞ ｶﾞ ｵｵｽｷﾞﾏｽ !!                               #"));
  line_sharp();
  Serial.println(F("# [FD_IN]ﾌｫﾙﾀﾞｰ ﾉ ﾌｧｲﾙ ｻｲﾀﾞｲ ｹﾝｽｳ(MAX: MAX_FILE ) ｦ ｺｴﾃｲﾏｽ !!   #"));
  line_sharp();
//Serial.println(F("########################################################"));
  Serial.println(F("##################### ｼｽﾃﾑ ﾃｲｼ ｼﾏｼﾀ #####################"));
  line_sharp();
  DSP.fillRect(MSG_SQ, YELLOW);                                 // ﾒｯｾｰｼﾞ欄
  for (i = 0; i <= 3; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Warning_Max_file[i])));
    j = i * 20 + 402;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
  Waiting_for_reset();                                        // 処理中止
}


// 警告ﾒｯｾｰｼﾞ(ﾌｫｰﾏｯﾄ区分(9:対象外)) ------------------------------------------------
void Warning_MSG_format() {
  int i, j;
  DSP.fillRect(MSG_SQ, YELLOW);                                 // ﾒｯｾｰｼﾞ欄
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Warning_format[0])));
  KNJ_print(Edit_Str, MSG_1_ST, BLACK);
//Insert_Edit_Str(" [");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_MSG_edit[0])));
  Connect_Edit_Str(File_Name);                                // Edit_Strに文字列を連結する
//Connect_Edit_Str("] ");
  strcpy_P(Short_Str, pgm_read_word(&(Str_MSG_edit[2])));
  Connect_Edit_Str(Short_Str);                                // Edit_Strに文字列を連結する
  ANK_print(Edit_Str, MSG_2_ST, BLACK);                       // FDｲﾒｰｼﾞﾌｧｲﾙ名を表示する
//Insert_Edit_Str("は不可です。");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_MSG_edit[4])));
  KNJ_print(Edit_Str, 192, 422, 2, BLACK);
  for (i = 1; i <= 2; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Warning_format[i])));
    j = i * 20 + 422;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
}


// 警告ﾒｯｾｰｼﾞ("********.***"はﾄﾞﾗｲﾌﾞからFD取出し用) ------------------------------------------------
void Warning_MSG_DUMMY_Name() {
  int i, j;
  DSP.fillRect(MSG_SQ, YELLOW);                                  // ﾒｯｾｰｼﾞ欄
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Warning_DUMMY_Name[0])));
  KNJ_print(Edit_Str, MSG_1_ST, BLACK);
//Insert_Edit_Str(" [");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_MSG_edit[0])));
  Connect_Edit_Str(File_Name);                                 // Edit_Strに文字列を連結する
//Connect_Edit_Str("] ");
  strcpy_P(Short_Str, pgm_read_word(&(Str_MSG_edit[2])));
  Connect_Edit_Str(Short_Str);                                 // Edit_Strに文字列を連結する
  ANK_print(Edit_Str, MSG_2_ST, BLACK);                        // FDｲﾒｰｼﾞﾌｧｲﾙ名を表示する
//Insert_Edit_Str("は不可です。");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_MSG_edit[4])));
  KNJ_print(Edit_Str, 192, 422, 2, BLACK);
  for (i = 1; i <= 2; i++) {
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Warning_DUMMY_Name[i])));
    j = i * 20 + 422;
    KNJ_print(Edit_Str, 2, j, 2, BLACK);
  }
}


//
