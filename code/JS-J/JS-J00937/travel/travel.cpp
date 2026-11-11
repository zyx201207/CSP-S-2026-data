#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a1=(c1[0]-'0')*10+(c1[1]-'0'),a2=(c2[0]-'0')*10+(c2[1]-'0');
    int b1=(s1[0]-'0')*10+(s1[1]-'0'),b2=(s2[0]-'0')*10+(s2[1]-'0');
    int d1=(s1[2]-'A'+1),d2=(s2[2]-'A'+1);
    int d3=min(d1,d2),d4=max(d1,d2);
    bool f1=0,f2=0,f3=0,f4=0;
    if(a1==a2) f1=1;
    if(f1&&b1==b2) f2=1;
    if(f2&&((d3<=3&&d4<=3)||(d3>=4&&d4>=4))) f3=1;
    if(f3&&((d3==1&&d4==2)||(d3==2&&d4==3)||(d3==4&&d4==6))) f4=1;
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
