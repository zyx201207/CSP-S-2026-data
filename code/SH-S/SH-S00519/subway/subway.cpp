#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

long long w[500002];
int k[502];
vector<pair<int,long long>>v[502];
vector<int>g[500002];
bool mem[500002];
int c,n,m,d,q;
void solve1()
{
	while (q--)
	{
		memset(mem,0,sizeof(mem));
		int x,y;
		cin >> x >> y;
		priority_queue<pair<long long,int>>pq;
		pq.push({0,x});
		long long val,u;
		while (!pq.empty())
		{
			u = pq.top().second;
			val = pq.top().first;
			pq.pop();
			if (mem[u]) continue;
			mem[u] = 1;
			if (u == y) break;
			if (g[u].size() == 1 && u != x) continue;
			for (int i = 0;i < g[u].size();i++)
			{
				int t = g[u][i],k;
				for (int j = 0;j < v[t].size();j++)
				{
					if (v[t][j].first == u) 
					{
						k = j;
						break;
					}
				}
				for (int j = 0;j < v[t].size();j++)
				{
					if (!mem[v[t][j].first]) pq.push({val-v[t][k].second-v[t][j].second,v[t][j].first});
				}
			}
		}
		cout << w[x]+w[y]-val << "\n";
	}
}
void solve2()
{
	while (q--)
	{
		int x,y;
		cin >> x >> y;
		long long num = w[x]+w[y];
		if (g[x].size() == 2 || g[x][0] == g[y][0])
		{
			for (int i = 0;i < v[g[y][0]].size();i++)
			{
				if (v[g[y][0]][i].first == x || v[g[y][0]][i].first == y) num += v[g[y][0]][i].second;
			}
		}
		else if (g[y].size() == 2)
		{
			for (int i = 0;i < v[g[x][0]].size();i++)
			{
				if (v[g[x][0]][i].first == x || v[g[x][0]][i].first == y) num += v[g[x][0]][i].second;
			}
		}
		else 
		{
			for (int i = 0;i < v[g[y][0]].size();i++)
			{
				if (v[g[y][0]][i].first == y || g[v[g[y][0]][i].first].size() == 2) num += v[g[y][0]][i].second;
			}
			for (int i = 0;i < v[g[x][0]].size();i++)
			{
				if (v[g[x][0]][i].first == x || g[v[g[x][0]][i].first].size() == 2) num += v[g[x][0]][i].second;
			}
		}
		cout << num << "\n";
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for (int j = 1;j <= k[i];j++)
		{
			int a,t;
			cin >> a >> t;
			v[i].push_back({a,t});
			g[a].push_back(i);
		}
	}
	if (c <= 15) solve1();
	else if (c >= 20) solve2();
	return 0;
}
