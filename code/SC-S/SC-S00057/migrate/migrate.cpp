# include <bits/stdc++.h>
using namespace std;
int vis[100012];
int n, a[100012], d;
int f[100012], ans;
vector <int> e[100012];
struct node
{
	int v, w;
	bool operator < (const node &x)
	{
		return v < x.v;
	}
};
bool check (int beg, int end)
{
	queue <int> q;
	q.push (beg);
	vis[beg] = 0;
	while (!q.empty ())
	{
		int u = q.front (); q.pop ();
		for (int i = 0; i < e[u].size (); i ++)
		{
			int v = e[u][i];
			vis[v] ++;
			q.push (v);
		}
	}
	return vis[end] == 2;
}
int main ()
{
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios :: sync_with_stdio (NULL);
	cin.tie (0x0), cout.tie (0x0);
	int c, t; cin >> c >> t;
	while (t --)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		for (int i = 1; i <= n; i ++)
		{
			for (int j = i + 1; j <= n; j ++)
			{
				if (a[j] - a[i] <= d)
				{
					e[i].push_back (j);
				}
			}
		}
		for (int i = 1; i <= n; i ++)
		{
			for (int j = i + 1; j <= n; j ++)
			{
				if (check (i, j))
				{
					ans ++;
				}
			}
		}
		cout << ans << endl;
	}
}
