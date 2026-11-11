#include<bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

int c, n, m, d, q;

namespace Sub1
{
	const int N = 501, M = 1000 + 10, E = 5e5 + 10, INF = 1e9 + 7; 
	
	int w[M];
	int k[N];
	int a[N][M], t[N][M];
//	vector<int> zhantai[M];
	vector<PII> e[E];
	
	int dist[E];
	bool st[E];
	vector<int> nod;
	
	void dijkstra(int s)
	{
		priority_queue<PII> q;
		for(auto i : nod)
		{
			dist[i] = INF;
			st[i] = false;
		}
		dist[s] = 0;
		
		q.push({0, s});
		
		while(q.size())
		{
			int u = q.top().second;
			q.pop();
			
			if(st[u]) continue;
			st[u] = true;
			
			for(auto i : e[u])
			{
				int v = i.second, w = i.first;
				if(dist[v] > dist[u] + w)
				{
					dist[v] = dist[u] + w;
					q.push({-dist[v], v});
				}
			}
		}
	}
	
	void Solve1()
	{
		for(int i = 1; i <= m; i ++)
		{
			scanf("%d", &w[i]);
		}
		for(int i = 1; i <= n; i ++)
		{
			scanf("%d", &k[i]);
			
			for(int j = 1; j <= k[i]; j ++)
			{
				scanf("%d%d", &a[i][j], &t[i][j]);
//				zhantai[a[i][j]].push_back(i);
				e[a[i][j]].push_back({t[i][j], a[i][j] * 1000 + i});
				e[a[i][j] * 1000 + i].push_back({t[i][j], a[i][j]});
				
				nod.push_back(a[i][j]);
				nod.push_back(a[i][j] * 1000 + i);;
			}
		}
		
//		for(auto i : nod)
//		{
//			printf("%d ", i);
//		}
//		puts("");
		
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= k[i] - 1; j ++)
			{
				e[a[i][j] * 1000 + i].push_back({0, a[i][j + 1] * 1000 + i});
				e[a[i][j + 1] * 1000 + i].push_back({0, a[i][j] * 1000 + i});
			}
		}
		
//		for(auto i : nod)
//		{
//			printf("%d: ", i);
//			for(auto j : e[i])
//			{
//				printf("%d ", j.second);
//			}
//			puts("");
//		}
		
		int ans, xr, yr;
		
		while(q --)
		{
			scanf("%d%d", &xr, &yr);
			ans = w[xr] + w[yr];
			
			dijkstra(xr);
			
			ans += dist[yr];
			
			printf("%d\n", ans);
		}
		
		return;
	}
}

namespace Sub2
{
	const int N = 501, M = 5e5 + 10; 
	
	int w[M];
	int k[N];
	vector<int> a[N], t[N];
	
	int colore[M], jiaodian[10];
	int id[M];
	
	void Solve2()
	{
		for(int i = 1; i <= n; i ++)
		{
			a[i].push_back(-1);
			t[i].push_back(-1);
		}
		
		for(int i = 1; i <= m; i ++)
		{
			scanf("%d", &w[i]);
		}
		for(int i = 1; i <= n; i ++)
		{
			scanf("%d", &k[i]);
			
			for(int j = 1; j <= k[i]; j ++)
			{
				int A, T;
				scanf("%d%d", &A, &T);
				
				a[i].push_back(A);
				t[i].push_back(T);
				
				if(colore[A] == 0)
				{
					colore[A] = i;
					id[A] = j;
				}
				else
				{
					jiaodian[colore[A]] = id[A];
					jiaodian[i] = j;
					colore[A] = 3;
				}
			}
		}
		
		int ans, xr, yr;
		
		while(q --)
		{
			scanf("%d%d", &xr, &yr);
			ans = w[xr] + w[yr];
			
			if(colore[xr] == colore[yr])
			{
				ans += t[colore[xr]][id[xr]] + t[colore[yr]][id[yr]];
			}
			else if(colore[xr] == 3)
			{
				ans += t[colore[yr]][id[xr]] + t[colore[yr]][id[yr]];
			}
			else if(colore[yr] == 3)
			{
				ans += t[colore[xr]][id[xr]] + t[colore[xr]][id[yr]];
			}
			else
			{
				ans += t[colore[xr]][id[xr]] + t[colore[xr]][jiaodian[colore[xr]]];
				ans += t[colore[yr]][jiaodian[colore[yr]]] + t[colore[yr]][id[yr]];
			}
			
			printf("%d\n", ans);
		}
		
		return;
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	
	if(c <= 11)
	{
		Sub1 :: Solve1();
	}
	else if(c >= 20 && c <= 21)
	{
		Sub2 :: Solve2();
	}
	
	return 0;
}