#include<bits/stdc++.h>
using namespace std;
int n,m,dp[10005][10005],a[200005];//dp[i][j]:qian i ge shu xuan j ge de zui da yu zhi
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        dp[i][1]=a[i];
    for(int i=1;i<=m;i++)
        dp[0][i]=(1<<30)-1;
    for(int i=2;i<=n;i++)
        for(int j=2;j<=i;j++)
            dp[i][j]=max(dp[i-1][j],a[i]&dp[i-1][j-1]);
    cout<<dp[n][m];
}
