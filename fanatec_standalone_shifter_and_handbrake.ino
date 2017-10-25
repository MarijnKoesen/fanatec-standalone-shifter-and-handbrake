// To compile select:
// - Tools -> Board -> Teensy LC
//
// Then:
// If you want to debug and enable serial communication:
// - Tools -> USB Type -> Serial / Keyboard / Mouse / Joystick
// else
// - Tools -> USB Type -> Keyboard / Mouse / Joystick

//#define DEBUG

#define PIN_SHIFTER_X 1
#define PIN_SHIFTER_Y 2
#define PIN_HANDBRAKE 3

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
  int x = analogRead(PIN_SHIFTER_X);
  int y = analogRead(PIN_SHIFTER_Y);

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

  if (y < 150) {
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
  Serial.print("shifter x: ");
  Serial.print(analogRead(PIN_SHIFTER_X));
  Serial.print(" shifter y: ");
  Serial.print(analogRead(PIN_SHIFTER_Y));
  Serial.print(" handbrake: ");
  Serial.println(analogRead(PIN_HANDBRAKE));
}

void poll_shifter() {
  int gear = get_current_gear();

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
}

void poll_handbrake() {
  int minBrakeValue = 60; // I got these values printing idle and max brake values
  int maxBrakeValue = 160;
  int rawBrake = analogRead(PIN_HANDBRAKE);
  
  if (rawBrake > maxBrakeValue) {
    rawBrake = maxBrakeValue;
  } else if (rawBrake < minBrakeValue) {
    rawBrake = minBrakeValue;
  }
  
  int normalizedBrake = (rawBrake - minBrakeValue) * (1024 / (maxBrakeValue-minBrakeValue));
  
  Joystick.X(normalizedBrake);
  Joystick.send_now();  
}

void loop() {
  #ifdef DEBUG
  debug();
  #endif

  pollShifter();
  pollHandbrake();

  delay(5);
}

