#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e6+10;
int n,d,x[MAXN],r[MAXN],R[MAXN],dp[MAXN][4];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=n;i++) r[i]=upper_bound(x+1,x+n,x[i]+d)-x,r[i]=(x[r[i]]<=x[i]+d?r[i]:r[i]-1);
    for(int i=n-1;i;i--) if(r[r[i]]^r[i]){
        if(r[i]-i<2) dp[i][1]=dp[r[i]][1]+1,dp[i][2]=dp[r[i]][2]+dp[r[i]][3];
        else if(r[i]-i<3){
            if(r[r[i]-1]==r[r[i]]) dp[i][1]=2,dp[i][3]=dp[r[i]][1];
            else if(r[r[i]-1]==r[r[i]]-1&&r[r[i]]-r[i]>1) dp[i][1]=dp[r[i]][1]+2,dp[i][2]=dp[r[i]][2],dp[i][3]=r[r[i]-1]-r[i];
            else dp[i][1]=dp[r[i]][1]+2,dp[i][2]=dp[r[i]][2]+dp[r[i]][3],dp[i][3]=r[r[i]-1]-r[i];
        } else{
            if(r[r[i]-1]==r[r[i]]){
                if(r[r[i]-2]^r[r[i]-1]) dp[i][1]=r[i]-i,dp[i][3]=dp[r[i]][1];
                else dp[i][1]=r[i]-i;
            } else if(r[r[i]-1]==r[r[i]]-1&&r[r[i]]-r[i]>1) dp[i][1]=dp[r[i]][1]+r[i]-i,dp[i][2]=dp[r[i]][2],dp[i][3]=r[r[i]-1]-r[r[i]-2];
            else dp[i][1]=dp[r[i]][1]+r[i]-i,dp[i][2]=dp[r[i]][2]+dp[r[i]][3],dp[i][3]=r[r[i]-1]-r[r[i]-2];
        }
    } else dp[i][1]=r[i]-i;
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=dp[i][2]+dp[i][3];
        cout<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<" "<<r[i]<<"\n";
        dp[i][1]=dp[i][2]=dp[i][3]=0;
    } cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
    int Cid,T=1;
    cin>>Cid>>T;
    while(T--) solve();
    return 0;
}
