#include <iostream>
#include <vector>
#include <cstdio>
#define ll long long
using namespace std;
const int MAXN = 2e6 + 5;
const int MAXM = 5e3 + 5;
int c, T, n;
ll d, a[MAXN];
vector <int> adj[MAXM];
int solve(int x, int y)
{
	int res = 0;
	int now = x;
	while(now < y)
	{
		if(!adj[now].size())
		{
			return -1;
		}
		now = adj[now][adj[now].size() - 1];
		res++;
	}
	return res;
}
int dfs(int x, int y, int len)
{
	if(!len)
	{
		if(x == y)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int res = 0;
	for(int v : adj[x])
	{
		if(v > y)
		{
			break;
		}
		res += dfs(v, y, len - 1);
	}
	return res;
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while(T--)
	{
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
		}
		for(int i = 1; i <= n; i++)
		{
			adj[i].clear();
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(a[j] - a[i] <= d)
				{
					adj[i].push_back(j);
				}
				else
				{
					break;
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 3; j <= n; j++)
			{
				int len = solve(i, j);
				if(len == -1)
				{
					continue;
				}
				int ls = dfs(i, j, len);
				if(ls == 2)
				{
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// 什么叫写了一个小时只能确定拿 8 分（剩下 12 分无疑是难以确定会不会 T 的） 
