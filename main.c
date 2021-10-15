//Zachary Keffaber / zachary7829, 2021/10/12, SeaJson 

#include <stdio.h>

int main(void) {
  int i, length = 0;
  char test[] = "{\"Test0\":\"Testinggg\",\"Test1\":\"Testto\"}";
  char dictkey[] = "Test0";
  int testt3 = 0;
  int keylength = sizeof dictkey - 1;
  int testt4 = 0;
  int testt5 = 0;
  int testt6 = 0;
  for (i = 0; test[i] != '\0' && test[i] != '\n'; i++) {
    length++;
  }
  for(int i = 0; i < length; ++i) {
    char testti1 = i;
    char testt1 = test[i];
    char testt2 = '\"';
    if (testt1 == testt2){
      //is "
      testt4 = 0;
      testt3 = 0;
      testt5 = 0;
      testt6 = 0;
      while (testt3 < keylength){
        testt3++;
        if (("%c",dictkey[testt3-1]) == ("%c",test[i+testt3])){
          testt4++;
        }
      }
      if (keylength == testt4){
        if (test[i + keylength + 2] == ':'){
          while (testt5 == 0){
            if (test[i + keylength + 4 + testt6] == '\"'){
              int beginkey = i + keylength + 4;
              int endkey = i + keylength + 4 + testt6;
              printf("Key is between %d and %d.\n",i + keylength + 4,i + keylength + 4 + testt6);
              testt5++;
            }
            testt6++;
          }

        }
      };
    } else {

    }
  }
  return 0;
}