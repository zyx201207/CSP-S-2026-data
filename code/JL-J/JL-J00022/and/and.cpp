#include<bits/stdc++.h>
using namespace std;
long long ans=-1e18,a[200010];
map<int,map<int,long long>> dp;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][1]=a[i];
    }
    for(int i=2;i<=m;i++){
        for(int j=i;j<=n;j++){
            for(int k=i-1;k<j;k++){
                dp[j][i]=max(dp[j][i],dp[k][i-1]&a[j]);
            }
        }
    }
    for(int i=m;i<=n;i++){
        ans=max(ans,dp[i][m]);
    }
    cout<<ans;
    return 0;
}
