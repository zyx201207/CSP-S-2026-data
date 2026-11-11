#include<bits/stdc++.h>
#define MX 10000
using namespace std;
struct node
{
	int to;
	int val;
};
vector<node> G[MX + 10];
int w[MX + 10],a[MX + 10][MX + 10],t[MX + 10][MX + 10],k[MX + 10];
int dist[MX + 10][MX + 10];
int vis[MX + 10];
void dfs(int s,int t)
{
	dist[s][s] = 0;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();
		if (vis[])
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int c,m,n,d,q,i,j;
	cin >> c >> n >> m >> d >> q;
	for (i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (i = 1;i <= n;i++)
	{
		cin >> k[i];
		for (j = 1;j <= k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= k[i];j++)
		{
			for (int s = j + 1;s <= k[i];s++)
			{
				G[a[i][j]].push_back({a[i][s],t[i][j] + t[i][s]});
			}
		}
	}
	for (i = 1;i <= m;i++)
	{
		for (j = i + 1;j <= m;j++)
		{
			queue<int> q;
			BFS(i,j);
		}
	}
	while(q--)
	{
		int xr,yr;
		cin >> xr >> yr;
		cout << w[xr] + dist[xr][yr] + w[yr] << endl;
	}
	return 0;
}//不做抵抗了,后悔没直接打T2暴力最短路了..... 
