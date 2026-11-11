#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[5],s2[5];
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%s%d%s",&c1,s1 + 1,&c2,s2 + 1);
    if (c1 != c2){
        printf("0000");
    } else {
        printf("1");
        if (s1[1] == s2[1] && s1[2] == s2[2]){
            printf("1");
            if (s1[3] == 'A'){
                if (s2[3] == 'B') printf("11");
                else if (s2[3] == 'C') printf("10");
                else printf("00");
            } else if (s1[3] == 'B'){
                if (s2[3] == 'A' || s2[3] == 'C') printf("11");
                else printf("00");
            } else if (s1[3] == 'C'){
                if (s2[3] == 'B') printf("11");
                else if (s2[3] == 'A') printf("10");
                else printf("00");
            } else if (s1[3] == 'D'){
                if (s2[3] == 'F') printf("11");
                else printf("00");
            } else {
                if (s2[3] == 'D') printf("11");
                else printf("00");
            }
        } else printf("000");
    }
    printf("\n");
    return 0;
}