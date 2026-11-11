#include <bits/stdc++.h>
using namespace std;
long long w[500010],k[505];
bool vis[505],vis2[500010];
int d[505][505];
struct stu
{
	int x;
	long long y;
};
vector<stu> g[500010];
vector<int> g2[500010];
int l,r;
long long ans = 9000000000000000000;
void dfs(int u,long long cnt)
{
	if(cnt >= ans)
	{
		return;
	}
	if(u == r)
	{
		ans = min(ans,1ll * cnt);
		return;
	}
	for(int v:g2[u])
	{
		if(vis2[v] == 1)
		{
			continue;
		}
		vis2[v] = 1;
		long long p2;
		for(auto p:g[v])
		{
			if(p.x == u)
			{
				p2 = p.y;
				break;
			}
		}
		for(auto p:g[v])
		{
			if(p.x == u)
			{
				continue;
			}
			if(vis[p.x])
			{
				continue;
			}
			long long p1 = p.y;
			vis[p.x] = 1;
			dfs(p.x,cnt + p2 + p1);
			vis[p.x] = 0;
		}
		vis2[v] = 0;
	}
	return;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
*/
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++)
		{
			int x;
			long long y;
			cin >> x >> y;
			g[i].push_back({x,y});
			g2[x].push_back(i);
		}
	}
//	if(c <= 11)
//	{
		while(q--)
		{
			memset(vis,0,sizeof(vis));
			memset(vis2,0,sizeof(vis2));
			ans = 9e18;
			cin >> l >> r;
			dfs(l,w[l] + w[r]);
			cout << ans << endl;
		}
//	}
//	else if(c <= 15)
//	{
//		
//	}
	return 0;
 } 
 /*
 0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
 /*输入的第一行包含五个非负整数 c, n, m, d, q，分别表示测试点编号、地铁线路数、
地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。特别地，若 c = 0，则
该测试点为样例。*/