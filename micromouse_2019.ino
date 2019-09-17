int cellDistance = 16;
int baseSpeed = 128; // Base PWM value
int encoderCountStraight = 400; // TODO: take the count for 8cm

// Right motor
#define PWMRight PA3
#define right1 PA4
#define right2 PA5
#define encRightA PA6 // Interrupt pin (OUTA of encoder)
#define encRightB PA7
volatile int rightCount = 0;
int rightBase = 60;


// Left motor
#define PWMLeft PA8
#define left1 PA9
#define left2 PA10
#define encLeftA PB0 // Interrupt pin (OUTA of encoder)
#define encLeftB PB1
volatile int leftCount = 0;
int leftBase = 60;

// Front,Right,Left sensors
const int sensorFront = PA0;
const int sensorRight = PA1;
const int sensorLeft = PA2;

int front = 0;
int right = 0;
int left = 0;
int rightDis = 0;
int leftDis = 0;

// PID
float kp = 0, kd = 0, ki = 0;
float integral = 0;
float previousPropotion = 0;

void setup() {  
  // Right Motor
  pinMode(encRightA, INPUT);
  pinMode(encRightB, INPUT);
  pinMode(PWMRight, OUTPUT);
  pinMode(right1, OUTPUT);
  pinMode(right2, OUTPUT);
  digitalWrite(right1, HIGH);
  digitalWrite(right2, LOW);


  // Left Motor
  pinMode(encLeftA, INPUT);
  pinMode(encLeftB, INPUT);
  pinMode(PWMLeft, OUTPUT);
  pinMode(left1, OUTPUT);
  pinMode(left2, OUTPUT);
  //  digitalWrite(left1, LOW);
  //  digitalWrite(left2, LOW);

  // Initialize hardware interrupts
//  attachInterrupt(digitalPinToInterrupt(encRightA), rightTurns, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encLeftA), leftTurns, CHANGE);
  
  Serial.begin(9600);

}

//========================================MAIN========================================//
void loop() {

  //  initialRun();
  //  getCellDistance();


  // Update front, right, left by reading sensors
//    readSensors();
//     Serial.println(analogRead(sensorFront));
    encoderForward();
    delay(5000);
      int a = 0;
  while (a < 5000)
  {
    moveStraight();

  }
   
  // Update walls

  // Floodfill

  //  // Travel to cell center
  //  while (cellDistance == 0) {
  //    moveStraight();
  //  }
  //
  //  // Stop the robot
  //  stopRobot();

//  Forward_encoder_Right();

}

//===========================================ENCODERS==========================================//

//------Forward------------------------------
void encoderForward() {
////  delay(1000);
//  Serial.println("dsdd");
  leftCount = 0;
  while (leftCount < encoderCountStraight) {
    moving(3,baseSpeed); // move forward
      Serial.println(leftCount);
  }
  moving(5,0); // stop
  rightCount = 0;
}

//-----RightNinety---------------------------
void turnRightNinety()
{
  rightCount = 0;
  leftCount = 0;

  while (leftCount < 440 || rightCount > -440)
  {
    if (leftCount < 440)
    {
      digitalWrite(left1, LOW);
      digitalWrite(left2, HIGH);
      analogWrite(PWMLeft, leftBase);

    }
    else
    {
      digitalWrite(left1, HIGH);
      digitalWrite(left2, HIGH);
      digitalWrite(PWMLeft, HIGH);

    }

    if (rightCount > -440)
    {
      digitalWrite(right1, HIGH);
      digitalWrite(right2, LOW);
      analogWrite(PWMRight, rightBase);
    }
    else
    {
      digitalWrite(right1, HIGH);
      digitalWrite(right2, HIGH);
      digitalWrite(PWMRight, HIGH);
    }
  }
  moving(5,0); // stop
  rightCount = 0;
  leftCount = 0;
}

//-----LeftNinety---------------------------
void turnLeftNinety()
{
  rightCount = 0;
  leftCount = 0;
  while (rightCount < 450 || leftCount > -450 )
  {
    if (rightCount < 450)
    {
      digitalWrite(right1, LOW);
      digitalWrite(right2, HIGH);
      analogWrite(PWMRight, rightBase);
    }
    else
    {
      digitalWrite(right1, HIGH);
      digitalWrite(right2, HIGH);  
      digitalWrite(PWMRight, HIGH);
    }
    
    if (leftCount > -450)
    {
      digitalWrite(left1, HIGH);
      digitalWrite(left2, LOW);
      analogWrite(PWMLeft, leftBase);
    }
    else
    {
      digitalWrite(left1, HIGH);
      digitalWrite(left2, HIGH); 
      digitalWrite(PWMLeft, HIGH);

    }
  
  }
  moving(5,0); // stop
  rightCount = 0;
  leftCount = 0;
}
//-----------------TEST----------------
void Forward_encoder_Right()
{
  int a = 0;
  while (a < 5000)
  {
    moveStraight();
    a = a + 1;
        Serial.println(digitalRead(encRightB));
    //        Serial.println(digitalRead(encRightB));
    //        Serial.println("------");

  }
  stopRobot();
  Serial.println(rightCount);

    rightCount = 0;
}

void rightTurns()
{
    Serial.println("TEST");
  if (digitalRead(encRightA) == HIGH && digitalRead(encRightB) == HIGH)
  {
    rightCount++;
  }
  if (digitalRead(encRightA) == HIGH && digitalRead(encRightB) == LOW)
  {
    rightCount--;
  }
}

void leftTurns()
{
  Serial.println("TEST");
  if (digitalRead(encLeftA) == HIGH && digitalRead(encLeftB) == HIGH)
  {
    leftCount++;
  }
  if (digitalRead(encLeftA) == HIGH && digitalRead(encLeftB) == LOW)
  {
    leftCount--;
  }
}

//===========================================SENSORS==========================================//

void readSensors() {
  //  READ SENSORS FRONT, RIGHT, LEFT
 
  float sensorFrontVolt = (float(analogRead(sensorFront)) / 4096) * 5;
  int distFront = 13 * pow(sensorFrontVolt, -1);

  float sensorRightVolt = (float(analogRead(sensorRight)) / 4096) * 5;
  int distRight = 13 * pow(sensorRightVolt, -1);

  float sensorLeftVolt = (float(analogRead(sensorLeft)) / 4096) * 5;
  int distLeft = 13 * pow(sensorLeftVolt, -1);

  if (distFront < 5) {
    front = 1;
  } else {
    front = 0;
  }

  if (distRight < 5) {
    right = 1;
  } else {
    right = 0;
  }

  if (distLeft < 5) {
    left = 1;
  } else {
    left = 0;
  }

  Serial.println(distFront);
  Serial.println(distRight);
  Serial.println(distLeft);
  Serial.println("-----------------");
}

//===========================================MOVE==========================================//

void moveStraight() {
  analogWrite(PWMRight, 128);
  digitalWrite(right1, HIGH);
  digitalWrite(right2, LOW);

  analogWrite(PWMLeft, 128);
  digitalWrite(left1, HIGH);
  digitalWrite(left2, LOW);
}

void stopRobot() {
  digitalWrite(right1, LOW);
  digitalWrite(right2, LOW);

  digitalWrite(left1, LOW);
  digitalWrite(left2, LOW);
}

//===========================================TURN==========================================//

void turnRight() {
  analogWrite(PWMRight, 128);
  digitalWrite(right1, HIGH);
  digitalWrite(right2, LOW);

  analogWrite(PWMLeft, 128);
  digitalWrite(left1, HIGH);
  digitalWrite(left2, LOW);
}

void turnLeft() {
  analogWrite(PWMRight, 128);
  digitalWrite(right1, LOW);
  digitalWrite(right2, HIGH);

  analogWrite(PWMLeft, 128);
  digitalWrite(left1, HIGH);
  digitalWrite(left2, LOW);
}

//===========================================PID=========================================//

int errorCal() {
  rightDis = 0;
  leftDis = 0;
  readSensors();

  if (leftDis > 16) {
    leftDis = 16;
  }
  if (rightDis > 16) {
    rightDis = 16;
  }
  // TODO:
  return 9 * (rightDis - leftDis);
  delay(10);
}

void PIDControl() {
  int PIDLeft;
  int PIDRight;
  int motorVal;
  int proportion = errorCal();

  int derivative = proportion - previousPropotion;
  integral = integral + proportion;
  previousPropotion = proportion;

  motorVal = proportion * kp + derivative * kd + integral * ki;
  //Serial.println(motor_val);
  if (motorVal >= 0) {
    if ((baseSpeed + motorVal) >= 255) {
      PIDLeft = 255;
    } else {
      PIDLeft = baseSpeed + motorVal;
    }

    if ((baseSpeed - motorVal) <= -255) {
      PIDRight = -255;
    } else {
      PIDRight = baseSpeed - motorVal;
    }

  } else if (motorVal < 0) {

    if ((baseSpeed - motorVal) >= 255) {
      PIDRight = 255;
    } else {
      PIDRight = baseSpeed - motorVal;
    }

    if ((baseSpeed + motorVal) <= -255) {
      PIDLeft = -255;
    } else {
      PIDLeft = baseSpeed + motorVal;
    }
  }
  motorDrive('L', PIDLeft);
  motorDrive('R', PIDRight);
  delay(25);
}

//===========================================MOVENEW==========================================//

void moving(int n, int speedVal) {
  switch (n) {
    case 1://forward
      motorDrive('L', speedVal+20);
      motorDrive('R',  speedVal);
      break;
    case 2://turn_Left
      motorDrive('L', -speedVal);
      motorDrive('R', speedVal);
      break;
    case 3://turn_right
      motorDrive('L', speedVal);
      motorDrive('R', -speedVal);
      break;
    case 4://backward
      motorDrive('L',  -speedVal);
      motorDrive('R', -speedVal);
      break;
    case 5://stop
      motorDrive('L', 0);
      motorDrive('R', 0);
      break;
  }
}
void motorDrive(char motor, int spd) {
  int spdPin;
  int dir1;
  int dir2;

  if (motor == 'R') {
    spdPin = PWMRight;
    dir1 = right1;
    dir2 = right2;
  }
  else if (motor == 'L') {
    spdPin = PWMLeft;
    dir1 = left1; 
    dir2 = left2;
  }
  else {
    return;
  }

  if (spd == 0) {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
  }
  else if (spd < 0) {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
  }
  else if (spd > 0) {
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
  }
  if (spd <= 0) {
    spd = -spd;
  } else {
    spd = spd;
  }
  analogWrite(spdPin, spd);
}

