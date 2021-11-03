//Zachary Keffaber / zachary7829, 2021/10/12, SeaJson 

#include <stdio.h>
#include <string.h>

int main(void) {
  int i = 0;
  char test[] = "{\"Test0\":\"Testinggg\",\"Test1\":\"Testto\",\"Test2\":{\"Test20\":\"Testta\",\"Test21\":\"Testte\"},\"Test3\":5,\"Test4\":true}";
  char dictkey[] = "Test2.Test20";
  if (!(dictkey[sizeof dictkey - 2] == '.')){
    strcat(dictkey,".");
  }
  int testt3, testt4, testt5, testt6, c = 0;
  int keylength = strlen(dictkey) - 1;
  char returnkey[] = "";
  char sub[sizeof test + 1];
  int beginkey = 3;
  int endkey = 6;
  int ignore = 0;
  int instring = 0;
  int tempvar = 0;
  int charindex = 0;
  int dotcount = 0;
  int dotcount2 = 0;
  int getdot = 0;
  int beginkeysegment = 0;
  int endkeysegment = 0;
  int keysegmentlength = 0;
  char dictkeysegment[sizeof dictkey];
  int c2 = 0;
  int position = 0;
  int length = 1;
  //Count number of dots in dictkey
  while (charindex < sizeof dictkey){
    if (dictkey[charindex] == '.'){
      dotcount++;
    } else {
    }
    charindex++;
  }
  getdot = dotcount - 1;
  charindex = 0;
  //Get part of dictkey after a dot
  while (tempvar == 0){
    if (dictkey[charindex] == '.'){
      dotcount2++;
    } else {
      if (dotcount2 == getdot) {
        keysegmentlength++;
        endkeysegment = charindex;
        printf("%c",dictkey[charindex]);
      }
    }
    charindex++;
    if (!(charindex < sizeof dictkey)) {
      tempvar++;
    }
  }printf("\n%d\n",endkeysegment);
  endkeysegment -= 0;
  keysegmentlength -= 0;
  beginkeysegment = (endkeysegment - keysegmentlength) + 1;
  int segmentposition = beginkeysegment + 1;
  while (c2 < keysegmentlength) {
   dictkeysegment[c2] = dictkey[segmentposition+c2-1];
   c2++;
  }
  printf("\n%d\n%d\n%s",beginkeysegment,keysegmentlength,dictkeysegment);
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
        if (("%c",dictkeysegment[testt3-1]) == ("%c",test[i+testt3])){
          testt4++;
        }
      }
      if (keysegmentlength == testt4){
        if (test[i + keysegmentlength + 2] == ':'){
          if (test[i + keysegmentlength + 3] == '\"'){
            instring = 1;
          }
          while (testt5 == 0){
            if (test[i + keysegmentlength + 4 + testt6] == '}' && ignore > 0){
              ignore = ignore - 1;
            } else if (test[i + keysegmentlength + 3 + testt6] == '{'){
              ignore++;
            } else if (((test[i + keysegmentlength + 4 + testt6] == '\"') && instring == 1 && ignore == 0) || ((test[i + keysegmentlength + 4 + testt6] == ',') && instring == 0 && ignore == 0) || ((test[i + keysegmentlength + 4 + testt6] == '}') && instring == 0 && ignore == 0)){
              if (ignore == 0){
                if (test[i + keysegmentlength + 3] == '\"'){
                  beginkey = i + keysegmentlength + 5;
                } else {
                  beginkey = i + keysegmentlength + 4;
                }
                endkey = i + keysegmentlength + 4 + testt6;
                printf("Key is between %d and %d.\n",beginkey,endkey);
                testt5++;
              }
            }
            testt6++;
          }
          position = beginkey;
          length = endkey - position + 1;
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
