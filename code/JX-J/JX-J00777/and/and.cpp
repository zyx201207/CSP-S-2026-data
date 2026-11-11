#include<bits/stdc++.h>
using namespace std;
int n,m,len,a[200005],dp[10005][10005];
string s;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        for(int j=1;j<=m;j++){
            dp[i][j]=a[i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]&a[i]);
        }
    }
    int maxs=0;
    for(int i=1;i<=n;i++){
        maxs=max(maxs,dp[i][m]);
        cout<<dp[i][m]<<" ";
    }
    cout<<"\n"<<maxs;
    return 0;
}

