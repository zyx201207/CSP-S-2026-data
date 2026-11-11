#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,k;

int tr[15][15];
int g[15][15];

int popcount(int x)
{
	int cnt = 0;
	while(x) cnt += (x & 1),x >>= 1;
	return cnt;
}

int color[15];

void dfs(int u,int fa,int cl,int msk)
{
	color[u] = cl;
	for(int i = 1;i <= n;i++)
	{
		if(i == u || i == fa) continue;
		if(g[u][i] != 1) continue;
		if(!((msk >> (i - 1)) & 1)) continue;
		dfs(i,u,cl,msk);
	}
}

void Main()
{
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++) tr[i][j] = (i != j) * (int)1e9,g[i][j] = (i != j) * (int)1e9;
	}
	for(int i = 1;i < n;i++)
	{
		int u,v;
		cin >> u >> v;
		tr[u][v] = tr[v][u] = 1;
		g[u][v] = g[v][u] = 1;
	}
	for(int p = 1;p <= n;p++)
	for(int x = 1;x <= n;x++)
	for(int y = 1;y <= n;y++)
	{
		tr[x][y] = min(tr[x][y],tr[x][p] + tr[p][y]);
	}
	int res = 2e9;
	for(int msk = 1;msk <= (1 << n) - 1;msk++)
	{
//		cout << " " << msk << endl;
		if(popcount(msk) != k) continue;
		for(int j = 1;j <= n;j++) color[j] = 0;
		int cnt = 0;
		for(int j = 1;j <= n;j++)
		{
			if(((msk >> (j - 1)) & 1) && !color[j])
			{
				dfs(j,0,++cnt,msk);
			}
		}
		if(cnt > 2) continue;
		int RO = -2e9;
		for(int i = 1;i <= n;i++)
		{
			int DIS = 2e9;
			for(int j = 1;j <= n;j++)
			{
				if(!((msk >> (j - 1)) & 1)) continue;
				DIS = min(DIS,tr[i][j]);
//				cout << "  " << i << " " << j << " " << tr[i][j] << endl;
			}
			RO = max(RO,DIS);
		}
		res = min(res,RO);
	}
	cout << res << endl;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c;
	int t;
	cin >> c >> t;
	while(t--)
	{
		if(0 <= c && c <= 3)
		{
			Main();
		}
	}
	return 0;
} 
