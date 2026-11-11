#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
bool k1,k2,k3,k4;
void solve(){
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]) k1=1;
    if(k1==1&&(s1[0]==s2[0]&&s1[1]==s2[1])) k2=1;
    int s1n=s1[2],s2n=s2[2];
    if(k2==1&&(s1n>=65&&s1n<=67&&s2n>=65&&s2n<=67||
    (s1n==68||s1n==70)&&(s2n==68||s2n==70))) k3=1;
    if(k2==1&&((max(s1n,s2n)==70&&min(s1n,s2n)==68)||
    (abs(s1n-s2n)==1&&min(s1n,s2n)!=67))) k4=1;
    cout<<k1<<k2<<k3<<k4;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int T=1; /*cin>>T;*/
    while(T--) solve();
    return 0;
}