#include <SPI.h>
#include <SD.h>
File myFile; // สร้างออฟเจก File สำหรับจัดการข้อมูล
const int chipSelect = D1 ; // 4 6

// variable count time

double count1 = 1 ;

void setup()
{
  
Serial.begin(9600);
  // while (!Serial) {
  // ; // รอจนกระทั่งเชื่อมต่อกับ Serial port แล้ว สำหรับ Arduino Leonardo เท่านั้น
  // }


  // end loop setup
}

void loop()
{



    
Serial.print("Initializing SD card...");
pinMode(SS, OUTPUT);   /// pin = 11 , 12, 13 
if (!SD.begin(chipSelect)) {
Serial.println("initialization failed!");
return;
}
Serial.println("initialization done.");

myFile = SD.open("testth1.txt", FILE_WRITE); // เปิดไฟล์ที่ชื่อ test.txt เพื่อเขียนข้อมูล โหมด FILE_WRITE


// ถ้าเปิดไฟล์สำเร็จ ให้เขียนข้อมูลเพิ่มลงไป
if (myFile) {
Serial.print("Writing to testth1.txt...");
myFile.print("วันที่ 1 พ.ย. 2567 บรรทัดที่ ") ; // สั่งให้เขียนข้อมูล
myFile.print(count1) ;
myFile.print("\n") ;

// serial.print 
Serial.println("วันที่ 1 พ.ย. 2567 บรรทัดที่ ");
Serial.println(count1);
Serial.print("\n");

myFile.close(); // ปิดไฟล์
Serial.println("done.");

} else {
// ถ้าเปิดไฟลืไม่สำเร็จ ให้แสดง error 
Serial.println("error opening writing testth1.txt");
}

delay(10) ;

  // add count1 and temp1
count1 = count1 + 1 ;

if ( count1 == 100000 ) {
  Serial.println(" it is finished. ");
  Serial.print("\n");
  delay(100000) ;
}

  // end loop void loop 
}


