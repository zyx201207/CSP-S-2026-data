#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long f[500005];
long long d[500005];
int n;long long m;
int dp[1000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        f[i] = a[i]-a[i-1];
    }
    int ans = 0;
    for(int i=2;i<=n;i++){
        d[i] = 0;
        for(int j=i-1;j>=1;j--){
            d[j] = abs(d[j+1]+f[j+1]);
        }
        memset(dp,0,sizeof dp);
        for(int x=1;x<=i;x++){
            for(int j=m;j>=d[x];j--){
                dp[j] = max(dp[j],dp[j-d[x]]+1);
            }
        }
        ans = max(ans,dp[m]);
    }
    cout<<ans;
    return 0;
}
