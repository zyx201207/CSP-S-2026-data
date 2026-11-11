#include <bits/stdc++.h>
using namespace std;
vector<int> g[500010];
int x[500010];
struct stu
{
	long long xx;
	int cnt;
};
stu dis[3010][3010];
bool vis[500010];
void dfs(int x,int u)
{
	for(int v:g[u])
	{
		if(vis[v])
		{
			continue;
		}
		vis[v] = 1;
		if(dis[x][v].xx > dis[x][u].xx + 1)
		{
			dis[x][v].xx = dis[x][u].xx + 1;
			dis[x][v].cnt = 1;
		}
		else if((dis[x][v].xx == dis[x][u].xx + 1));
		{
			cout << (dis[x][v].xx == dis[x][u].xx + 1) << endl;
			cout << x << ' ' << v << endl;
			cout << u << ' ' << v << endl;
			dis[x][v].cnt++;
		}
		dfs(x,v);
		vis[v] = 0;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n,d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		{
			cin >> x[i];
			int p = lower_bound(x + 1,x + i + 1,x[i] - d) - x;
			for(int j = p; j <= i; j++)
			{
				if(i == j)
				{
					continue;
				}
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				dis[i][j].xx = 0x3f3f3f3f;
				dis[i][j].cnt = 0;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			dis[i][i].xx = 0;
		}
		cout << 0 << endl;
	}
	return 0;
}