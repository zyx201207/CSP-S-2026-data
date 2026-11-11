#include<bits/stdc++.h>
using namespace std;
int n,m,dp[2][200005],a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++){
            int t1=i%2,t2=(i-1)%2;
            dp[t1][j]=dp[t2][j];
            if(j==1){
                dp[t1][j]=max(dp[t2][j],a[i]);
                continue;
            }
            if(j>0) dp[t1][j]=max(dp[t1][j],dp[t2][j-1]&a[i]);
        }
    cout<<dp[n%2][m];
    return 0;
}
