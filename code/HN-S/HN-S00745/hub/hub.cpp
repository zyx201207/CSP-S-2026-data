#include<bits/stdc++.h>
using namespace std;
const int N = 114514;
int T, n, k, x, y, hc[N], cnt, f[N], mx, ans;
struct node
{
	int v, h;
}a[N * 2];
void add(int x, int y)
{
	a[++cnt].v = y;
	a[cnt].h = hc[x];
	hc[x] = cnt;
}
void pt(int k, int fa)
{
	if (!f[k])
	{
		return;
	}
	f[k] = 2;
	for (int i = hc[k];i;i = a[i].h)
	{
		if (a[i].v != fa)
		{
			pt(a[i].v, k);
		}
	}
}
int fd(int k, int fa, int d = 0)
{
	if (f[k])
	{
		return d;
	}
	int w = N;
	for (int i = hc[k];i;i = a[i].h)
	{
		if (a[i].v != fa)
		{
			w = min(w, fd(a[i].v, k, d + 1));
		}
	}
	return w;
}
void check()
{
	cnt = 0;
	for (int i = 1;i <= n;i++)
	{
		if (f[i] == 1)
		{
			pt(i, i);
			cnt++;
		}
	}
	if (cnt <= 2)
	{
		mx = 0;
		for (int i = 1;i <= n;i++)
		{
			mx = max(mx, fd(i, i));
		}
		ans = min(ans, mx);
	}
	for (int i = 1;i <= n;i++)
	{
		if (f[i] == 2)
		{
			f[i] = 1;
		}
	}
}
void dfs(int x, int y)
{
	if (x == n)
	{
		if (y == k)
		{
			check();
		}
		return;
	}
	x++;
	dfs(x, y);
	f[x] = 1;
	dfs(x, y + 1);
	f[x] = 0;
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> T >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 1;i < n;i++)
		{
			cin >> x >> y;
			add(x, y), add(y, x);
		}
		ans = N;
		dfs(0, 0);
		cout << ans << "\n";
		cnt = 0;
		for (int i = 1;i <= n;i++)
		{
			hc[i] = 0;
		}
	}
	return 0;
}
