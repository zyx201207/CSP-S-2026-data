#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5],sum[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%c%c %c%c%c %c%c %c%c%c",&c1[1],&c1[2],&s1[1],&s1[2],&s1[3],&c2[1],&c2[2],&s2[1],&s2[2],&s2[3]);
    if(c1[1]==c2[1]&&c1[2]==c2[2])
        sum[1]='1';
    else{
        printf("0000\n");
        return 0;
    }
    if(s1[1]==s2[1]&&s1[2]==s2[2])
        sum[2]='1';
    else{
        printf("1000\n");
        return 0;
    }
    if(s1[3]-s2[3]==1||s2[3]-s1[3]==1||(s1[3]=='A'&&s2[3]=='C')||(s1[3]=='C'&&s2[3]=='A')&&(s1[3]!='D'&&s2[3]!='C')||(s1[3]!='C'&&s2[3]!='D'))
        sum[3]='1';
    else{
        printf("1100\n");
        return 0;
    }
    if((s1[3]-s2[3]==1||s2[3]-s1[3]==1)&&(s1[3]!='D'&&s2[3]!='C')||(s1[3]!='C'&&s2[3]!='D'))
        sum[4]='1';
    else{
        printf("1110\n");
        return 0;
    }
    printf("1111\n");
    return 0;
}
