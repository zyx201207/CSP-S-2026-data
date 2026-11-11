#include<bits/stdc++.h>

using namespace std;
#define int long long

struct pos
{
	int cnt, r, c;
};

int c, n, m, d, qq, t[1001][1001], w[500001], s[2001][2001], vis[2001][2001], k[1001];
vector<int>v[500001];
queue <pos>q;

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> qq;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			int a;
			cin >> a;
			cin >> t[a][i];
			s[i][j] = a;
			v[a].push_back(i);
		}
	}
	while(qq--)
	{
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
		for (int i = 0; i < v[x].size(); i++)
		{
			pos p;
			p.cnt = t[x][v[x][i]];
			p.r = x;
			p.c = v[x][i];
			q.push(p);
		}
		while (!q.empty())
		{
			pos p1 = q.front();
			q.pop();
			if (p1.r == y)
			{
				ans = min(ans, p1.cnt + t[p1.r][p1.c]);
				continue;
			} 
			vis[p1.r][p1.c] = 1;
			for (int i = 1; i <= k[p1.c]; i++)
			{
				if (vis[s[p1.c][i]][p1.c] == 0)
				{
					pos p2;
					p2.cnt = p1.cnt;
					p2.r = s[p1.c][i];
					p2.c = p1.c; 
					q.push(p2);
				}
			}
			for (int i = 0; i < v[p1.r].size(); i++)
			{
				if (vis[p1.r][v[p1.r][i]] == 0)
				{
					pos p2;
					p2.cnt = p1.cnt + t[p1.r][p1.c] + t[p1.r][v[p1.r][i]];
					p2.r = p1.r;
					p2.c = v[p1.r][i]; 
					q.push(p2);
				}
			}
		}
		cout << ans + w[x] + w[y] << endl;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++) vis[i][j] = 0;
		}
	}
	return 0;
 } 
 
