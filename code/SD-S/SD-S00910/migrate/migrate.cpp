#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, d, a[2000005], sum;
vector<int> e[2000005];
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		sum = 0; 
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
			e[i].clear();
		}
		for(int i = 2;i <= n;i++)
		{
			int l = a[i] - d;
			int k = lower_bound(a + 1, a + i, l) - a;
			for(int j = k;j < i;j++)
			{
				e[j].push_back(i);
				e[i].push_back(j);
			}
		}
		for(int x = 1;x <= n;x++)
		{
			vector<bool> st(n + 1, 0);
			vector<int> dist(n + 1, 0);
			vector<int> ans(n + 1, 1);
			queue<int> q;
			q.push(x);
			st[x] = 1;
			while(!q.empty())
			{
				int u = q.front();
				q.pop();
				for(int i = 0;i < e[u].size();i++)
				{
					int v = e[u][i];
					if(!st[v])
					{
						st[v] = 1;
						dist[v] = dist[u] + 1;
						q.push(v);
					}
					else if(dist[v] == dist[u] + 1)
						ans[v]++;
				} 
			}
			for(int i = 1;i <= n;i++)
				if(ans[i] == 2)
					sum++;
		}
		cout << sum / 2 << '\n';
	}
	return 0;
}
