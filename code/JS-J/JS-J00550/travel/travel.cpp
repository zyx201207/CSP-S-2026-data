#include<bits/stdc++.h>
#define pcr(i,a,b,c) for(int i=a;i<=b;i+=c)
#define rcp(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e5+3;
const ll inf=1e9;
const int mod=998244353;
string s1,s2,c1,c2;
void solve(){
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        cout<<"0000";
        return;
    }
    int r1=(s1[0]-'0')*10+(s1[1]-'0'),r2=(s2[0]-'0')*10+(s2[1]-'0');
    if(r1==r2) cout<<1;
    else{
        cout<<"000";
        return;
    }
    char ch1=s1[2],ch2=s2[2];
    if(ch1>ch2) swap(ch1,ch2);
    if(ch2<='C'||ch1>='D') cout<<1;
    else{
        cout<<"00";
        return;
    }
    if(ch1=='B'||ch2=='B'||ch1=='D') cout<<1;
    else cout<<0;
    return;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    T=1;
    while(T--) solve();
    return 0;
}
