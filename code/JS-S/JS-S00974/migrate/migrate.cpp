#include<bits/stdc++.h>
using namespace std;
long long x[5001];
long long pre[5001];
long long dp[301][301][301];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        long long n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i],pre[i]=0;
        for(long long i=1,j=1;i<=n;i++){
            while(j<i&&x[i]-x[j]>d) j++;
            pre[i]=j;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++) dp[i][j][k]=0;
        for(int i=1;i<=n;i++) dp[i][i][0]=1;
        for(long long i=1;i<=n;i++)
            for(long long j=i+1;j<=n;j++)
                for(long long k=j-i;k>=1;k--){
                    for(long long l=max(pre[j],i);l<=j-1;l++) dp[i][j][k]+=dp[i][l][k-1];
                    if(dp[i][j][k]==0) break;
                }
        long long ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=1;k<=n;k++){
                    if(dp[i][j][k]==0) continue;
                    if(dp[i][j][k]==2) ans++;
                    break;
                }
        cout<<ans<<"\n";
    }
    return 0;
}
