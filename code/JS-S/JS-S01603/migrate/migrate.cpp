#include <iostream>
#include <cstdio>
using namespace std;
int c,t,dp[5005][5005][2],x[5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++){
            dp[i][i][0]=0;dp[i][i][1]=1;
            for(int j=i+1;j<=n;j++){
                dp[i][j][0]=0x3f3f3f3f;
                for(int k=i;k<j;k++){
                    if(x[j]-x[k]>d)continue;
                    if(dp[i][k][0]+1<dp[i][j][0]){
                        dp[i][j][0]=dp[i][k][0]+1;
                        dp[i][j][1]=dp[i][k][1];
                    }
                    else if(dp[i][k][0]+1==dp[i][j][0]){
                        dp[i][j][1]+=dp[i][k][1];
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(dp[i][j][0]!=0x3f3f3f3f && dp[i][j][1]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
