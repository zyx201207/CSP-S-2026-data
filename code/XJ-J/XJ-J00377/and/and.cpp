#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n,m,a[N],ans=-1;
int dp[N][N];//dp[i][j]:前i个数中选择j个的答案，且必须选择a[i]
int best[N][N];//best[k][j]:dp[前i][k]&a[j]的最大值
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0][0]=-1;
    memset(best,-1,sizeof(best));
    for(int i=1;i<=n;i++){
        dp[i][0]=-1;
        for(int j=1;j<=m;j++){
            for(int k=0;k<i;k++){
                dp[i][j]=max(dp[i][j],dp[k][j-1]&a[i]);
            }
        }
    }
    int ans=-1;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i][m]);
    }
    cout<<ans;
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
}