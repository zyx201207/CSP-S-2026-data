#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,cc,ss;
    cin>>c>>s>>cc>>ss;
    if (c==cc){
        printf("1");
    }
    else{
        printf("0000");
        return 0;
    }
    if (s[0]==ss[0] && s[1]==ss[1]){
        printf("1");
        if ((s[2]=='A' && ss[2]=='B') || (s[2]=='B' && ss[2]=='A') || (s[2]=='A' && ss[2]=='C') || (s[2]=='C' && ss[2]=='A') || (s[2]=='B' && ss[2]=='C') || (s[2]=='C' && ss[2]=='B') || (s[2]=='D' && ss[2]=='F') || (s[2]=='F' && ss[2]=='D')){
            printf("1");
            if ((s[2]=='A' && ss[2]=='B') || (s[2]=='B' && ss[2]=='A') || (s[2]=='B' && ss[2]=='C') || (s[2]=='C' && ss[2]=='B') || (s[2]=='D' && ss[2]=='F') || (s[2]=='F' && ss[2]=='D')){
                printf("1");
            }
            else{
                printf("0");
            }
        }
        else{
            printf("00");
        }
    }
    else{
        printf("000");
    }
    return 0;
}
