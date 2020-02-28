#ifndef Simple_GPIO
#define Simple_GPIO
#endif

void begin_Output (char port, int pin_number); 				/*Function to declare pin as an output*/
void begin_Input (char port, int pin_number);				/*Function to declare pin as an input*/
void set_Pin (char port, int pin , int state);		/*Function to set pin state Low/ High as output*/
int read_Pin (char port, int pin_number);					/*Function to read pin state and return 0 for low or 1 for high*/
