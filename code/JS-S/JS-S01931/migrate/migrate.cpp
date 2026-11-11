#include<bits/stdc++.h>
#define int long long
const int N=5e3+10;
using namespace std;
int a[N],n,d,dp[N][N],dp1[N],ans;
void dfs(int dep,int h){
    for(int i=dep+1;i<=n;i++){
        if(a[i]-a[dep]<=d){
            // if(dp1[dep]==h)
            dp[h][dep]++;
            if(dp[h][dep]>=2)
                continue;
            dfs(i,h+1);
        }
        else break;
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            // cout<<dp1[i]<<" ";
        }

        // for(int k=1;k<=n;k++){
            memset(dp,0,sizeof(dp));
            dfs(1,1);
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++)
                    if(dp[i][j]>=2){
                    //     cout<<k<<" "<<i<<" "<<j<<"\n";
                    ans++;
                    }
                    // cout<<dp[i][j]<<" ";
                    // cout<<"\n";
            }   
        // }
        cout<<ans<<"\n";
    }
    return 0;
}//5 5 1 2 3 4 5