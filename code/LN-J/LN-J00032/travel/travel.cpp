#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char e,f;
    scanf("%02d %02d%c %02d %02d%c",&a,&b,&e,&c,&d,&f);
    if(e=='D')e++;
    if(f=='D')f++;
    printf("%d%d%d%d",a==c,(a==c)&&(b==d),(a==c)&&(b==d)&&((e<'D'&&f<'D')||(e>'D'&&f>'D')),(a==c)&&(b==d)&&((e-f==1)||(f-e==1)));
}
