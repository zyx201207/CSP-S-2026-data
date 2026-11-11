#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
int test_id,n,m,a[500005],max_d,q,dis[505][505];
vector<array<int,2> > v[500005];

inline void Min(int &x,int y)
{
	if (y < x) x = y;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> test_id >> n >> m >> max_d >> q;
	for (int i = 1;i <= m;i++) cin >> a[i];
	int qtt,x,y;
	for (int i = 1;i <= n;i++)
	{
		cin >> qtt;
		while (qtt--)
		{
			cin >> x >> y;
			v[x].push_back({i,y});
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++) dis[i][j] = INF;
	}
	for (int i = 1;i <= n;i++) dis[i][i] = 0;
	for (int i = 1;i <= m;i++)
	{
		for (auto j:v[i])
		{
			for (auto k:v[i]) Min(dis[j[0]][k[0]],j[1]+k[1]);
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			for (int k = 1;k <= n;k++) Min(dis[j][k],dis[j][i]+dis[i][k]);
		}
	}
	while (q--)
	{
		cin >> x >> y;
		int ans = INF;
		for (auto j:v[x])
		{
			for (auto k:v[y]) Min(ans,a[x]+a[y]+j[1]+k[1]+dis[j[0]][k[0]]);
		}
		cout << ans << '\n';
	}
	return 0;
}
