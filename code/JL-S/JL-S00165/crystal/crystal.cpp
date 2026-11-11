#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[500010][2];
int n,m;
int a[500010];
int b[500010];
int maxn;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
    }
    int last=0;
    for(int i=1;i<=n;i++){
        last=0;
        for(int j=i+1;j<=n;j++){
            if(dp[j-1][1]+dp[j-1][0]*(last+b[j])<=m){
                dp[j][0]=dp[j-1][0]+1;
                dp[j][1]=dp[j-1][1]+dp[j-1][0]*(last+b[j]);
                last=0;
            }
            else{
                //last+=b[j];
                //dp[j][0]=dp[j-1][0];
                //dp[j][1]=dp[j-1][1];
                dp[n][0]=dp[j-1][0];
                break;
            }
        }
        maxn=max(maxn,dp[n][0]);
    }
    cout<<maxn;
    return 0;
}
