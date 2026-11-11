#include <bits/stdc++.h>
using namespace std;

int w[500010];
vector<pair<int,int>> e[510];
int dis[500010];

void dfs(int x)
{
	priority_queue<pair<int,int>> q;
	dis[x] = w[x];
	q.push({dis[x],x});
	while (q.size())
	{
		int now = q.top().second;
		q.pop();
		for (auto it: e[now])
		{
			if (e[now]) dis[now]++;
		}
	}
}

int main()
{
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int aa,bb;
			cin >> aa >> bb;
			e[aa].push_back({i,bb});
		}
	}
	while (q--)
	{
		int x,y;
		cin >> x >> y;
		dfs(x);
	}
	return 0;
}
