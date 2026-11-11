#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e6+5,inf = 1e9;
int x[maxn],cnt[maxn],dis[maxn];
vector<int> G[maxn];
queue<int> q;
void bfs()
{
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v:G[u])
		{
			if (dis[u]+1 <= dis[v])
			{
				if (dis[u]+1 < dis[v])
				{
					dis[v] = dis[u]+1;
					cnt[v] = 1;
				}
				else cnt[v]++;
				q.push(v);
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin >> c >> t;
	while (t--)
	{
		int n,d,ans = 0;
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			G[i].clear();
		}
		for (int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		bool flag = true;
		for (int i = 3;i <= n;i++)
		{
			if (x[i]-x[i-1] != x[i-1]-x[i-2])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			int c = x[2]-x[1];
			if (d <= c) cout << 0;
			else
			{
				int k = d/c*2-1;
				if (k <= 0) cout << 0;
				else cout << max(n-k,0ll);
			}
		}
		else
		{
			for (int i = 1;i <= n;i++)
			{
				for (int j = 1;j < i;j++)
				{
					if (x[i]-x[j] <= d) G[j].push_back(i);
				}
			}
			for (int i = 1;i <= n;i++)
			{
				dis[i] = inf;
			}
			for (int i = 1;i <= n;i++)
			{
				dis[i] = 0;
				q.push(i);
				bfs();
				for (int j = i+1;j <= n;j++)
				{
					if (cnt[j] == 2) ans++;
				}
				for (int j = i;j <= n;j++)
				{
					cnt[j] = 0;
					dis[j] = inf;
				}
			}
			cout << ans;
		}
		cout << endl;
	}
	return 0;
}