#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 5e3 + 5;
int c, t;
int n;
long long d;
long long ans = 0;
long long x[maxn];
vector<int>G[maxn];
int dist[maxn][maxn];
int dp[maxn][maxn];
void bfs(int n)
{
	queue<int>q;
	q.push(n);
	dist[n][n] = 0;
	dp[n][n] = 1;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < G[now].size(); i++)
		{
			int v = G[now][i];
			if (dist[n][v] > dist[n][now] + 1)
			{
				dist[n][v] = dist[n][now] + 1;
				dp[n][v] = 1;
				q.push(v);
			}
			else if (dist[n][v] == dist[n][now] + 1)
			{
				dp[n][v]++;
				q.push(v);
			}
		}
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		memset(dist, 0x3f, sizeof dist);
		memset(dp, 0, sizeof dp);
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
			vector<int>().swap(G[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (x[j] - x[i] <= d)
				{
					G[i].push_back(j);
				}
				else
				{
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++) bfs(i);
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (dp[i][j] == 2)
				{
					ans += 1;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
