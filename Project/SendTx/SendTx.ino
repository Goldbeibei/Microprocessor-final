#include <IRremote.h>

IRsend irsend; // IRRemote限定使用數位腳位3

void setup()
{
  Serial.begin(115200);
}

void loop() {
  int d;
  
//  if( (d = Serial.read()) != -1) { // 讀取序列埠
  unsigned long v = 0x0;
//    switch(d){ // 根據讀取到的資料，換成代表六個按鍵的紅外線編碼
//      case '1':
//        v = 0x1705002000002000A000E08FC3;
//      break;
//      case '2':
//        v = 0x1705000000002000A000E08FC3;
//      break;
//    }
   v = 0x1705000000002000A000E08FC3;
   
    if(v != 0x0){
      Serial.print("read ");
      Serial.print(d);
      Serial.print(", IR send ");
      Serial.println(v, HEX);
      irsend.sendNEC(v, 32); // 輸出紅外線訊號
    }
//  }
}
