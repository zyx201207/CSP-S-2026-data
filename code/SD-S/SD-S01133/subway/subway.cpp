#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 999999999999999999ll;
int n, a[500005], ans, c,  m, d, q, w[500005], k[1005], dis[505][505], t[500005];
vector<pair<int, int> > v[500005];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dis, 0x3f, sizeof(dis));
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= n; i++)
		dis[i][i] = 0; 
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++)
		{
			cin >> a[i] >> t[i];
			v[a[i]].push_back({i, t[i]});
		}
	}
	for(int i = 1; i <= m; i++)
	{
		assert(v[i].size() <= d);
		for(int j = 0; j < v[i].size(); j++)
			for(int k = j+1; k < v[i].size(); k++)
			{
				int A = v[i][j].first, B = v[i][k].first, D = v[i][j].second + v[i][k].second;
				dis[A][B] = min(dis[A][B], D);
				dis[B][A] = min(dis[B][A], D);
			}
	}
//	cout << "OK!";
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		int mn = inf;
		for(auto i:v[x])
			for(auto j:v[y])
				mn = min(mn, dis[i.first][j.first] + i.second + j.second);
		cout << mn+w[x]+w[y] << '\n';
	}
	return 0;
}
