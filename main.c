//Zachary Keffaber / zachary7829, 2021/10/12, SeaJson 

#include <stdio.h>

int main(void) {
  int i, length = 0;
  char test[] = "{\"Test0\":\"Testinggg\",\"Test1\":\"Testto\",\"Test2\":{\"Test20\":\"Testta\",\"Test21\":\"Testte\"},\"Test3\":5,\"Test4\":true}";
  char dictkey[] = "Test2";
  int testt3, testt4, testt5, testt6, c = 0;
  int keylength = sizeof dictkey - 1;
  char returnkey[] = "";
  char sub[sizeof test + 1];
  int beginkey = 3;
  int endkey = 6;
  int tempvar, charindex = 0;
  int dotcount = 0;
  int dotcount2 = 0;
  int getdot = 2;
  int ignore = 0;
  int instring = 0;
  //Count number of dots in dictkey
  while (charindex < sizeof dictkey){
    if (dictkey[charindex] == '.'){
      dotcount++;
    } else {
      printf("%c",dictkey[charindex]);
    }
    charindex++;
  }
  charindex = 0;
  //Get part of dictkey after a dot
  while (tempvar == 0){
    if (dictkey[charindex] == '.'){
      dotcount2++;
    } else {
      if (dotcount2 == getdot) {
        printf("%c",dictkey[charindex]);
      }
    }
    charindex++;
    if (!(charindex < sizeof dictkey)) {
      tempvar++;
    }
  }
  printf("\n");
  for(int i = 0; i < sizeof test; ++i) {
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
          if (test[i + keylength + 3] == '\"'){
            instring = 1;
          }
          while (testt5 == 0){
            if (test[i + keylength + 4 + testt6] == '}' && ignore > 0){
              ignore = ignore - 1;
            } else if (test[i + keylength + 3 + testt6] == '{'){
              ignore++;
            } else if (((test[i + keylength + 4 + testt6] == '\"') && instring == 1 && ignore == 0) || ((test[i + keylength + 4 + testt6] == ',') && instring == 0 && ignore == 0) || ((test[i + keylength + 4 + testt6] == '}') && instring == 0 && ignore == 0)){
              if (ignore == 0){
                if (test[i + keylength + 3] == '\"'){
                  beginkey = i + keylength + 5;
                } else {
                  beginkey = i + keylength + 4;
                }
                endkey = i + keylength + 4 + testt6;
                printf("Key is between %d and %d.\n",beginkey,endkey);
                testt5++;
              }
            }
            testt6++;
          }
          int position = beginkey;
          int length = endkey - position + 1;
          while (c < length) {
            sub[c] = test[position+c-1];
            c++;
          }
          sub[c] = '\0';
          printf("Value of key is \"%s\"\n", sub); // '\"' to print "
        }
      };
    }
  }
  return 0;
}