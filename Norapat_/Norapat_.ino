#include <my_rp2040.h>


unsigned long lasts_time_servo=millis();
int servo_down = 40;
int servo_up = 110;
void setup() 
  {    
      Serial.begin(9600);
      
      pos_motor_cal(10, 10, 10);
      to_set_motor_LR(100, 100);          //ตั้งค่ามอเตอร์ให้หุ่นยนต์วิ่งตรง
      
      to_slow_motor(20, 20);           // ตั้งค่า ความเร็วมอเตอร์เวลาเข้าแยก
      to_turn_center_l(-100, 100 );   // ตั้งค่ามอเตอร์หมุนซ้ายขวา ตอนเลี้ยวซ้ายแบบ center
      to_turn_center_r(100, -100 );   // ตั้งค่ามอเตอร์หมุนซ้ายขวา ตอนเลี้ยวขาวแบบ center
      to_turn_front_l(-12, 100);     // ตั้งค่ามอเตอร์หมุนซ้ายขวา ตอนเลี้ยวซ้ายแบบ เซนเซอร์หน้า  เดินหน้า
      to_turn_front_r(100, -12);     // ตั้งค่ามอเตอร์หมุนซ้ายขวา ตอนเลี้ยวขวาแบบ เซนเซอร์หน้า  เดินหน้า
      to_speed_turn_fl(100, 80, 30);  // ค่าพุ่งตัวออกหลังจากการเลี้ยว มีผลต่อตัวแปรสุดท้ายของคำสั่งเลี้ยว ถ้าเป็น 0
      to_speed_turn_fr(80, 100, 30);  // ค่าพุ่งตัวออกหลังจากการเลี้ยว มีผลต่อตัวแปรสุดท้ายของคำสั่งเลี้ยว ถ้าเป็น 0
      
      to_brake_fc(2, 15);            // ตั้งค่าในการหยุดมอเตอร์ก่อนหมุนซ้ายขวา to_brake_fc(...f..., ....c...); 
      to_brake_bc(2,20);
      to_delay_f(3);//////5                 // ระยะทางในการข้ามเส้นเวลาหมุนตัวแบบ f
    
      kp_sl(0.3, 0.3);  // kp และ ki ในฟังก์ เดินตามเส้นแบบช้า
      kd_fw(0.8);
      kd_bw(0.8);

      sensor_set();
      //setup_tcs();
     
      //servo_down_open() ;    
      //servo_down_close() ;  
      //servo_up_close() ; 
      servo(8,110 );       //แขนยก
      //servo(8,40 );       //แขนลง
      servo(23,100);

      
      ///////////////
      sw();
      box_1();
      box_2();
      box_3();
      box_4();
      box_5();
      box_6();
      End();

  }

void loop() 
  {  
 

  }