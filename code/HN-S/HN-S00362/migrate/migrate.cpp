#include<bits/stdc++.h>
using namespace std;
#define N 2000011
#define int long long
int n, d;
int cnt;
int x[N], l[N], r[N], inl[N], inr[N], res[N], ans;
int cont[N];
void solve()
{
	ans = 0; 
	while (cnt)
		res[cnt--] = 0;
	int lp = 1, rp = 1;
	for (int i = 1; i <= n; i++)
	{
		while (x[lp] < x[i] - d)
			lp++;
		while (rp < n && x[rp + 1] < x[i] + d)
			rp++;
		l[i] = lp;
		r[i] = rp;
		inl[i] = inr[i] = 0;
	}
	for (int i = 2; i + 1 < n; i++)
	{
		int f = i, s = i + 1;
		int nl = f - 1, nr = s + 1;
		if (x[nl] + d < x[nr])
			inl[f] = inr[s] = ++cnt;
	}
	for (int i = 1; i <= n; i++)
		if (inr[r[i]] && i != r[i])
			res[inr[r[i]]]++;
	for (int i = n; i >= 1; i--)
		if (inl[l[i]] && i != l[i])
			ans += res[inl[l[i]]];
	cout << ans << '\n';
}
vector<int> g[N];
int dis[N], tim[N];
void bfs(int s)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		dis[i] = 1e9;
		tim[i] = 0;
	}
	q.push(s);
	dis[s] = 0;
	tim[s] = 1;
	while (q.size())
	{
		int f = q.front();
		q.pop();
		if (tim[f] == 2)
			ans++;
		for (int u : g[f])
		{
			if (dis[f] + 1 == dis[u])
				tim[u] += tim[f];
			if (dis[f] + 1 < dis[u])
			{
				dis[u] = dis[f] + 1;
				tim[u] = tim[f];
				q.push(u);
			}
		}
	}
}
void Solve()
{
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		g[i].clear();
		for (int j = i + 1; j <= n; j++)
			if (x[i] + d >= x[j])
				g[i].push_back(j);
			else
				break;
	}
	for (int i = 1; i <= n; i++)
		bfs(i);
	cout << ans << '\n';
}
int c, t;
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		if (c < 11 && n <= 5000)
			Solve();
		else
			solve();
	}
	return 0;
}

