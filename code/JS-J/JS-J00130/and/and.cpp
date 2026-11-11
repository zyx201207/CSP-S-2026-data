#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m;
ll a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<ll> > dp(n+1,vector<ll>(m+1,0));
    ll maxn{};
    for(int i=1;i<=n;i++){
        maxn=max(maxn,a[i]);
        dp[i][1]=maxn;
    }
    for(int i=1;i<=n;i++){
        for(int k=2;k<=i&&k<=m;k++){
            dp[i][k]=max(dp[i-1][k-1]&a[i],dp[i-1][k]);
        }
    }
    ll ans{};
    for(int i=1;i<=n;i++){
        ans=max(dp[i][m],ans);
    }
    cout<<ans;
    return 0;
}
