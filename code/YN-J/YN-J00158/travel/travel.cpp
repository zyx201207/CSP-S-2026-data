#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int num1,num2,num3,num4;
bool ok[5];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    for(int i=0;i<2;++i)num1=num1*10+(s1[i]-'0'),num2=num2*10+(s3[i]-'0');
    for(int i=0;i<2;++i)num3=num3*10+(s2[i]-'0'),num4=num4*10+(s4[i]-'0');
    ok[1]=(num1==num2);ok[2]=(ok[1]&&num3==num4);
    num3=(int)(s2[2]-'A');num4=(int)(s4[2]-'A');
    ok[3]=(ok[2]&&(min(num3,num4)>=3||max(num3,num4)<=2));
    ok[4]=(ok[3]&&max(num3,num4)-min(num3,num4)==1);
    for(int i=1;i<=4;++i)cout<<ok[i];
    return 0;
}
