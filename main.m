//Zachary Keffaber / zachary7829, 2021/10/19, SeaJson 

#import <Foundation/Foundation.h>

int main (int argc, const char * argv[])
{
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

    int i, length = 0;
    char test[] = "{\"Test0\":\"Testinggg\",\"Test1\":\"Testto\"}";
    char dictkey[] = "Test0";
    int testt3, testt4, testt5, testt6, c = 0;
    int keylength = sizeof dictkey - 1;
    char returnkey[] = "";
    char sub[1000];
    int beginkey = 3;
    int endkey = 6;
    while (sizeof test > i) {
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
                beginkey = i + keylength + 5;
                endkey = i + keylength + 4 + testt6;
                NSLog(@"Key is between %d and %d.\n",beginkey,endkey);
                testt5++;
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
            NSLog(@"Value of key is \"%s\"\n", sub); // '\"' to print "
          }
        };
      }
      i++;
    }

    [pool drain];
    return 0;
}
