#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+10;
ll dp[maxn],a[maxn],f[maxn];
ll n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n>>m;
    ll mi=-1,kj;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>mi){
            mi=a[i];
            kj=i;
        }
    }
    for(int i=0;i<=maxn;i++){
        f[i]=mi;
        dp[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            if(j-1>=0&&kj!=i){
                ll x=f[j-1],y=a[i];
                ll k=(x&y);
                dp[j]=max(dp[j],k);
                f[j]=dp[j];
            }
        }
    }
    ll mx=0;
    for(int i=2;i<=m;i++){
        mx=max(mx,dp[i]);
    }
    cout<<mx;
    return 0;
}
