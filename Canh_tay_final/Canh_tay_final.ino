/*
  Code này dùng để điều khiển cánh tay như sau
  1, Điều khiển thủ công, Điều khiển theo app qua bluetooth
  2, Điều khiển tự động
    Đặt vật trên bán kính đường tròn từ 27 - 29 cm;
    Cánh tay sẽ đến gắp vật và đưa vật đến vị trí đã cài đặt ở trên app qua bluetooth
*/

#include <SoftwareSerial.h>
//#include <VL53L0X.h>
#include <Servo.h>
#include <Wire.h>
SoftwareSerial Bluetooth(3, 4);


//VL53L0X sensor;
Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;
Servo rada;

int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos; 
double servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos, Posrada;
double df1, df2, df3, df4, df5, df6;
double Goc_quay = 0;
int distance;
int kc;
double s1,s2,s3,s4,s5,s6;
String dataIn = "";

void setup()
{
  Serial.begin(38400);
  Wire.begin(); 

  //sensor.init();
  //sensor.setTimeout(500);
  //sensor.startContinuous();
  Bluetooth.begin(38400); 
  Bluetooth.setTimeout(1);

  servo1PPos = 90;
  servo2PPos = 165;
  servo3PPos = 140;
  servo4PPos = 0;
  servo5PPos = 30;
  servo6PPos = 35;
  Posrada = 90;

  df1 = servo1PPos;
  df2 = servo2PPos;
  df3 = servo3PPos;
  df4 = servo4PPos;
  df5 = servo5PPos;
  df6 = servo6PPos;
  
  rada.attach(11);
  rada.write(90);
  servo05.attach(9);
  s5 = servo05.read();
  servo03.attach(7);
  s3 = servo03.read();
  servo02.attach(6);
  s2 = servo02.read();
  if(s2 < servo2PPos) for(int i=s2;i <= servo2PPos; ++i) {s2++; servo02.write(s2); delay(20);}
  if(s2 > servo2PPos) for(int i=s2;i >= servo2PPos; --i) {s2--; servo02.write(s2); delay(20);}
  if(s2 == servo2PPos) {servo02.write(servo2PPos); delay(20);}
  if(s3 < servo3PPos) for(int i=s3;i <= servo3PPos; ++i) {s3++; servo03.write(s3); delay(20);}
  if(s3 > servo3PPos) for(int i=s3;i >= servo3PPos; --i) {s3--; servo03.write(s3); delay(20);}
  if(s3 == servo3PPos) {servo03.write(servo3PPos); delay(20);}
  if(s5 < servo5PPos) for(int i=s5;i <= servo5PPos; ++i) {s5++; servo05.write(s5); delay(20);}
  if(s5 > servo5PPos) for(int i=s5;i >= servo5PPos; --i) {s5--; servo05.write(s5); delay(20);}
  if(s5 == servo5PPos) {servo05.write(servo5PPos); delay(20);}
  servo01.attach(5);
  servo06.attach(10);
  servo01.write(servo1PPos);
  //*
  servo04.attach(8);
  servo04.write(servo4PPos);
  //*/
  servo06.write(servo6PPos);
}
void loop()
{
  if (Bluetooth.available() > 0) 
  {
    Serial.print('conect');
    dataIn = Bluetooth.readString();
    
    if (dataIn.startsWith("s1")) 
      {
        Serial.print(dataIn);
        String dataInS = dataIn.substring(2, dataIn.length()); // Extract only the number. E.g. from "s1120" to "120"
        servo1Pos = dataInS.toInt();
        if (servo1PPos > servo1Pos) {for(int j = servo1PPos; j >= servo1Pos; j--) {servo01.write(j); delay(10);}}
        if (servo1PPos < servo1Pos) {for(int j = servo1PPos; j <= servo1Pos; j++) {servo01.write(j); delay(10);}}
        servo1PPos = servo1Pos;   
      }

    if (dataIn.startsWith("s2")) 
      {
        Serial.print(dataIn);
        String dataInS = dataIn.substring(2, dataIn.length()); 
        servo2Pos = dataInS.toInt();
        if (servo2PPos > servo2Pos) {for(int j = servo2PPos; j >= servo2Pos; j--) {servo02.write(j); delay(10);}}
        if (servo2PPos < servo2Pos) {for(int j = servo2PPos; j <= servo2Pos; j++) {servo02.write(j); delay(10);}}
        servo2PPos = servo2Pos;   
      }

    if (dataIn.startsWith("s3")) 
      {
         Serial.print(dataIn);
        String dataInS = dataIn.substring(2, dataIn.length()); 
        servo3Pos = dataInS.toInt();
        if (servo3PPos > servo3Pos) {for(int j = servo3PPos; j >= servo3Pos; j--) {servo03.write(j); delay(10);}}
        if (servo3PPos < servo3Pos) {for(int j = servo3PPos; j <= servo3Pos; j++) {servo03.write(j); delay(10);}}
        servo3PPos = servo3Pos;   
      }

    if (dataIn.startsWith("s4")) 
      {
         Serial.print(dataIn);
        String dataInS = dataIn.substring(2, dataIn.length()); 
        servo4Pos = dataInS.toInt();
        if (servo4PPos > servo4Pos) {for(int j = servo4PPos; j >= servo4Pos; j--) {servo04.write(j); delay(10);}}
        if (servo4PPos < servo4Pos) {for(int j = servo4PPos; j <= servo4Pos; j++) {servo04.write(j); delay(10);}}
        servo4PPos = servo4Pos;   
      }

    if (dataIn.startsWith("s5")) 
      {
         Serial.print(dataIn);
        String dataInS = dataIn.substring(2, dataIn.length()); 
        servo5Pos = dataInS.toInt();
        if (servo5PPos > servo5Pos) {for(int j = servo5PPos; j >= servo5Pos; j--) {servo05.write(j); delay(10);}}
        if (servo5PPos < servo5Pos) {for(int j = servo5PPos; j <= servo5Pos; j++) {servo05.write(j); delay(10);}}
        servo5PPos = servo5Pos;   
      }

    if (dataIn.startsWith("s6")) 
      {
         Serial.print(dataIn);
        String dataInS = dataIn.substring(2, dataIn.length()); 
        servo6Pos = dataInS.toInt();
        if (servo6PPos > servo6Pos) {for(int j = servo6PPos; j >= servo6Pos; j--) {servo06.write(j); delay(10);}}
        if (servo6PPos < servo6Pos) {for(int j = servo6PPos; j <= servo6Pos; j++) {servo06.write(j); delay(10);}}
        servo6PPos = servo6Pos;   
      }

    if (dataIn.startsWith("s8"))
      {
        String dataInS = dataIn.substring(2, dataIn.length()); 
        Goc_quay = dataInS.toInt();
      }

    // if (dataIn.startsWith("s9"))
    //   {
    //     String dataInS = dataIn.substring(2, dataIn.length()); 
    //     kc = dataInS.toInt();
    //   }

    if (dataIn.startsWith("RUN"))
      {
        return_to_default();
        run_program()
      }
  }
}
void return_to_default()
{
  s1 = servo1PPos;
  s2 = servo2PPos;
  s3 = servo3PPos;
  s4 = servo4PPos;
  s5 = servo5PPos;
  s6 = servo6PPos;

  if(s2 < df2) for(int i=s2;i <= df2; ++i) {s2++; servo02.write(s2); delay(20);}
  if(s2 > df2) for(int i=s2;i >= df2; --i) {s2--; servo02.write(s2); delay(20);}
  if(s2 == df2) {servo02.write(df2); delay(20);}

  if(s3 < df3) for(int i=s3;i <= df3; ++i) {s3++; servo03.write(s3); delay(20);}
  if(s3 > df3) for(int i=s3;i >= df3; --i) {s3--; servo03.write(s3); delay(20);}
  if(s3 == df3) {servo03.write(df3); delay(20);}

  if(s5 < df5) for(int i=s5;i <= df5; ++i) {s5++; servo05.write(s5); delay(20);}
  if(s5 > df5) for(int i=s5;i >= df5; --i) {s5--; servo05.write(s5); delay(20);}
  if(s5 == df5) {servo05.write(df5); delay(20);}

  servo01.write(df1); delay(20);
  servo04.write(df4); delay(20);
  servo06.write(df6); delay(20);

  servo1PPos = df1;
  servo2PPos = df2;
  servo3PPos = df3;
  servo4PPos = df4;
  servo5PPos = df5;
  servo6PPos = df6;


}

// Thực hiện chức năng phát hiện và gắp vật đến vị trí yêu cầu
void run_program()
{
  while(dataIn != "PAUSE")
  {
    if (Bluetooth.available() > 0) 
    {     
      dataIn = Bluetooth.readString();
      if (dataIn.startsWith("s8"))
      {
        String dataInS = dataIn.substring(2, dataIn.length()); 
        Goc_quay = dataInS.toInt();
      }
      if ( dataIn == "PAUSE") break;
    }
    
    int runn = 0;

    // Bước 1: Bắn cảm biến để phát hiện vật
    distance = 0;
    distance = sensor.readRangeContinuousMillimeters();
    while(distance > 350)
      {
        if (Bluetooth.available() > 0) 
        { 
          dataIn = Bluetooth.readString();
          if (dataIn.startsWith("s8"))
            {
              String dataInS = dataIn.substring(2, dataIn.length()); 
              Goc_quay = dataInS.toInt();
            }
          if ( dataIn == "PAUSE") { runn = 1; break;} 
        }
        distance = sensor.readRangeContinuousMillimeters();  
      }
  
    if(runn == 0)
      {
        delay(2000);
        // Bước 2: Về trạng thái sẵn sàng
        for(int i=1; i<=5; ++i)
          {
            for(int j=1; j<=5; ++j) {servo3PPos++; servo03.write(servo3PPos); delay(1);}
            delay(5);
            for(int j=1; j<=28; ++j) {servo5PPos++; servo05.write(servo5PPos); delay(1);}
            delay(10);
            for(int j=1; j<=16; ++j) {servo2PPos--; servo02.write(servo2PPos); delay(1);}
            delay(5);
          }
        delay(500);
        servo06.write(85);
        delay(500);
        /// Bước 3: Đi gắp
        for(int i=1; i<=5; ++i)
          {
            for(int j=1; j<=7; ++j) {servo3PPos--; servo03.write(servo3PPos); delay(5);}
            for(int j=1; j<=4; ++j) {servo5PPos--; servo05.write(servo5PPos); delay(5);}
            for(int j=1; j<=4; ++j) {servo2PPos--; servo02.write(servo2PPos); delay(5);}
          }
        delay(1000);
        servo06.write(15);
        delay(1000);
        // Bước 4: Nhấc vật lên, đưa vật lên bằng servo 3, 5 
        int tt = 15;
        for(int i=1; i<=tt; ++i) 
          {
            servo5PPos++; servo05.write(servo5PPos); delay(15);
            servo3PPos--; servo03.write(servo3PPos); delay(15);
          }
        delay(1500);
        
        // Bước 5: Quay servo 01 đưa đến góc đã setup
        int xx; 
        if(servo1PPos < Goc_quay) 
          {
            xx = Goc_quay - servo1PPos;
            for(int i=1; i<=xx; ++i) {servo1PPos++; servo01.write(servo1PPos); delay(15);}
          }
        if(servo1PPos > Goc_quay) 
          {
            xx = servo1PPos - Goc_quay;
            for(int i=1; i<=xx; ++i) {servo1PPos--; servo01.write(servo1PPos); delay(15);}
          }

        // Bước 6: Đặt vật xuống, nhả tay gắp
        for(int i=1; i<=tt; ++i) 
          {
            servo5PPos--; servo05.write(servo5PPos); delay(15);
            servo3PPos++; servo03.write(servo3PPos); delay(15);
          }
        delay(1000);
        servo06.write(80);
        delay(1000);

        // Bước 7: Về lại vị trí đã setup ban đầu
        for(int i=1; i<=5; ++i)
          {
            for(int j=1; j<=7; ++j) {servo3PPos++; servo03.write(servo3PPos); delay(5);}
            for(int j=1; j<=4; ++j) {servo5PPos++; servo05.write(servo5PPos); delay(5);}
            for(int j=1; j<=4; ++j) {servo2PPos++; servo02.write(servo2PPos); delay(5);}
          }
        delay(1000);
        for(int i=1; i<=5; ++i)
          {
            for(int j=1; j<=5; ++j) {servo3PPos--; servo03.write(servo3PPos); delay(1);}
            delay(5);
            for(int j=1; j<=28; ++j) {servo5PPos--; servo05.write(servo5PPos); delay(1);}
            delay(10);
            for(int j=1; j<=16; ++j) {servo2PPos++; servo02.write(servo2PPos); delay(1);}
            delay(5);
          }
        delay(1000);
        if(servo1PPos > 90) 
          {
            xx = servo1PPos - 90;
            for(int i=1; i<=xx; ++i) {servo1PPos--; servo01.write(servo1PPos); delay(10);}
          }
        if(servo1PPos < 90)
          {
            xx = 90 - servo1PPos;
            for(int i=1; i<=xx; ++i) {servo1PPos++; servo01.write(servo1PPos); delay(10);}
          }
      }
  }
}
