#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll N = 3e2 + 7;
ll A[N];
pair <ll,ll> dp[N][N];
ll d;
void floyd(ll n)
{
	memset(dp,0x3f,sizeof(dp));
	for (ll k = 1; k <= n; k ++)
	{
		for (ll i = 1; i <= n; i ++)
		{
			for (ll j = 1; j <= n; j ++)
			{
				if (abs(A[i] - A[j]) <= d) dp[i][j] = dp[j][i] = make_pair(1,1);
				else if (dp[i][j].first == dp[i][k].first + dp[k][j].first) dp[i][j].second += dp[i][k].second * dp[k][j].second;
				else if (dp[i][j].first > dp[i][k].first + dp[k][j].first) dp[i][j] = make_pair(dp[i][k].first + dp[k][j].first,dp[i][k].second * dp[k][j].second);
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	scanf("%lld%lld",&c,&t);
	if (c >= 11 && c <= 12)
	{
		while (t --)
		{
			ll n;
			scanf("%lld%lld",&n,&d);
			for (ll i = 1; i <= n; i ++) 
			{
				ll x;
				if (i <= 2) scanf("%lld",&A[i]);
				else scanf("%lld",&x);
			}
			ll t = A[2] - A[1];
			ll ans;
			if (d <= t) ans = 0;
			else 
			{	
				d /= t;
				ans = n - d * 2 + 1;
			}
			if (ans < 0) ans = 0;
			if (n < 4) ans = 0;
			printf("%lld\n",ans);
		}
		return 0;
	}
	while (t --)
	{
		ll n;
		scanf("%lld%lld",&n,&d);
		for (ll i = 1; i <= n; i ++) scanf("%lld",&A[i]);
		floyd(n);
		ll ans = 0;
		for (ll i = 1; i <= n; i ++)
		{
			for (ll j = 1; j <= n; j ++)
			{
				if (i == j) continue;
				if (dp[i][j].second == 2) ans ++;
			}
		}
		printf("%lld\n",ans / 2);
	}
	return 0;
} 
/*

0 2
 5 3
 -2 -1 0 1 2
 6 2
 -4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


*/
