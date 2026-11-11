#include <bits/stdc++.h>

using namespace std;
#define MAXN 2010000
#define LL long long

int n, k;
vector<int> g[MAXN];
int keyx, keyy;
int max_deep[MAXN];
int x[MAXN], y[MAXN];
int mid;

bool check(int mid)
{
	vector<int> deg(n + 1);
	vector<int> dis(n + 1);
	vector<int> vis(n + 1);
	for (int i = 1; i < n; i++)
	{
		deg[x[i]]++;
		deg[y[i]]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] <= 1)
			q.push(i);
	}
	int ans = 0;
	while (!q.empty())
	{
		int f = q.front();
		q.pop();
		if (deg[f] == 0)
			continue;
		vis[f] = 1;
		if (dis[f] < mid)
		{

			ans ++;
			for (auto p: g[f])
			{
				if (p == keyx && f == keyy || p == keyy && f == keyx)
					continue;
				deg[p]--;
				dis[p] = max(dis[p], dis[f] + 1);
				if (deg[p] <= 1)
					q.push(p);
			}
		}
	}
	// cout << mid << ' ' << ans << endl;
	return ans >= n - k;
}

int sss()
{
	int l = 0, r = n;
	while (l != r)
	{
		mid = (l + r) / 2;
		if (check(mid))
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return r;
}

void work()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		g[i].clear();
	}
	for (int i = 1; i < n ;i++)
	{
		cin >> x[i] >> y[i];
		g[x[i]].push_back(y[i]);
		g[y[i]].push_back(x[i]);
	}
	int ans = n;
	for (int i = 1; i < n; i++)
	{
		keyx = x[i];
		keyy = y[i];
		x[i] = 0;
		y[i] = 0;
		ans = min(ans, sss());

		x[i] = keyx;
		y[i] = keyy;
	}
	cout << ans << endl;
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
		work();
	return 0;
}