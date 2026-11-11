#include<bits/stdc++.h>
using namespace std;
int n,m,dp[200005][200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>dp[1][i];
    }
    for(long long i=2;i<=m;i++){
        for(long long j=i;j<=n;j++){
            int u=0;
            for(long long k=1;k<j;k++){
                if((dp[i-1][k]&dp[1][j])>u){
                    u=dp[i-1][k]&dp[1][j];
                }
            }
            dp[i][j]=max(u,dp[i][j-1]);
        }
    }
    cout<<dp[m][n];
    return 0;
}

