#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,ans=0,A[2000002],x[2000002],dp[2000002];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        ans=0;
        for(long long i=1;i<=n;i++){
            cin>>A[i];
            x[i]=0;
            long long j=i-1;
            while(j>=1&&A[j]>=A[i]-k){
                x[j]++;
                j--;
            }
        }
        for(long long i=n;i>=1;i--){
            dp[i]=0;
            for(long long j=i-1;j>=1;j--){
                if(x[j]==0)break;
                long long y=min(i,j+x[j]);
                dp[j]=dp[y]+1;
                if(j<=i-2&&x[j]>=2){
                    if(dp[y]==dp[y-1]&&dp[y-1]!=dp[y-2])ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
