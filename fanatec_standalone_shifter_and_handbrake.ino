//#define DEBUG

#define PIN_X 1
#define PIN_Y 2
#define PIN_Z 0

#define GEAR_1 1
#define GEAR_2 2
#define GEAR_3 3
#define GEAR_4 4
#define GEAR_5 5
#define GEAR_6 6
#define GEAR_7 7
#define GEAR_REVERSE 8

void setup() {
  #ifdef DEBUG
  Serial.begin(9600);
  #endif  

  Joystick.useManualSend(true);
}


int get_current_gear() {
  int x = analogRead(PIN_X);
  int y = analogRead(PIN_Y);

  if (y > 1000) {
    if (x < 100) {
      return GEAR_7;
    }    
    if (x < 300) {
      return GEAR_5;
    }

    if (x < 500) {
      return GEAR_3;
    }

    if (x < 700) {
      return GEAR_1;
    }

    if (x < 900) {
      // reverse
      return GEAR_REVERSE;
    }

  }

  if (y < 65) {
    if (x < 300) {
      return GEAR_6;
    }  
    
    if (x < 500) {
      return GEAR_4;
    }
      
    if (x < 700) {
      return GEAR_2;
    }
  }

  return 0;
}

void debug() {
  Serial.print("x: ");
  Serial.print(analogRead(PIN_X));
  Serial.print(" y: ");
  Serial.print(analogRead(PIN_Y));
  Serial.print(" z: ");
  Serial.println(analogRead(PIN_Z));
}

void loop() {
  int gear = get_current_gear();
  
  #ifdef DEBUG
  debug();
  #endif
  
  if (gear != 0) {
    Joystick.button(gear, 1);
    Joystick.send_now();
    
    delay(100);
    
    Joystick.button(gear, 0);
    Joystick.send_now();
    
    while (get_current_gear() != 0) {
      delay(5);
    }
  }      
  
  delay(5);
}

