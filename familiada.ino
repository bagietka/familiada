#define BTN_RESET 12
#define BTN_BLUE 6
#define LED_BLUE 7
#define BTN_YELLOW 8
#define LED_YELLOW 9

int currentColor = -1;

void setup() {
  pinMode(BTN_RESET, INPUT_PULLUP);
  pinMode(BTN_BLUE, INPUT_PULLUP);
  pinMode(BTN_YELLOW, INPUT_PULLUP);

  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
}

void loop() {
  if( digitalRead(BTN_BLUE) == LOW and currentColor == -1 )
  {
    currentColor = BTN_BLUE;
    digitalWrite(LED_BLUE, HIGH);
  }

  if( digitalRead(BTN_YELLOW) == LOW and currentColor == -1 )
  {
    currentColor = BTN_YELLOW;
    digitalWrite(LED_YELLOW, HIGH);
  }

  if( digitalRead(BTN_RESET) == LOW )
  {
    currentColor = -1;
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_BLUE, LOW);
  }

}

