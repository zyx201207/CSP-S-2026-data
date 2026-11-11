#include <bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int c,t,x[N],dp[N][N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        sort(x+1,x+n+1);
        for(int len=2;len<=n;len++){
            for(int i=1;i<=(n-len+1);i++){
                int j=i+len-1;
                if(x[j ]-x[i]<=d)dp[i][j]++;
                else{
                    for(int k=i+1;k<j;k++){
                        if(dp[i][k]&&dp[k][j])dp[i][j]++;
                    }
                }
                
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dp[i][j]==2)ans++;
           //     cout<<dp[i][j];
            }
           // cout<<'\n';
        }
        cout<<ans<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}