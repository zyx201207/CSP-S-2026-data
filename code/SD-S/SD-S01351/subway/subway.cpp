#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, D, q;
int w[500005], k[505], x, y, ans, d[505];
//vector<int> a[505], t[505];
vector<int> g[505], a[500005], t[500005], tt[505];
bool bj[505];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> D >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			int A, T;
			cin >> A >> T;
//			a[i].push_back(A);
//			t[i].push_back(T);
			a[A].push_back(i);
			t[A].push_back(T);
		}
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 0;j < a[i].size();j++)
		{
			for(int l = j+1;l < a[i].size();l++)
			{
				g[a[i][j]].push_back(a[i][l]);
				g[a[i][l]].push_back(a[i][j]);
				tt[a[i][j]].push_back(t[i][j]+t[i][l]);
				tt[a[i][l]].push_back(t[i][j]+t[i][l]);
			}
		}
	}
	while(q--)
	{
		cin >> x >> y;
		ans = 1e18;
		for(int j = 0;j < a[x].size();j++)
		{
			for(int i = 1;i <= n+1;i++)
			{
				d[i] = 1e18;
			}
			memset(bj, 0, sizeof(bj));
			d[a[x][j]] = 0; 
			priority_queue<pair<int, int>> maxheap;
			maxheap.push({0, a[x][j]});
			while(!maxheap.empty())
			{
				if(bj[maxheap.top().second])
				{
					maxheap.pop();
					continue;
				}
				bj[maxheap.top().second] = 1;
				pair<int, int> c = maxheap.top();
				maxheap.pop();
				for(int i = 0;i < g[c.second].size();i++)
				{
					if(d[g[c.second][i]] > -c.first + tt[c.second][i])
					{
						d[g[c.second][i]] = -c.first + tt[c.second][i];
						maxheap.push({-d[g[c.second][i]], g[c.second][i]});
					}
				}
			}
			for(int i = 0;i < a[y].size();i++)
			{
				ans = min(ans, d[a[y][i]] + w[x] + w[y] + t[x][j] + t[y][i]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
