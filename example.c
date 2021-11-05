//Zachary Keffaber / zachary7829, 2021/11/3, SeaJson 

#include <stdio.h>
#include <string.h>
#include "seajson.h"

int main (void) {
  char test[] = "{\"Test0\":\"Testinggg\",\"Test1\":\"Testto\",\"Test2\":{\"Test20\":\"Testta\",\"Test21\":\"Testte\"},\"Test3\":5,\"Test4\":true}";
  char * testingstring = getstring("Test2.Test20", test);
  printf("\n%s",testingstring);
}
