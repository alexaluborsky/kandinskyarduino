String letter;

const int buzzer = 9;  //buzzer to arduino pin 9
const int BLUE1 = 8;
const int BLUE2 = 11;
const int YELLOW1 = 10;
const int YELLOW2 = 7;
const int RED1 = 13;
const int RED2 = 12;
const int WHITE = 6;

void turnOffAll() {
  digitalWrite(RED1, LOW);
  digitalWrite(RED2, LOW);
  digitalWrite(BLUE2, LOW);
  digitalWrite(YELLOW1, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(BLUE1, LOW);
  digitalWrite(YELLOW2, LOW);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Starting receiver");
  Serial.setTimeout(1);
  //set pins to OUTPUT
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(buzzer, OUTPUT);  // Set buzzer - pin 9 as an output
  tone(buzzer, 1000);       // Send 1KHz sound signal...
}



//The loop function runs from the top down and repeats itself until you upload new        //code or power down your Arduino
void loop() {
  if (Serial.available() > 0) {
    // read the incoming string:
    String letter = Serial.readString();

    // make the letter lower case
    String letter = toLowerCase(letter);

    // prints the received data
    Serial.print("I received: ");
    Serial.println(letter);

    // a switch case statement is a little bit easier to read and follow...
    switch (letter) {
      case "a":
        //Turn pin 13 HIGH (ON). This will represent the first red LED.
        digitalWrite(RED1, HIGH);
        //Turn pin 12 HIGH (ON). This will represent the second red LED.
        digitalWrite(RED2, HIGH);
        //Delay 1s and then blink the blue led. This will be pin 11.
        delay(500);
        digitalWrite(BLUE1, HIGH);
        delay(500);
        turnOffAll();
        break;

      case "b":
        //Turn pin 10 HIGH (ON). This will represent the yellow LED.
        digitalWrite(YELLOW1, HIGH);
        //Turn pin 9 HIGH (ON). Play tone.
        digitalWrite(buzzer, HIGH);
        //Delay then turn off yellow LED.
        delay(500);
        turnOffAll();
        break;

      case "c":
        //Turn pin 9 HIGH (ON). Play tone.
        digitalWrite(buzzer, HIGH);
        delay(500);
        turnOffAll();
        break;

      case "d":
        //Turn pin 10 HIGH (ON). This will represent the yellow LED.
        digitalWrite(YELLOW1, HIGH);
        delay(1000);
        digitalWrite(YELLOW1, LOW);
        //Turn pin 9 HIGH (ON). Play tone.
        digitalWrite(buzzer, HIGH);
        delay(500);
        turnOffAll();
        break;

      case "e":
        //Turn pin 11 and 8 at the same time HIGH (ON). This will represent two blue LEDs.
        digitalWrite(BLUE1, HIGH);
        digitalWrite(BLUE2, HIGH);
        //Short delay then turn off blue LEDs.
        delay(500);
        digitalWrite(BLUE1, LOW);
        digitalWrite(BLUE2, LOW);
        delay(1000);
        turnOffAll();
        break;

      case "f":
        //Turn pin 11 and 8 at the same time HIGH (ON). This will represent two blue LEDs.
        digitalWrite(BLUE1, HIGH);
        digitalWrite(BLUE2, HIGH);
        //Short delay then turn off blue LEDs.
        delay(1000);
        turnOffAll();
        break;

      case "g":
        //Turn buzzer on (pin 9) and at the same time the blue LED.
        digitalWrite(buzzer, HIGH);
        digitalWrite(BLUE2, HIGH);
        delay(1000);
        turnOffAll();
        digitalWrite(RED1, HIGH);
        break;

      case "h":
        //Turn yellows on first, then short blue LED.
        digitalWrite(YELLOW1, HIGH);
        digitalWrite(YELLOW2, HIGH);
        delay(500);
        digitalWrite(BLUE2, HIGH);
        delay(1000);
        turnOffAll();
        break;

      case "i":
        //Turn 2 blues and one yellow LED on all at once
        digitalWrite(BLUE1, HIGH);
        digitalWrite(BLUE2, HIGH);
        digitalWrite(YELLOW1, HIGH);
        delay(1000);
        turnOffAll();
        break;

      case "j":
        //Turn on blue blink + same tone as "D"
        digitalWrite(BLUE1, HIGH);
        delay(500);
        turnOffAll();
        break;

      case "k":
        //2 red blinks (short) at once, one short yellow afterwards
        digitalWrite(RED1, HIGH);
        digitalWrite(RED2, HIGH);
        delay(500);
        digitalWrite(YELLOW1, HIGH);
        turnOffAll();
        break;

      case "l":
        //NEUTRAL - One white LED, "medium" length + the note that an orchestra tunes to
        digitalWrite(WHITE, HIGH);
        delay(1000);
        turnOffAll();
        break;

      case "m":
        //Blink both red LEDs at once twice
        digitalWrite(RED1, HIGH);
        digitalWrite(RED2, HIGH);
        delay(250);
        turnOffAll();
        digitalWrite(RED1, HIGH);
        digitalWrite(RED2, HIGH);
        delay(250);
        turnOffAll();
        break;

      case "n":
        //Turn red, then yellow, then red, fast blinks
        digitalWrite(RED1, HIGH);
        delay(250);
        digitalWrite(RED1, LOW);
        digitalWrite(YELLOW1, HIGH);
        delay(250);
        digitalWrite(RED2, HIGH);
        delay(250);
        turnOffAll();
        break;

      case "o":
        //Find a tone, long, associated with wholeness
        break;

      case "p":
        //One long yellow blink and one "D" tone
        digitalWrite(YELLOW1, HIGH);
        delay(1000);
        digitalWrite(buzzer, HIGH);
        turnOffAll();
        break;

      case "q":
        // O tone and red blink
        digitalWrite(buzzer, HIGH);
        digitalWrite(RED1, HIGH);
        delay(250);
        digitalWrite(RED1, LOW);
        delay(250);
        turnOffAll();
        break;

      case "r":
        //D tone first, then red and yellow blinks at once
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(RED2, HIGH);
        digitalWrite(YELLOW1, HIGH);
        delay(500);
        turnOffAll();
        break;

      case "s":
        //Only tone -- 2 tones -- like a wave
        digitalWrite(buzzer, HIGH);
        break;

      case "t":
        //Neutral, so use white LED
        digitalWrite(WHITE, HIGH);
        delay(250);
        digitalWrite(WHITE, LOW);
        digitalWrite(WHITE, HIGH);
        delay(250);
        digitalWrite(WHITE, LOW);
        break;

      case "u":
        digitalWrite(buzzer, HIGH);
        delay(250);
        digitalWrite(buzzer, HIGH);
        delay(250);
        turnOffAll();
        break;

      case "v":
        digitalWrite(RED1, HIGH);
        delay(250);
        digitalWrite(RED1, LOW);
        digitalWrite(RED2, HIGH);
        delay(250);
        turnOffAll();
        break;

      case "w":
        digitalWrite(RED1, HIGH);
        digitalWrite(RED2, HIGH);
        delay(250);
        turnOffAll();
        break;

      default:
        digitalWrite(RED1, HIGH);
        digitalWrite(RED2, HIGH);
        digitalWrite(BLUE2, HIGH);
        digitalWrite(YELLOW1, HIGH);
        digitalWrite(buzzer, HIGH);
        digitalWrite(BLUE1, HIGH);
        digitalWrite(YELLOW2, HIGH);
        delay(5000);
        turnOffAll();
    }
  }
}