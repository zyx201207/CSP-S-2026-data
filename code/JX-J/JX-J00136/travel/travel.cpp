#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
  /*   char s[20];

   scanf("%s", s + 1);
    printf("%s\n", s + 1);
    if (s[1] == s[8] && s[2] == s[9]) {
        printf("1");
        if (s[4] == s[11] && s[5] == s[12]) {
            printf("1");
            if ((s[6] == 'A' && s[13] == 'B') || (s[6] == 'A' && s[13] == 'C') || (s[6] == 'B' && s[13] == 'C')) {
                printf("1");
                if (s[6] == 'A' && s[13] == 'B')
                    printf("1");
                if (s[6] == 'B' && s[13] == 'C')
                    printf("1");
            }
            if ((s[13] == 'A' && s[6] == 'B') ||
                (s[13] == 'A' && s[6] == 'C') ||
                (s[13] == 'B' && s[6] == 'C')) {
                printf("1");
                if (s[13] == 'A' && s[6] == 'B')
                    printf("1");
                if (s[13] == 'B' && s[6] == 'C')
                    printf("1");
            }
            if ((s[6] == 'D' && s[13] == 'F') || (s[13] == 'D' && s[6] == 'F'))
                printf("11");
        }

    }*/
    char s1[20], s2[20], s3[20], s4[20];
    scanf("%s %s %s %s", s1 + 1, s2 + 1, s3 + 1, s4 + 1);
    if (s1[1] == s3[1] && s1[2] == s3[2]) {
        printf("1");
        if (s2[1] == s4[1] && s2[2] == s4[2]) {
            printf("1");
            if (abs(s2[3] - s4[3]) == 1 && (s2[3] != 'D' && s4[3] != 'C') && (s2[3] != 'C' && s4[3] != 'D'))
                printf("11");
            else {
                if ((s2[3] == 'A' && s4[3] == 'C') || (s2[3] == 'C' && s4[3] == 'A'))
                    printf("10");
                else
                    printf("00");
                }
    }
        else printf("000");
    }
    else printf("0000");
   // printf("%s\n%s\n%s\n%s", s1 + 1, s2 + 1, s3 + 1, s4 + 1);
    return 0;

}
