#include <bits/stdc++.h>
using namespace std;
vector<int>a;
int n,m,ans=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=0;i<n;i++){
            ans=max(ans,a[i]);
            cout<<ans;
        }
        return 0;
    }
    if(m==n){
        ans=a[0];
        for(int i=1;i<n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    vector<vector<int>>dp(m+2,vector<int>(n+2,0));
    for(int i=1;i<=m;i++){
        for(int j=i-1;j<n;j++){
            if(i==1){
                dp[i][j]=a[j];
                continue;
            }
            for(int k=0;k<j;k++){
                dp[i][j]=max(max(dp[i][j],dp[i-1][k]&a[j]),dp[i][j-1]);
            }
        }
    }
    cout<<dp[m][n-1];
    return 0;
}
