#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long a[2000002], dis[5005], cnt[5005];
bool vis[5005], ans[5005][5005];
vector <long long> g[2000002];
queue <long long> q;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	while (t--)
	{
		long long n, d;
		cin >> n >> d;
		for (long long i = 1; i <= n; ++i)
		{
			cin >> a[i];
			g[i].clear();
			for (long long j = 1; j <= n; ++j)
			{
				ans[i][j] = false;
			}
		}
		for (long long i = 1; i <= n; ++i)
		{
			for (long long j = i + 1; j <= n; ++j)
			{
				if (a[j] - a[i] <= d)
				{
					//cout << i << " " << j << endl;
					g[i].push_back(j);
					g[j].push_back(i);
				}
				else
				{
					break;
				}
			}
		}
		long long ans1 = 0;
		for (long long i = 1; i <= n; ++i)
		{
			for (long long j = 1; j <= n; ++j)
			{
				dis[j] = 1e9;
				cnt[j] = 0;
				vis[j] = false;
			}
			q.push(i);
			dis[i] = 0;
			cnt[i] = 1;
			vis[i] = true;
			while (q.size() > 0)
			{
				long long now = q.front();
				q.pop();
				vis[now] = true;
				for (long long j = 0; j < g[now].size(); ++j)
				{
					long long nxt = g[now][j];
					if (vis[nxt] == false)
					{
						if (dis[now] + 1 < dis[nxt])
						{
							cnt[nxt] = cnt[now];
							q.push(nxt);
							dis[nxt] = dis[now] + 1;
						}
						else if (dis[now] + 1 == dis[nxt])
						{ 
							cnt[nxt] += cnt[now];
						}
					}
				}
			}
			for (long long j = 1; j <= n; ++j)
			{
				if (cnt[j] == 2)
				{
					ans[i][j] = true;
					ans[j][i] = true;
				}
			}
		}
		for (long long i = 1; i <= n; ++i)
		{
			for (long long j = i + 1; j <= n; ++j)
			{
				if (ans[i][j] == true)
				{
					ans1 += 1;
				}
			}
		}
		cout << ans1 << "\n";
	}
	
	return 0;
}
