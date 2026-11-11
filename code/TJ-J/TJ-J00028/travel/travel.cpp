#include<bits/stdc++.h>
using namespace std;
int a1,b1,A2,B2;
char a2[4],b2[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d",&a1);
    scanf("%s",a2);
    scanf("%d",&b1);
    scanf("%s",b2);
    if(a1==b1)
        printf("1");
    else {
        printf("0000");
        return 0;
    }
    A2=(a2[0]-'0')*10+(a2[1]-'0');
    B2=(b2[0]-'0')*10+(b2[1]-'0');
    if(A2==B2)
        printf("1");
    else {
        printf("000");
        return 0;
    }
    A2=a2[2]-'0';
    B2=b2[2]-'0';
    if(((A2=='A'-'0'||A2=='B'-'0'||A2=='C'-'0')&&(B2=='A'-'0'||B2=='B'-'0'||B2=='C'-'0'))||((A2=='D'-'0'||A2=='E'-'0')&&(B2=='D'-'0'||B2=='E'-'0')))
        printf("1");
    else {
        printf("00");
        return 0;
    }
    if(A2==B2+1||A2==B2-1)
        printf("1");
    else {
        printf("0");
        return 0;
    }
    return 0;
}
