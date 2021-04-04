// 文字列の長さを求める関数(測りたい文字列) ------------------------------------------------
//unsigned int Str_length;                // 文字数(ｸﾞﾛｰﾊﾞﾙ変数)
void String_length(char * _Target) {
  Str_length = 0;
  while(true) {
    if (_Target[Str_length] == NULL) {
      return; 
    }
    Str_length++;
  }
}


// Edit_Strに文字列を挿入する ------------------------------------------------
//char Edit_Str[64];                      // ﾒｯｾｰｼﾞ編集用(ｸﾞﾛｰﾊﾞﾙ変数)
void Insert_Edit_Str(char * Ins_str) {
  String_length(Ins_str);
  for ( int i = 0 ; i < Str_length ; i++ ) {
    Edit_Str[i] = Ins_str[i];
  }
  Edit_Str[Str_length] = NULL;
}


// Edit_Strに文字列を連結する ------------------------------------------------
//char Edit_Str[64];                      // ﾒｯｾｰｼﾞ編集用(ｸﾞﾛｰﾊﾞﾙ変数)
void Connect_Edit_Str(char * Con_str) {
  int i, j, k;
  String_length(Edit_Str);
  i = Str_length;
  String_length(Con_str);
  j = Str_length;
  for ( int cnt = 0 ; cnt < j ; cnt++ ) {
    k = i + cnt;
    Edit_Str[k] = Con_str[cnt];
  }
  k++;
  Edit_Str[k] = NULL;
}


// 文字列の一部を文字配列にｺﾋﾟｰする ------------------------------------------------
//char Copy_Str[13];                      // ｺﾋﾟｰされた文字列の一部(ｸﾞﾛｰﾊﾞﾙ変数)
void String_toCharArray(char * Char_tbl, unsigned int bufsize, unsigned int index) {
  int i;
  String_length(Char_tbl);
  if (index > Str_length) {
    Copy_Str[0] = NULL;
  }
  for ( i = 0 ; i < bufsize ; i++ ) {
    Copy_Str[i] = Char_tbl[index];
    index++;
    if (index == Str_length) {
      break;
    }
  }
  i++;
  Copy_Str[i] = NULL;
}


// 文字列を数値(10進数0-999999999)に変換する ------------------------------------------------
//long Str_DEC;                   // 文字列から変換された数値(ｸﾞﾛｰﾊﾞﾙ変数)
void Str_DEC_conversion(char * Char_DEC) {
//Serial.print(F("Char_DEC = "));Serial.println(Char_DEC);//debug
  byte Byte_DEC, i;
  unsigned long Num_digit = 1;
  unsigned long Work_DEC;
  Str_DEC = 0;
  String_length(Char_DEC);
  if (Str_length > 9) {
    return;
  }
  for ( i = 1 ; i < Str_length ; i++ ) {
    Num_digit = Num_digit * 10;
  }
  for ( i = 0 ; i < Str_length ; i++ ) {
    if ((Char_DEC[i] >= 0x30) && (Char_DEC[i] <= 0x39)) {     // Asciiｺｰﾄﾞの'0'-'9'だったら
      Work_DEC = byte(Char_DEC[i]) - 0x30;                    // 0x30 : Asciiｺｰﾄﾞの'0'
      Str_DEC += Work_DEC * Num_digit;
//Serial.print(F("Work_DEC = "));Serial.println(Work_DEC);    // debug
      Num_digit = Num_digit / 10;
    }
  }
//Serial.print(F("Str_DEC = "));Serial.println(Str_DEC, DEC); // debug
}


// 数値(10進数0-999999999)を文字列に変換する ------------------------------------------------
//char DEC_Str[10];                   // 数値から変換された文字列(ｸﾞﾛｰﾊﾞﾙ変数)
void DEC_Str_conversion(long Long_DEC) {
  int i, j;
  byte byte_DEC;
  byte Num_digit = 1;                 // 数値の桁数
  unsigned long DEC_tbl[9] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};
  unsigned long Long_Num;
  DEC_Str[0] = '0';
  DEC_Str[1] = NULL;
  if ((Long_DEC == 0) || (Long_DEC > 999999999)) {
    return;
  }
  for ( i = 0 ; i < 9 ; i++ ) {
    if (Long_DEC >= DEC_tbl[i]) {
      Num_digit = i + 1;
    } else {
      break;
    }
  }
  i = Num_digit - 1;
  for ( j = 0 ; j < Num_digit ; j++ ) {
    Long_Num   = Long_DEC / DEC_tbl[i];
    Long_DEC   = Long_DEC % DEC_tbl[i];                       // 剰余(割り算の余り)
    byte_DEC   = Long_Num;
    DEC_Str[j] = byte_DEC + 0x30;                             // 0x30 : Asciiｺｰﾄﾞの'0'
    i--;
  }
  DEC_Str[Num_digit] = NULL;
}


// 文字列を文字ｺｰﾄﾞで比較する ------------------------------------------------
//int Comp_sts;                           // 比較結果(ｸﾞﾛｰﾊﾞﾙ変数)
void String_compareTo(char * String_a, char * String_b) {
  int cnt, i, j, k, l;
  int a_len, b_len, len;
  byte byte_a, byte_b;
  Comp_sts = 0;                                               // a < b : -1, a = b : 0, a > b : 1
      
  String_length(String_a);
  a_len = Str_length;
  String_length(String_b);
  b_len = Str_length;
  if ((a_len == 0) || (b_len == 0)) {
    return;
  }
  if (a_len < b_len) {
    len = a_len;
  } else {
    len = b_len;
  }
  for ( l = 0 ; l <= len ; l++ ) {
    byte_a = byte(String_a[l]);
    byte_b = byte(String_b[l]);
//Serial.print(F(" byte_a : "));Serial.print(char(byte_a));//debug
//Serial.print(F(" , byte_b : "));Serial.println(char(byte_b));//debug
    if (byte_a > byte_b) {
      Comp_sts =  1;                                          // a < b : -1, a = b : 0, a > b : 1
    } else if (byte_a < byte_b) {
      Comp_sts = -1;                                          // a < b : -1, a = b : 0, a > b : 1
    }
  }
}


// 文字列のｽﾍﾟｰｽを取って文字配列にｺﾋﾟｰする ------------------------------------------------
//char Copy_Str[13];                      // ｺﾋﾟｰされた文字列の一部(ｸﾞﾛｰﾊﾞﾙ変数)
void String_trim(char * Char_tbl) {
  String_length(Char_tbl);
  if (Str_length == 0) {
    Copy_Str[0] = NULL;
    return;
  }
  for ( int i = 0 ; i < Str_length ; i++ ) {
    if ((Char_tbl[i] == LF) || (Char_tbl[i] == CR)) {
      Copy_Str[i] = NULL;
      break;
    }
    if ((Char_tbl[i] == ' ') || (Char_tbl[i] == '\n')) {
      Copy_Str[i] = NULL;
      break;
    }
    Copy_Str[i] = Char_tbl[i];
  }
}


//
