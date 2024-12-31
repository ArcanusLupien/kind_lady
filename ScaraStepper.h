/*
This is a modification and replacement of the standard arduino Stepper Library
I am using a 4-pole stepper motor with a potentiometer coupled to it to relate the angle to a electrical signal

*/

// Erik's Personal Stepper Class
class ScaraStepper {
  private:
  //attachment pins
  int motor_pin_a, motor_pin_b, motor_pin_c, motor_pin_d;
  int pot_pin_a;

  //directional controls
  int reading; //potentiometer output
  int goal; // target angle
  int direction; //rotation direction (- cw, + ccw)
  int step_number; //Stepper sequence

void Step(){
    switch (this->step_number) {
      case 0:  // 1010
        digitalWrite(motor_pin_a, HIGH);
        digitalWrite(motor_pin_b, LOW);
        digitalWrite(motor_pin_c, HIGH);
        digitalWrite(motor_pin_d, LOW);
      break;
      case 1:  // 0110
        digitalWrite(motor_pin_a, LOW);
        digitalWrite(motor_pin_b, HIGH);
        digitalWrite(motor_pin_c, HIGH);
        digitalWrite(motor_pin_d, LOW);
      break;
      case 2:  //0101
        digitalWrite(motor_pin_a, LOW);
        digitalWrite(motor_pin_b, HIGH);
        digitalWrite(motor_pin_c, LOW);
        digitalWrite(motor_pin_d, HIGH);
      break;
      case 3:  //1001
        digitalWrite(motor_pin_a, HIGH);
        digitalWrite(motor_pin_b, LOW);
        digitalWrite(motor_pin_c, LOW);
        digitalWrite(motor_pin_d, HIGH);
      break;
    }
  }
  public:
  //Constructor
  ScaraStepper(int motor_pin_a, int motor_pin_b, int motor_pin_c, int motor_pin_d,int pot_pin_a){
    // variable set-up
    this->step_number = 0;
    this->direction = 0;

    // pin control
    this->motor_pin_a = motor_pin_a;
    this->motor_pin_b = motor_pin_b;
    this->motor_pin_c = motor_pin_c;
    this->motor_pin_d = motor_pin_d;
    this->pot_pin_a = pot_pin_a;

    // Pin Set-up
    pinMode(this->motor_pin_a, OUTPUT);
    pinMode(this->motor_pin_b, OUTPUT);
    pinMode(this->motor_pin_c, OUTPUT);
    pinMode(this->motor_pin_d, OUTPUT);
    pinMode(this->pot_pin_a, INPUT);
  }

  // Stepper Motion
  void setGoal(int goal){
    this->goal = goal;
  }

  // Updating and Moving the Stepper
  void Move(int wait){
    readAngle();
    this->direction = this->reading - this->goal;

    if (this->direction > 0) {
      this->step_number++;
    }
    else if (this->direction < 0){
      this->step_number--;
    }

    if (this->step_number == 4){
      this->step_number = 0;
    }
    else if (this->step_number == -1){
      this->step_number = 3;
    }

    Step();
    delay(wait);
  }

  // Turning off the Stepper
  void Off() {
    digitalWrite(motor_pin_a, LOW);
    digitalWrite(motor_pin_b, LOW);
    digitalWrite(motor_pin_c, LOW);
    digitalWrite(motor_pin_d, LOW);
  }

  //Read the current value
  void readAngle() {
    this->reading = analogRead(pot_pin_a);
    }
  int printAngle() {
    return this->reading;
  }
  int printGoal() {
    return this->goal;
  }
  int printStep() {
    return this->step_number;
  }
};
