#include<iostream>
#include<vector>
#include<set>
using namespace std;
using ll = long long;
const int MAXN = 6e5;
int c, n, m, d, q;
ll a[MAXN];
vector<pair<ll, ll>> pos[MAXN];
ll dis[505][505];
inline ll read()
{
	ll s = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-')ch = getchar();
	if(ch == '-')f = -1, ch = getchar();
	while(isdigit(ch))s = s * 10 + ch - '0', ch = getchar();
	return s * f;
}
inline void write(ll x)
{
	if(x < 10)putchar(x + '0');
	else write(x / 10), putchar(x % 10 + '0');
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; i++)a[i] = read();
	for(int i = 1; i <= n; i++)
	{
		ll k = read();
		for(int j = 1; j <= k; j++)
		{
			ll p = read(), v = read();
			pos[p].push_back({v, i});
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dis[i][j] = 1e18;
	for(int i = 1; i <= n; i++)
		dis[i][i] = 0;
	for(int i = 1; i <= m; i++)
		for(auto v : pos[i])
		{
			ll v1 = v.first;
			ll p1 = v.second;
			for(auto u : pos[i])
			{
				ll v2 = u.first;
				ll p2 = u.second;
				dis[p1][p2] = min(v1 + v2, dis[p1][p2]);
			}
		}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
	for(int i = 1; i <= q; i++)
	{
		ll u = read(), v = read();
		ll ans = 1e18;
		for(auto v1 : pos[u])
			for(auto v2 : pos[v])
				ans = min(ans, dis[v1.second][v2.second] + v1.first + v2.first + a[u] + a[v]);
		write(ans);
		putchar('\n');
	}
}