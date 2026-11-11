#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+5;
ll n,m,mx;
ll ans=1;
ll a[N];
ll dp[N];
bool vis[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,1,sizeof(dp));
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }

    dp[0]=0;
    dp[1]=mx;
    for(ll i=0;i<n;i++){
        bool ok=0;
        for(ll j=N;j>=1;j--){
            if(((dp[j-1]&a[i])>0)&&ok==0){
                dp[j]=dp[j-1]&a[i];
                ok=1;
            }
            else dp[j]=max(dp[j],dp[j-1]&a[i]);
        }
    }

    cout<<dp[m];
    return 0;
}
