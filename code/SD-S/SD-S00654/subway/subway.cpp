#include<bits/stdc++.h>
using namespace std;
int c , n , m , d , q;
int gra[int(1e3 + 5)][int(1e3 + 5)] , dis[int(1e3 + 5)] , vis[int(1e3 + 5)];
void dij(int s)
{
	queue<int> q;
	int u , v;
	u = s , v = s;
	dis[s] = gra[u][v];
	q.push(s);
	vis[s] = 1;
	while(!q.empty())
	{
		for(int i = 1;i <= m + n;i = i + 1)
		{
			if(gra[q.front()][i] != INT_MAX && gra[i][q.front()] != INT_MAX && vis[i] == 0)
			{
				vis[i] = 1;
				dis[i] = gra[q.front()][i] + dis[q.front()];
				q.push(i);
			}
			if(vis[i] == 1)
			{
				if(dis[i] > 1ll * dis[q.front()] + gra[q.front()][i] && dis[q.front()] > 1ll * dis[i] + gra[i][q.front()])
				{
					dis[i] = dis[q.front()] + gra[q.front()][i];
				}
			}
		}
		q.pop();
	}
}
int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	if(c != 0 || 1)
	{
		for(int i = 1;i <= n + m + 1;i = i + 1)
		{
			for(int j = 1;j <= n + m + 1;j = j + 1)
			{
				gra[i][j] = INT_MAX;
			}
			dis[i] = INT_MAX;
		}
		for(int i = 1;i <= m;i = i + 1)
		{
			int x;
			cin >> x;
			gra[i][i] = x;
			dis[i] = x;
		}
		for(int i = m + 1;i <= m + n;i = i + 1)
		{
			int k;
			cin >> k;
			for(int j = 1;j <= k;j = j + 1)
			{
				int x , y;
				cin >> x >> y;
				gra[i][x] = y;
				gra[x][i] = y;
			}
		}
		while(q--)
		{
			for(int i = 1;i <= n + m;i = i + 1)
			{
				if(i <= m)
				{
					dis[i] = gra[i][i];
				}
				else
				{
					dis[i] = INT_MAX;
				}
				vis[i] = 0;
			}
			int s , e;
			cin >> s >> e;
			int t = gra[e][e];
			dij(s);
			cout << dis[e] + t << endl;
		}
	}
	return 0;
}
