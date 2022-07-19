#define BTN_RESET 12
#define BTN_BLUE 2
#define LED_BLUE 5
#define BTN_GREEN 3
#define LED_GREEN 9

volatile int state = HIGH;

void setup() {
  pinMode(BTN_RESET, INPUT_PULLUP);
  pinMode(BTN_BLUE, INPUT_PULLUP);
  pinMode(BTN_GREEN, INPUT_PULLUP);

  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(BTN_GREEN), setGreen, LOW);
  attachInterrupt(digitalPinToInterrupt(BTN_BLUE), setBlue, LOW);

  // Blink to show readiness
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(LED_BLUE, state);
    digitalWrite(LED_GREEN, state);
    delay(100);
    state = !state;
  }

  state = -1;
}

void loop() {
  if( state != -1 )
  {
    digitalWrite(state, HIGH);
  }
  
  if( digitalRead(BTN_RESET) == LOW)
  {
    state = -1;
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, LOW);
  }
}

void setGreen() { if ( state == -1 ) state = LED_GREEN; }
void setBlue() { if ( state == -1 ) state = LED_BLUE; }
