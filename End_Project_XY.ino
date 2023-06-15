/* 모터 정보 */
//모터 1 핀
int INX1=11;
int INX2=9;
int INX3=10;
int INX4=8;

//모터 2 핀
int INY1=7;
int INY2=5;
int INY3=6;
int INY4=4;

//모터 이동 정보 (1칸)
const int RotX = 20;
const int RotY = 22;

//모터 딜레이타임 (속도)
int delayTimeX = 3;
int delayTimeY = 3;
/* 모터 정보 */

//위치 정보
int bxp = 1; //before X Position
int byp = 1; //before Y Position
int yp[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

//자석 핀 정보 
int Electromagnet = 2;

void setup()
{
  Serial.begin(9600);
  
  pinMode(Electromagnet, OUTPUT);
  
  pinMode(INX1,OUTPUT);
  pinMode(INX2,OUTPUT);
  pinMode(INX3,OUTPUT);
  pinMode(INX4,OUTPUT);
  
  pinMode(INY1,OUTPUT);
  pinMode(INY2,OUTPUT);
  pinMode(INY3,OUTPUT);
  pinMode(INY4,OUTPUT);
}

void loop()
{
    if (Serial.available()) {
      int val = Serial.parseInt();
            
      if (val != 0 && val < 12) {
      Serial.print("input ");
      Serial.println(val);
      Serial.print("bxp ");
      Serial.println(bxp);
      int xgap = 0;
      int ygap = 0;
      xgap = val - bxp;

      /************* X좌표 이동 시작 ***************/
      stepMotorX(xgap);
      Serial.print("MoveX ");
      Serial.println(xgap);
      /************* X좌표 이동 앤드 ***************/
     
      bxp = val;
      Serial.print("xp ");
      Serial.println(bxp);
      delay(500);
      
      /*0000000000000 Y좌표 이동 시작 000000000000*/            
      ygap = yp[val] - byp;
      Serial.print("byp ");
      Serial.println(byp);     
      Serial.print("MoveY ");
      Serial.println(ygap);
      stepMotorY(ygap);
      /*0000000000000 Y좌표 이동 앤드 000000000000*/ 
      
      delay(1000);      
      digitalWrite(Electromagnet, HIGH); //    yp [val]에서 자석 켜기
      Serial.println("Magnet On");
      delay(2000);
      
      /*0000000000000 Y좌표 밀기 이동 시작 000000000000*/ 
      yp[val] = yp[val] + 1; 
      Serial.println("Yforward");
      
      stepMotorY(1);
      delay(1000);
      /*0000000000000 Y좌표 밀기 이동 앤드 000000000000*/ 
      
      Serial.println("Magnet off"); 
      digitalWrite(Electromagnet, LOW); 
      
      byp = yp[val];
      Serial.print("byp ");
      Serial.println(byp);
      Serial.println("----------------");
    }
  }
}

void stepMotorX(int steps) {
  if (steps > 0) {
    // 정방향 회전
    for (int i = 0; i < steps * RotX; i++) {
      digitalWrite(INX1, LOW);
      digitalWrite(INX2, HIGH);
      digitalWrite(INX3, HIGH);
      digitalWrite(INX4, LOW);
      delay(delayTimeX);

      digitalWrite(INX1, LOW);
      digitalWrite(INX2, HIGH);
      digitalWrite(INX3, LOW);
      digitalWrite(INX4, HIGH);
      delay(delayTimeX);

      digitalWrite(INX1, HIGH);
      digitalWrite(INX2, LOW);
      digitalWrite(INX3, LOW);
      digitalWrite(INX4, HIGH);
      delay(delayTimeX);

      digitalWrite(INX1, HIGH);
      digitalWrite(INX2, LOW);
      digitalWrite(INX3, HIGH);
      digitalWrite(INX4, LOW);
      delay(delayTimeX);
    }
    digitalWrite(INX1, LOW);
    digitalWrite(INX2, LOW);
    digitalWrite(INX3, LOW);
    digitalWrite(INX4, LOW);
  } else if (steps < 0) {
    // 역방향 회전
    for (int i = 0; i > steps * RotX; i--) {
      digitalWrite(INX1, HIGH);
      digitalWrite(INX2, LOW);
      digitalWrite(INX3, HIGH);
      digitalWrite(INX4, LOW);
      delay(delayTimeX);

      digitalWrite(INX1, HIGH);
      digitalWrite(INX2, LOW);
      digitalWrite(INX3, LOW);
      digitalWrite(INX4, HIGH);
      delay(delayTimeX);

      digitalWrite(INX2, HIGH);
      digitalWrite(INX3, LOW);
      digitalWrite(INX4, HIGH);
      delay(delayTimeX);

      digitalWrite(INX1, LOW);
      digitalWrite(INX2, HIGH);
      digitalWrite(INX3, HIGH);
      digitalWrite(INX4, LOW);
      delay(delayTimeX);
    }
    digitalWrite(INX1, LOW);
    digitalWrite(INX2, LOW);
    digitalWrite(INX3, LOW);
    digitalWrite(INX4, LOW);
  }
}

void stepMotorY(int steps) {
  if (steps > 0) {
    // 정방향 회전
    for (int i = 0; i < steps * RotY; i++) {
      digitalWrite(INY1, LOW);
      digitalWrite(INY2, HIGH);
      digitalWrite(INY3, HIGH);
      digitalWrite(INY4, LOW);
      delay(delayTimeY);

      digitalWrite(INY1, LOW);
      digitalWrite(INY2, HIGH);
      digitalWrite(INY3, LOW);
      digitalWrite(INY4, HIGH);
      delay(delayTimeY);

      digitalWrite(INY1, HIGH);
      digitalWrite(INY2, LOW);
      digitalWrite(INY3, LOW);
      digitalWrite(INY4, HIGH);
      delay(delayTimeY);

      digitalWrite(INY1, HIGH);
      digitalWrite(INY2, LOW);
      digitalWrite(INY3, HIGH);
      digitalWrite(INY4, LOW);
      delay(delayTimeY);
    }
    
    digitalWrite(INY1, LOW);
    digitalWrite(INY2, LOW);
    digitalWrite(INY3, LOW);
    digitalWrite(INY4, LOW);
  } else if (steps < 0) {
    // 역방향 회전
    for (int i = 0; i > steps * RotY; i--) {
      digitalWrite(INY1, HIGH);
      digitalWrite(INY2, LOW);
      digitalWrite(INY3, HIGH);
      digitalWrite(INY4, LOW);
      delay(delayTimeY);

      digitalWrite(INY1, HIGH);
      digitalWrite(INY2, LOW);
      digitalWrite(INY3, LOW);
      digitalWrite(INY4, HIGH);
      delay(delayTimeY);

      digitalWrite(INY1, LOW);
      digitalWrite(INY2, HIGH);
      digitalWrite(INY3, LOW);
      digitalWrite(INY4, HIGH);
      delay(delayTimeY);

      digitalWrite(INY1, LOW);
      digitalWrite(INY2, HIGH);
      digitalWrite(INY3, HIGH);
      digitalWrite(INY4, LOW);
      delay(delayTimeY);
    }
    
    digitalWrite(INY1, LOW);
    digitalWrite(INY2, LOW);
    digitalWrite(INY3, LOW);
    digitalWrite(INY4, LOW);
  }
}
