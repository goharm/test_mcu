#include <DynamixelWorkbench.h>


DynamixelWorkbench dxl_wb; //인스턴스화


void setup() {
  // put your setup code here, to run once:
  dxl_wb.begin("", 1000000);
  
  
  dxl_wb.ping(1); //살았나? 죽었나? 확인
  dxl_wb.ping(2); //원래는 방어코드를 넣어 주어야 함

  
  dxl_wb.jointMode(1); //살았다는 전재하에 
  dxl_wb.jointMode(2);
  
  Serial.begin(115200);
}

void forword(){
  dxl_wb.goalPosition(1,2000);
  dxl_wb.goalPosition(2,2000);

  delay(10);
}

void b_stop(){
  dxl_wb.goalPosition(1,0);
  dxl_wb.goalPosition(2,0);

  delay(10);
}

String control;

void loop() {
  // put your main code here, to run repeatedly:
  while(!Serial.available()){
    control = Serial.readString();
    // Serial.write(control);
    if(control == "s"){
      Serial.println("stop");
      b_stop();
    } else if(control == "f"){
      Serial.println("forward");
      forword();
    }else{
      
    }
  
  }
  
  


  
  

  dxl_wb.goalPosition(1,2000);
  dxl_wb.goalPosition(2,2000);

  delay(2000);
}
