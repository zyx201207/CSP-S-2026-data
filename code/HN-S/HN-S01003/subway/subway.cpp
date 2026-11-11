#include<bits/stdc++.h>
#define pre(i, l, r)	for(int i = (l); i <= (r); ++i)
#define fpre(i, r, l)	for(int i = (r); i >= (l); --i)
#define ll long long

using namespace std;

const int maxn = 1e6 + 5;
const int inf = 1e9;
const ll lnf = 2e18;

int c, n, m, d, q;
int w[maxn];
vector<pair<int,int>> edges[maxn];
ll f[505][505];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	pre(i, 1, m)
		scanf("%d", &w[i]);
	pre(i, 1, n)
	{
		int k;
		scanf("%d", &k);
		while(k--)
		{
			int a, t;
			scanf("%d%d", &a, &t);
			edges[a].emplace_back(i, t);
		}
	}
	memset(f, 0x3f, sizeof f);
	pre(i, 1, m)
		for(auto y : edges[i])
			for(auto z : edges[i])
				f[y.first][z.first] = min(f[y.first][z.first], (ll)y.second + z.second);
	pre(i, 1, n)
		f[i][i] = 0;
	pre(k, 1, n)
		pre(i, 1, n)
			pre(j, 1, n)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while(q--)
	{
		int st, ed;
		scanf("%d%d", &st, &ed);
		ll ans = lnf;
		for(auto y : edges[st])
			for(auto z : edges[ed])
				ans = min(ans, f[y.first][z.first] + y.second + z.second);
		printf("%lld\n", ans + w[st] + w[ed]);
	}
	return 0;
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
