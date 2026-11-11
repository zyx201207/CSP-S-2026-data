#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],dp[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++){
        memset(dp,0,sizeof(dp));
        dp[n]=a[n]==i;
        for(int j=n-1;j>=i;j--)if(a[j]==i)dp[j]=dp[j+1]+1;
        cout<<dp[i]<<' ';
    }
    return 0;
}
