//track in time
//Yh0326 448917 in Luogu
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l;i <= r;++ i)
#define per(i, r, l) for(int i = r;i >= l;-- i)
using namespace std;
typedef long long ll;
inline int read()
{
	int s = 0, w = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-'){w = -1;}ch = getchar();}
	while(isdigit(ch)) s = s * 10 + ch - 48, ch = getchar();
	return s * w;
}
const int mod = 998244353;
inline int ksm(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1) ans = (ll)ans * a % mod;
		a = (ll)a * a % mod;
		n >>= 1;
	}
	return ans;
}
int c, n, m, d, q;
ll w[500003];
int k;
#define pii pair<int, ll>
vector<pii> g[500003];
const ll M = (ll)3e18;
ll dis[503][503];
ll ans;
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	rep(i, 1, m) w[i] = read();
	int x, y;
	rep(i, 1, n)
	{
		k = read();
		rep(j, 1, k)
		{
			x = read(), y = read();
			g[x].push_back(make_pair(i, y));
		}
	}
	rep(i, 1, n)
	{
		dis[i][i] = 0;
		rep(j, i + 1, n) dis[i][j] = dis[j][i] = M;
	}
	rep(i, 1, m)
	{
		int j = 0;
		for(pii p = g[i][0];j < g[i].size();++ j, p = g[i][j])
		{
			k = j + 1, x = p.first;
			for(pii q = g[i][k];k < g[i].size();++ k, q = g[i][k])
			{
				y = q.first;
				dis[x][y] = min(dis[x][y], p.second + q.second);
				dis[y][x] = dis[x][y];
			}
		}
	}
	rep(k, 1, n)
		rep(i, 1, n)
			rep(j, 1, n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	int s, t;
	while(q --)
	{
		s = read(), t = read();
		ans = M;
		for(pii p : g[s])
		{
			x = p.first;
			for(pii q : g[t])
			{
				y = q.first;
				ans = min(ans, dis[x][y] + p.second + q.second);
			}
		}
		ans += w[s] + w[t];
		cout << ans << '\n';
	}
	return 0;
}
/*

Easy to think of Dij?

And we have got (nm) nodes

NOOO

so wo got n^2 nodes

and OK

it's more likely to be Floyd

*/
