#include<bits/stdc++.h>
using namespace std;
long long a[10005],dp[10005][10005];
int main(){
freopen("and.in","r",stdin);
freout("and.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}
dp[1][1]=a[1];
for(int i=2;i<=n;i++)
{
dp[i][1]=max(dp[i-1][1],a[i])
}
for(int i=2;i<=n;i++)
{
for(int j=2;j<=m&&j<=i;j++)
{
dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
}
}
cout<<dp[n][m];
return 0;
}
