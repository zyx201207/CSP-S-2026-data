#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5010;
int c, T;
int n, d;
int x[MAXN];
vector<int> g[MAXN];
pair<int, int> cnt[MAXN][MAXN];
void bfs(int st)
{
	queue<pair<int, int> > q;
	q.push({st, 0});
	while(!q.empty())
	{
		int u = q.front().first, dist = q.front().second;
		q.pop();
		if(cnt[st][u].first != 0 && dist > cnt[st][u].first) continue;
		cnt[st][u].first = dist;
		cnt[st][u].second++;
		for(int v : g[u])
		{
			if(cnt[st][v].first != 0 && dist + 1 > cnt[st][u].first) continue;
			q.push({v, dist + 1});
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		{
			cin >> x[i];
			g[i].clear();
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(x[j] - x[i] > d) break;
				g[i].push_back(j);
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				cnt[i][j] = {0, 0};
			}
		}
		for(int i = 1; i < n; i++) bfs(i);
		int res = 0;
		for(int i = 1; i < n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(cnt[i][j].second == 2) res++;
			}
		}
		cout << res << "\n";
	}
	return 0;
}