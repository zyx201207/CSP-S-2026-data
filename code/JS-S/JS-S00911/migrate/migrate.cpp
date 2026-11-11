#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,_;
    cin>>c>>_;
    while(_--){
        int n,k,ans=0;
        cin>>n>>k;
        vector<int>v(n+1,0);
        for(int i=1;i<=n;i++)cin>>v[i];
        vector<vector<int>>dp(n+1,vector<int>(n+1,0)),dp2(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            int ls=i,f=0;
            dp[i][i]=0;
            for(int j=i+1;j<=n;j++){
                while(v[j]-v[ls]>k)ls++;
                if(ls==j)f=1;
                dp[i][j]=dp[i][ls]+1;
                if(f)dp[i][j]=1e18;
            }
        }
        for(int i=1;i<=n;i++){
            dp2[i][i]=1;
            int ls=i,f=0;
            for(int j=i+1;j<=n;j++){
                for(int kk=j-1;v[j]-v[kk]<=k&&kk>=i;kk--){
                    if(dp[i][kk]+1==dp[i][j])dp2[i][j]+=dp2[i][kk];
                }
                if(dp[i][j]==1e18)dp2[i][j]=1e18;
                if(dp2[i][j]==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
