#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,tot,a[2010],dp[2010][2010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	cin >> n >> m;
	for(ll i = 1;i <= n;i++) cin >> a[i],tot &= a[i];
	if(n == m)
	{
		cout << tot;
		return 0;
	}
	for(ll i = 1;i <= n;i++)
		for(ll j = 1;j <= m;j++)
		{
			if(j > i) break;
			dp[i][j] = max(dp[i][j],dp[i - 1][j]);
			dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] & a[i]);
		}
	cout << dp[n][m];
	return 0;
}
