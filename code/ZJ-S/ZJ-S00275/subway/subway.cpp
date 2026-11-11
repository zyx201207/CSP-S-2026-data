#include<bits/stdc++.h>
#define int long long
#define mkp make_pair
#define vc vector
#define pi pair<int, int>
#define INF 461168601842738790
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

constexpr int N = 511;
constexpr int M = 501011;

int cas, n, m, d, Q, tot;
int w[M], pos[M], dis[M], ans[M];
bitset<M> vis;
vc<pi> a[M], qq[M];
priority_queue<pi, vc<pi>, greater<pi> > q;


void Kruskal(int s)
{   
	for (int i = 1; i <= tot; i++)
	{
		dis[i] = INF;
		vis[i] = 0;
	}
	while (!q.empty()) q.pop();
	q.push(mkp(0, s));
	dis[s] = 0;
	
	while (!q.empty())
	{
		int x = q.top().second;
		q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (auto i : a[x])
		{
			if (dis[i.first] > dis[x] + i.second)
			{
				dis[i.first] = dis[x] + i.second;
				q.push(mkp(dis[i.first], i.first));
			}
		}
	}
}

signed main()
{
    IOS;
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> cas >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	tot = m + 1;
	for (int i = 1; i <= n; i++)
	{
		int len;
		cin >> len;
		for (int j = 1; j <= len; j++)
		{
			int x, y;
			cin>> x >> y;
			a[x].push_back(mkp(tot, y));
			a[tot].push_back(mkp(x, y));
		}
		tot++;
	}
	for (int i = 1; i <= Q; i++)
	{
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		qq[x].push_back(mkp(y, i));
	}
	for (int i = 1; i <= m; i++)
	{
		if (qq[i].size()) Kruskal(i);
		for (auto j : qq[i])
		{
			ans[j.second] = w[i] + w[j.first] + dis[j.first];
		}
	}
	for (int i = 1; i <= Q; i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}
/*

*/
/*
#include<bits/stdc++.h>
#define int long long
#define mkp make_pair
#define vc vector
#define pi pair<int, int>
#define INF 461168601842738790
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

constexpr int N = 511;
constexpr int M = 501011;

int cas, n, m, d, Q, tot;
int w[M], pos[M], dis[M], ans[M];
bitset<M> vis;
pi cc[M];
vc<pi> a[M], qq[M];
priority_queue<pi, vc<pi>, greater<pi> > q;


void Kruskal(int s)
{   
	for (int i = 1; i <= tot; i++)
	{
		dis[i] = INF;
		vis[i] = 0;
	}
	while (!q.empty()) q.pop();
	q.push(mkp(0, s));
	dis[s] = 0;
	
	while (!q.empty())
	{
		int x = q.top().second;
		q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (auto i : a[x])
		{
			if (dis[i.first] > dis[x] + i.second)
			{
				dis[i.first] = dis[x] + i.second;
				q.push(mkp(dis[i.first], i.first));
			}
		}
	}
}

signed main()
{
    IOS;
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> cas >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	tot = m + 1;
	for (int i = 1; i <= n; i++)
	{
		int len;
		cin >> len;
		for (int j = 1; j <= len; j++)
		{
			cin>> cc[j].first >> cc[j].second;
		}
		for (int j = 1; j < len; j++)
		{
			a[tot].push_back(mkp(tot + 1, 0));
			a[tot + 1].push_back(mkp(tot, 0));
			a[cc[j].first].push_back(mkp(tot, cc[j].second));
			a[tot].push_back(mkp(cc[j].first, cc[j].second));
			tot++;
		}
		a[cc[len].first].push_back(mkp(tot, cc[len].second));
		a[tot].push_back(mkp(cc[len].first, cc[len].second));
		tot++;
	}
	for (int i = 1; i <= Q; i++)
	{
		int x, y;
		cin >> x >> y;
		qq[x].push_back(mkp(y, i));
	}
	for (int i = 1; i <= m; i++)
	{
		if (qq[i].size()) Kruskal(i);
		for (auto j : qq[i])
		{
			ans[j.second] = w[i] + w[j.first] + dis[j.first];
		}
	}
	for (int i = 1; i <= Q; i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}

*/