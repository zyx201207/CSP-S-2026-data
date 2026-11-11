#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int m,n;
int a[MAXN];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int dp[n][m];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][1]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m;j++){
            for(int k=1;k<=n;k++){
                if(i==k)continue;
                dp[i][j]=max(dp[i][j],dp[i][j-1]&a[k]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i][m]);
    }
    cout<<ans;
    return 0;
}
