#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;

    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    int mx=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,a[i]);
        dp[i][1]=mx;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=min(i,m);j++){
            dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i][j]);
        }
    }
    cout<<dp[n][m];
    return 0;
}
