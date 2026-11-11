#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 502 , N = 5e5 + 2;
int c , n , m , d , q , k , u , v;
ll w[N] , w1 , dis[M][M] , ans , minn;
vector <int> t[N];
vector<pair<int , ll> > l[M];
void Floyd()
{
	for (int k = 1;k <= n;k ++)
		for (int i = 1;i <= n;i ++)
			for (int j = 1;j <= n;j ++)
				if (dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
}
int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i ++) cin >> w[i];
	for (int i = 1;i <= n;i ++)
	{
		cin >> k;
		for (int j = 1;j <= k;j ++)
		{
			cin >> v >> w1;
			l[v].push_back({i , w1});
		}
	}
	memset(dis , 0x3f , sizeof(dis));
	for (int i = 1;i <= m;i ++)
		for (int j = 0;j < int(l[i].size());j ++)
			for (int k = j + 1;k < int(l[i].size());k ++)
			{
				int v1 = l[i][j].first , v2 = l[i][k].first;
				ll w1 = l[i][j].second , w2 = l[i][k].second;
				dis[v1][v2] = dis[v2][v1] = w1 + w2;
			}
	for (int i = 1;i <= n;i ++) dis[i][i] = 0;
	Floyd();
	while (q --)
	{
		cin >> u >> v;
		ans = w[u] + w[v] , minn = 9e18;
		for (int i = 0;i < int(l[u].size());i ++)
			for (int j = 0;j < int(l[v].size());j ++)
				minn = min(minn , dis[l[u][i].first][l[v][j].first] + l[u][i].second + l[v][j].second);
		cout << ans + minn << "\n";
	}
	return 0;
}
