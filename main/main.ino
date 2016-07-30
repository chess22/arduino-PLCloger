//コンパイルエラー出ます。
#include <SPI.h>
#include <SD.h>
 
// SDカードの設定
// イーサーネットシールドは 4
// Adafruit のSDシールドは 10
// Sparkfun のSDシールドは 8
const int chipSelect = 4;

//使用する変数の定義
//bool ows = HIGH; //1つ前の入力入力状態
//int count = 0;　//使わないかも
//int count_high = 0; //使わないかも
float val = 0; //ローパスフィルタ後の出力値
unsigned long prev = millis(); //
unsigned long cur; //現在時刻

void setup() {
  //ピン入力設定
  pinMode(2,INPUT);
  
  // シリアルポート初期化
  Serial.begin(9600);
  
  while (!Serial) {
    ;// wait for serial port to connect. Needed for Leonardo only
  }
  Serial.print("Initializing SD card...");
  pinMode(4, OUTPUT);
  
  // SDライブラリを初期化
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("card initialized.");
}
void loop() {
  unsigned long cur = millis();
  bool sw = digitalRead(2);
  
  //ローパスフィルタ変換
  if(sw == HIGH){
    val = val*0.9 + 0.1;
  }
  else{
    val = val*0.9;
  }
  
  //チャタリング防止のための遅延
  if(cur - prev >400){
    
    if(val >= 0.8){
      //SDカードへの書き込み用　初期設定
      String dataString = "";
      
      //SDカードへの書き込み
      File dataFile = SD.open("DATALOG.TXT", FILE_WRITE); //ファイル名
      
      if (dataFile) { //SDカードのファイルが無事開けたら(ない場合は新規作成)
        dataFile.println(dataString); //dataStringに入っている内容を書き込み
        dataFile.close(); //書き込み後ファイルを閉じる
        Serial.println(dataString);
      }
      else {
        Serial.println("error opening datalog.txt");
      }
      prev = cur;
    } 
  }
} 
  
