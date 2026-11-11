#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char s[10][10];
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d %s %d %s",&a,s[0],&b,s[1]);
    if(s[1][2]=='F')s[1][2]='E';
    if(s[0][2]=='F')s[0][2]='E';
    if(a==b){
        printf("1");
        if(s[0][0]==s[1][0]&&s[0][1]==s[1][1]){
            printf("1");
            if(s[0][2]=='A'||s[0][2]=='B'||s[0][2]=='C')c=1;
            else c=2;
            if(s[1][2]=='A'||s[1][2]=='B'||s[1][2]=='C')d=1;
            else d=2;
            if(c==d){
                printf("1");
                if(abs(s[0][2]-s[1][2])<=1)printf("1");
                else printf("0");
            }else printf("00");
        }else printf("000");
    }else printf("0000");
    return 0;
}
//02 01C 02 01D
