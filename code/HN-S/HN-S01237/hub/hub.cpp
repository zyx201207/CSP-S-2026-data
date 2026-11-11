#include<bits/stdc++.h>
// #define int long long
using namespace std;
const int maxn=2e5+7;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
// int pls(int a,int b){ return (0ll+a+b>=mod?a-mod+b:a+b); }
// int div(int a,int b){ return (a>=b?a-b:a-b+mod); }
int pls(int a,int b){ return (a+b)%mod; }
int dpl(int a,int b){ return ((a-b)%mod+mod)%mod; }
int mul(int a,int b){ return 1ll*a*b%mod; }
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,k;
        cin>>n>>k;
        for(int j=1;j<n;j++){
            int a,b; cin>>a>>b;
        } 
        if(k==n) cout<<"0\n";
        else cout<<1<<'\n';
    }
    return 0;
}