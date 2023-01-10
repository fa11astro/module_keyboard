#include <VirtualWire.h>
#include <VirtualWire_Config.h>

byte buf[VW_MAX_MESSAGE_LEN];
byte buflen = VW_MAX_MESSAGE_LEN;
const int receive_pin = 3;
void setup()
{
vw_set_rx_pin(receive_pin);
//vw_set_ptt_inverted(true);
Serial.begin(9600);
Serial.println("Device is ready");
vw_setup(2000);
vw_rx_start();
}
void loop()
{
  if (vw_get_message(buf, &buflen)) // Non-blocking
    {
        Serial.print("Got: ");
        
        for (int i = 0; i < buflen; i++)
        {
            char c = buf[i];
            Serial.print(c);
        }
        Serial.println();
    }
}
