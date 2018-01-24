const int A = 14;
const int B = 13;
const int C = 6;
const int D = 9;
const int E = 8;
const int F = 12;
const int G = 11;
const int dice1 = 5;
const int dice2 = 10;
const int button1 = 2;
const int button2 = 17;
const int segment[] = {A, B, C, D, E, F, G};

const bool digit[][7] = {
  {1, 0, 0, 1, 1, 1, 1},
  {0, 0, 1, 0, 0, 1, 0},
  {0, 0, 0, 0, 1, 1, 0},
  {1, 0, 0, 1, 1, 0, 0},
  {0, 1, 0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 0}
};
int delay1 = 0;
int delay2 = 0;
int value1 = 1;
int value2 = 1;


void setup() {
  Serial.begin(9600);
  pinMode (button1, INPUT_PULLUP);  //Set button as input (not required)
  pinMode (button2, OUTPUT);
  digitalWrite(button2, LOW);
  pinMode (dice1, OUTPUT);
  pinMode (dice2, OUTPUT);
  for (int i = 0; i < 7; i++) {
    pinMode (segment[i], OUTPUT); //Set all pins to output
  }
  for (int n = 0; n < 6; n++) {
    digitalWrite (segment[0], digit[n][0]);
    digitalWrite (segment[1], digit[n][1]);
    digitalWrite (segment[2], digit[n][2]);
    digitalWrite (segment[3], digit[n][3]);
    digitalWrite (segment[4], digit[n][4]);
    digitalWrite (segment[5], digit[n][5]);
    digitalWrite (segment[6], digit[n][6]);
    digitalWrite (dice1, HIGH);
    digitalWrite (dice2, HIGH);
    delay(50);
    digitalWrite (dice1, LOW);
    digitalWrite (dice2, LOW);
  }

}

void loop() {
  //Serial.println(value1);
  //sets dice1 button not pressed
  if (digitalRead(button1) == 0) {
    if (delay2 > 0) {
      value2 = ((delay2+random(1,6))%6) ;
      delay2 = 0;
    }
    delay1++;

  }
  //sets dice2
  if (digitalRead(button1) == 1) {
    if (delay1 > 0) {
      value1 = ((delay1+random(1,6)) % 6) ;
      delay1 = 0;
    }
    delay2++;

    //display values
//    Serial.print(" value2: ");
//    Serial.print(value2);
//    Serial.print(" value1: ");
//    Serial.println(value1);
    //delay between button presses
    displayDice(dice1, value1);
    //delay during button press
    displayDice(dice2, value2);
  }
}

void displayDice(int die, int n) {
 // Serial.println(n);
  digitalWrite (segment[0], digit[n][0]);
  digitalWrite (segment[1], digit[n][1]);
  digitalWrite (segment[2], digit[n][2]);
  digitalWrite (segment[3], digit[n][3]);
  digitalWrite (segment[4], digit[n][4]);
  digitalWrite (segment[5], digit[n][5]);
  digitalWrite (segment[6], digit[n][6]);
  digitalWrite (die, HIGH);
  delay(1);
  digitalWrite (die, LOW);
}
