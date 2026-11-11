#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[200005];
int dp[20005][20005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }

    for(long long i=1;i<=n;i++){
        dp[i][1]=a[i];
    }
    for(long long i=2;i<=n;i++){
        for(long long j=2;j<=i;j++){
            dp[i][j]=dp[i][j-1]&a[j];
            for(long long k=1;k<i-j+1;k++){
                dp[i][j]=max(dp[i][j],dp[i][j-1]&a[j+k]);
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}
