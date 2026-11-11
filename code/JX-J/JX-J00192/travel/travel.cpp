
#include<bits/stdc++.h>
using namespace std;
int main(){
        freopen("travel.in","r",stdin);
        freopen("travel.out","w",stdout);
        char x,y,a,b,c,d,q,w,e,r,op=' ';
        scanf("%c%c%c%c%c%c%c%c%c%c%c%c%c",&a,&b,&op,&c,&d,&x,&op,&q,&w,&op,&e,&r,&y);
        if(a==q && b==w) printf("1");
        else{
            printf("0000");
            return 0;
        }
        if(c==e && d==r) printf("1");
        else{
            printf("000");
            return 0;
        }
        if((x=='A' || x=='B' || x=='C') && (y=='A' || y=='B' || y=='C')) printf("1");
        else if((x=='D' || x=='F') && (y=='D' || y=='F')) printf("1");
        else{
            printf("00");
            return 0;
        }
        if((x=='D' || x=='F') && (y=='D' || y=='F')) printf("1");
        else if((x=='A' && y=='B') || (x=='B' && y=='A') || (x=='B' && y=='C') || (x=='C' && y=='B')) printf("1");
        else printf("0");
        return 0;
}
