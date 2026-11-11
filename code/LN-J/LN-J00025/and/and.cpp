#include <bits/stdc++.h>
using namespace std;
int n,m,s,a[200005],dp[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    dp[0]=(1<<30);
    dp[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=i;j++)
        {
            dp[j]=max(dp[j],dp[j-1]&a[i]);
        }
        s=max(s,a[i]);
        dp[1]=s;
    }
    cout << dp[m];
    return 0;
}
