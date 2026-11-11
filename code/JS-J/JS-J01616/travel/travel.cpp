#include <bits/stdc++.h>
using namespace std;
char s[21],t[21];
char s1[21],t1[21];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s",s+1,s1+1);
    scanf("%s%s",t+1,t1+1);
    int ss=0,tt=0;
    ss+=(s[1]-'0')*10+(s[2]-'0');
    tt+=(t[1]-'0')*10+(t[2]-'0');
    if(tt!=ss){
        printf("0000\n");
        return 0;
    }
    if(!(s1[1]==t1[1]&&s1[2]==t1[2])){
        printf("1000\n");
        return 0;
    }
    int x=0;
    if(s1[3]=='A'||s1[3]=='B'||s1[3]=='C')
        x=0;
    else
        x=1;
    int y=0;
    if(t1[3]=='A'||t1[3]=='B'||t1[3]=='C')
        y=0;
    else
        y=1;
    if(x!=y){
        printf("1100\n");
        return 0;
    }
    if((s1[3]=='A'&&t1[3]=='C')||(s1[3]=='C'&&t1[3]=='A'))
       printf("1110\n");
    else
        printf("1111\n");
    return 0;
}
