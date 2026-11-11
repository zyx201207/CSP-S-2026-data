#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using pii = pair<int,int>;
const int maxn = 2e6 + 5;
int n,d,idx,ans;
int a[maxn];
int dis[5005][5005],ways[5005][5005];
queue<int> q;
vector<int> g[maxn];
void bfs(int s)
{
	memset(dis[s],0x3f,sizeof(int) * (n + 5));
	memset(ways[s],0,sizeof(int) * (n + 5));
	dis[s][s] = 0;
	ways[s][s] = 1;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto v : g[u])
		{
			if (dis[s][v] > dis[s][u] + 1)
			{
				dis[s][v] = dis[s][u] + 1;
				ways[s][v] = ways[s][u];
				q.push(v);
			}
			else if (dis[s][v] == dis[s][u] + 1)
				ways[s][v] += ways[s][u];
		}
	}
}
void solve(int _)
{
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i],g[i].clear();
	if (_ > 10)
		cout << "0\n";
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[j] - a[i] <= d)
				g[i].emplace_back(j);
	for (int i = 1; i <= n; i++)
		bfs(i);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans += ways[i][j] == 2;
	cout << ans << '\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _,t;
	cin >> _ >> t;
	while (t--)
		solve(_);
	return 0;
}
/*
6 12
-10 -6 -2 2 6 10
*/