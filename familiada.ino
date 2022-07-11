#define BTN_RESET 12
#define BTN_BLUE 6
#define LED_BLUE 7
#define BTN_GREEN 8
#define LED_GREEN 9

int currentColor = -1;

void setup() {
  pinMode(BTN_RESET, INPUT_PULLUP);
  pinMode(BTN_BLUE, INPUT_PULLUP);
  pinMode(BTN_GREEN, INPUT_PULLUP);

  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
      digitalWrite(LED_GREEN, HIGH);
          digitalWrite(LED_BLUE, HIGH);
}

void loop() {
  if( digitalRead(BTN_BLUE) == LOW and currentColor == -1 )
  {
    currentColor = BTN_BLUE;
    digitalWrite(LED_BLUE, HIGH);
  }

  if( digitalRead(BTN_GREEN) == LOW and currentColor == -1 )
  {
    currentColor = BTN_GREEN;
    digitalWrite(LED_GREEN, HIGH);
  }

  if( digitalRead(BTN_RESET) == LOW )
  {
    currentColor = -1;
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, LOW);
  }

}

