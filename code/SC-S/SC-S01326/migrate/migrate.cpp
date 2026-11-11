#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

queue<pii> q;
int n, d;
int pos[2000005];
int mn[2000005];

int bfs(int st, int ed)
{
	for(int i = st;i <= ed;i++)
		mn[i] = 1e9;
	mn[st] = 1;
	for(int i = st + 1;i <= ed;i++)
	{
		for(int j = i - 1;j >= st;j--)
		{
			if(pos[i] - pos[j] > d)
				break;
			mn[i] = min(mn[i], mn[j] + 1);  
		}
	}
	
	int cnt = 0, len = mn[ed] - mn[st];
	q.push({st, 0});
	while(q.size())
	{
		int u = q.front().first, w = q.front().second;
		q.pop();
		if(u == ed)
		{
			cnt++;
			continue;
		}
		if(w == len)
			continue;
		for(int v = u + 1;v <= ed;v++)
		{
			if(pos[v] - pos[u] > d)
				break;
			q.push({v, w + 1});
		}
	}
	return cnt;
}

void work()
{
	int ans = 0;
	for(int i = 1;i <= n;i++)
		for(int j = i + 1;j <= n;j++)
			if(bfs(i, j) == 2)
				ans++;
	printf("%d\n", ans);
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int C, t;
	scanf("%d %d", &C, &t);
	while(t--)
	{
		scanf("%d %d", &n, &d);
		for(int i = 1;i <= n;i++)
			scanf("%d", &pos[i]);
		work();
	}
	return 0;
}
