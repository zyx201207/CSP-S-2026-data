#include<bits/stdc++.h>
using namespace std;
long long n,m,v[11000000],w[11000000]={1};
long long dp[11000000][11000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>v[i];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            if(j<m) dp[i][j]=v[i];
            dp[i][j]=dp[i-1][j];
            if(j>=w[i]){
                dp[i][j]=max(dp[i-1][j],(dp[i-1][j-w[i]]&v[i]));
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}
