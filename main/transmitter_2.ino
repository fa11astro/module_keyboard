#include <VirtualWire.h>
#include <VirtualWire_Config.h>

#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad
const int tx_pin = 13;
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  Serial.begin(9600);
  vw_set_tx_pin(tx_pin);
  //vw_set_ptt_inverted(true); 
  vw_setup(2000);
  while (!Serial) { // needed to keep leonardo/micro from starting too fast!
    delay(10);
  }
}
void loop() {
  char customKey = customKeypad.getKey();
  Serial.print(customKey);
  if (customKey){
    char *msg = &customKey;
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); // Wait until the whole message is gone 
  }
}
