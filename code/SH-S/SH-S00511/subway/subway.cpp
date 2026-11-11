#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
	int x, step;
};

const int M = 5e5 + 5, N = 505;
int OOO, n, m, d, q, w[M], k[N], xx, yy, vis[M], ans;
unordered_map<int, unordered_map<int, int> > a, t;
vector<int> v[M];

void bfs()
{
	queue<node> q;
	q.push({xx, w[xx]});
	vis[xx] = w[xx];
	while (!q.empty())
	{
		node now = q.front();
		q.pop();
		if (now.x == yy)
		{
			ans = min(ans, now.step + w[yy]);
			continue;
		}
		if (now.step + w[yy] >= ans) continue;
		for (int i = 0; i < v[now.x].size(); i++)
		{
			int nd = v[now.x][i];
			for (int j = 1; j <= k[nd]; j++)
			{
//				cout << j << " ";
				int nx = a[nd][j];
				if (nx == now.x) continue;
//				cout << nx << " ";
//				cout << t[nd][now.x] << " " << t[nd][nx] << "\n";
				if (vis[nx] <= now.step + t[nd][now.x] + t[nd][nx]) continue;
				vis[nx] = now.step + t[nd][now.x] + t[nd][nx];
//				cout << nx << " " << nd << "\n";
				q.push({nx, vis[nx]});
			}
		}
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> OOO >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			int aa, tt;
			cin >> aa >> tt;
			a[i][j] = aa, t[i][a[i][j]] = tt;
			v[aa].push_back(i);
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> xx >> yy;
		for (int j = 1; j <= m; j++) vis[j] = 1e18;
		ans = 1e18;
		bfs();
		cout << ans << "\n";
	}
	return 0;
}

