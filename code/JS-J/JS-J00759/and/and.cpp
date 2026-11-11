#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=200005;
ll n,m,a[MAXN],dp[5][MAXN]={0},INF=((ll)(1)<<35)-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[0][1]=a[1];
    for(ll i=2;i<=n;i++){
        dp[0][0]=INF;
        for(ll j=1;j<=min(m,i);j++){
            dp[1][j]=max(dp[0][j],dp[0][j-1]&a[i]);
        }
        for(int j=1;j<=m;j++){
            dp[0][j]=dp[1][j];
        }
    }
    cout<<dp[0][m];
    return 0;
}
//(tle)