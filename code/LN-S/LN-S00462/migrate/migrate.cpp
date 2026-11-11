#include<bits/stdc++.h>
using namespace std;
#define N 5010
#define ll long long
int n,dp[N][N],ans,c,T;
ll m,a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        memset(dp,0x3f,sizeof dp);
        for(int len=1;len<n;len++){
            for(int l=1;l+len<=n;l++){
                int r=l+len;
                if(a[r]-a[l]<=m){
                    dp[l][r]=1;
                    continue;
                }
                int t=0;
                for(int k=l+1;k<r;k++){
                    if(dp[l][k]==0||dp[k][r]==0)continue;
                    if(dp[l][k]+dp[k][r]==dp[l][r])t++;
                    if(dp[l][k]+dp[k][r]<dp[l][r]){
                        dp[l][r]=dp[l][k]+dp[k][r];
                        t=1;
                    }
                }
                if(t==2)ans++;
            }
        }
        cout<<ans<<endl;
        ans=0;
        memset(dp,0x3f,sizeof dp);
    }
    return 0;
}
