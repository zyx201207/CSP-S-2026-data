#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const ll inf=1e9+7;
int a,b,c,d;
string c1,s1,c2,s2;
int ans1=0,ans2=0,ans3=0,ans4=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    a=(s1[2]-'A');
    b=(s2[2]-'A');
    c=(s1[0]-'0')*10+(s1[1]-'0');
    d=(s2[0]-'0')*10+(s2[1]-'0');
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
    if(c1==c2) ans1=1;
    if(c==d and ans1==1) ans2=1;
    if((a/3)==(b/3) and ans2==1) ans3=1;
    if(abs(a-b)==1 and ans3==1) ans4=1;
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
