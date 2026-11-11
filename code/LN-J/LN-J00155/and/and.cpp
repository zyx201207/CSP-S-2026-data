#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[1]=a[n];
    for(int i=1;i<n;i++)
    {
        dp[i+1]=max(max(dp[i+1],a[i])&min(dp[i+1],a[i]),dp[i]);
    }
    cout<<dp[m];
}
