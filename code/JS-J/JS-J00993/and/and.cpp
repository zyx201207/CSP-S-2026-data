
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[200005];
int dp[20005][20005];
bool cmp(int a,int b){
    return a<b;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        dp[i][1]=a[i];
    }
    dp[0][0]=a[1];
    for(int i=2;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[j][i]=max(dp[j-1][i-1]&a[j],dp[j-1][i]);
        }
    }
    int ans=-1;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i][m]);
    }
    cout<<ans;
    return 0;
}

