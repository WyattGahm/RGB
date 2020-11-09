# RGB
example code:
```C
#include "RGB.h"

RGB led = RGB(11,10,9);

void setup() {
  led.begin();
}
void loop() {
  delay(30);
  led.tick();
}
```
