#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	int step;
	const operator < (node n2)const
	{
		return step < n2.step;
	}
};
int c, t;
int n, d;
int a[2000005];
int vis[2000005];
vector<int> edge[2000005];
int ans = 0;
void djk(int st, int en)
{
	memset(vis, 0, sizeof(vis));
	priority_queue <node> pq;
	node s;
	s.num = st;
	s.step = 0;
	pq.push(s);
//	vis[st] = 1;
	int minn = INT_MAX;
	int cnt = 0;
	while (!pq.empty())
	{
		node u = pq.top();
		pq.pop();
		if (u.num == en)
		{
			if (minn > u.step)
			{
				cnt = 1;
				minn = u.step;
			}
			else if (minn == u.step)
			{
				cnt ++;
			}
			if (cnt > 2)
			{
				cnt = 0;
				break;
			}
			continue;
		}
//		if (vis[u.num])
//		{
//			continue;
//		}
		for (int i = 0; i < edge[u.num].size(); i ++)
		{
			if (!vis[edge[u.num][i]])
			{	
				node v;
				v.num = edge[u.num][i];
				v.step = u.step + 1;
//				cout << u.num << " " << v.num << "\n";
				pq.push(v);
			}
		}
		vis[u.num] = 1;
	}
//	cout << cnt << "\n";
	if (cnt == 2)
	{
		ans ++;
	}
}
int main()
{
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while (t --)
	{
		memset(a, 0, sizeof(a));
		cin >> n >> d;
		for (int i = 1; i <= n; i ++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i ++)
		{
			int j = i + 1;
			while (a[j] <= a[i] + d && j <= n)
			{
//				cout << i << " " << j << "\n";
				edge[i].push_back(j);
				edge[j].push_back(i);
				j ++;
			}
		}
		ans = 0;
		for (int i = 1; i <= n - 2; i ++)
		{
			for (int j = i + 2; j <= n; j ++)
			{
				djk(i, j);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
priority_queue<int> pq;
*/