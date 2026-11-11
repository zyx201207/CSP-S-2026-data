#include<bits/stdc++.h>
using namespace std;
char a[5],b[5],c[5],d[5];
bool ans[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",a,b,c,d);
    int ta=(a[0]-'0')*10+a[1]-'0',tb=(c[0]-'0')*10+c[1]-'0';
    int la=(b[0]-'0')*10+b[1]-'0',lb=(d[0]-'0')*10+d[1]-'0';
    int sita=b[2]-'A',sitb=d[2]-'A';
    if(ta==tb){
        cout<<1;
    }else{
        cout<<0;
    }
    if(ta==tb&&la==lb){
        cout<<1;
    }else{
        cout<<0;
    }
    if(ta==tb&&la==lb&&(sita<=2&&sitb<=2)||(sita>=3&&sitb>=3)){
        cout<<1;
    }else{
        cout<<0;
    }
    if(ta==tb&&la==lb&&(sita-sitb==1||sita-sitb==-1)&&(sita+sitb!=5)){
        cout<<1;
    }else{
        cout<<0;
    }
}
