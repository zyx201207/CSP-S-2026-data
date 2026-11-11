#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool f1,f2,f3,f4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3) f1=1;
    if(f1&&s2[0]==s4[0]&&s2[1]==s4[1]) f2=1;
    if(f1&&f2&&((s2[2]<='C'&&s4[2]<='C')||(s2[2]<='C'&&s4[2]<='C'))) f3=1;
    char a=s2[2],b=s4[2];
    if(a>b) swap(a,b);
    if((f2&&f1)&&((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F'))) f4=1;
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
