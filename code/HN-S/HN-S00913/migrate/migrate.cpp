#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;
const int INF = 1e9;
int c, t;
long long n;
int dis[MAXN][MAXN];
long long ans;
long long d;
long long cnt[MAXN][MAXN];
long long x[5000007];
vector<int> e[MAXN];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	if(c <= 10)
	{
		queue<int> q;
		while(t --)
		{
			ans = 0;
			cin >> n >> d;
			for(int i = 1; i <= n; i ++)
			{
				cin >> x[i];
			}
			for(int i = 1; i < n; i ++)
			{
				for(int j = i + 1; j <= n; j ++)
				{
					if(x[j] - x[i] > d) break;
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
			for(int i = 1; i <= n; i ++)
			{
				for(int j = 1; j <= n; j ++)
				{
					dis[i][j] = INF;
					cnt[i][j] = 0;
				}
			}
			for(int i = 1; i <= n; i ++)
			{
				while(!q.empty()) q.pop();
				q.push(i);
				dis[i][i] = 0;
				cnt[i][i] = 1;
				while(!q.empty())
				{
					int u = q.front();
					q.pop();
					for(int j = 0; j < (int)(e[u].size()); j ++)
					{
						int v = e[u][j];
						if(dis[i][v] < dis[i][u] + 1) continue;
						cnt[i][v] += cnt[i][u];
						if(dis[i][v] == dis[i][u] + 1) continue;
						dis[i][v] = dis[i][u] + 1;
						q.push(v);
					}
				}
			}
			for(int i = 1; i < n; i ++)
			{
				for(int j = i + 1; j <= n; j ++)
				{
					if(cnt[i][j] == 2) ans ++;
				}
			}
			cout << ans << endl;
			for(int i = 1; i <= n; i ++) e[i].clear();
		}
	}
	if(c == 11 || c == 12)
	{
		while(t --)
		{
			ans = 0;
			cin >> n >> d;
			for(int i = 1; i <= n; i ++)
			{
				cin >> x[i];
			}
			if(n == 1) cout << 0 << endl;
			else if(d / (x[2] - x[1]) < 2) cout << 0 << endl;
			else cout << max(0ll, n + 1ll - 2 * d / (x[2] - x[1])) << endl; 
		}
	}
	return 0;
}
/*
显然最短路径中不会有往回飞的
 
*/
