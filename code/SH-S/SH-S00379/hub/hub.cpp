#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long LL;
const int N = 10005, M = 10005;
int c, t, n, k, s, e, x, y, mn, ans, cnt, f[N], head[N], nxt[M], to[M], q[N], dis[N];
bool vis[N];
void add(int x, int y)
{
//	}
	nxt[++cnt] = head[x];
	head[x] = cnt;
	to[cnt] = y;
//	cout << head[3] << endl;
//	if (x == 3)
////	{
//		cout << "add " << x << " " << y << " " << cnt << " " << nxt[cnt] << " " << head[x] << endl;
}
int find(int x)
{
	return f[x] == x ? x : f[x] = find(f[x]);
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while (t--)
	{
		memset(head, 0, sizeof(head));
		cnt = 0;
		mn = 1e9;
		cin >> n >> k;
		for (int i = 1; i < n; i++)
		{
			cin >> x >> y;
			add(x, y);
			add(y, x);
		}
		for (int i = 0; i < (1 << n); i++)
		{
			if (__builtin_popcount(i) == k)
			{
				for (int j = 1; j <= n; j++)
				{
					f[j] = j;
				}
				for (int j = 1; j <= n; j++)
				{
					if (i & (1 << (j - 1)))
					{
						for (int k = head[j]; k; k = nxt[k])
						{
							if (i & (1 << (to[k] - 1)))
							{
								f[find(i)] = find(to[k]);
							}
						}
					}
				}
//				cout << "head[3] " << head[3] << endl;
				ans = 0;
				for (int j = 1; j <= n; j++)
				{
					if (i & (1 << (j - 1)))
					{
						ans += (find(j) == j);
					}
				}
				if (ans <= 2)
				{
					ans = 0;
					s = 1, e = 0;
					for (int j = 1; j <= n; j++)
					{
						vis[j] = false;
						if (i & (1 << (j - 1)))
						{
							vis[j] = true;
							dis[j] = 0;
							q[++e] = j;
						}
					}
					while (s <= e)
					{
						x = q[s++];
						ans = max(ans, dis[x]);
//						if (i == 19) cout << x << " " << dis[x] << endl;
						for (int j = head[x]; j; j = nxt[j])
						{
//							if (i == 19)cout << "edge " << j << " " << nxt[j] << " " << x << " " << to[j] << endl;
							if (!vis[to[j]])
							{
								vis[to[j]] = true;
								dis[to[j]] = dis[x] + 1;
								q[++e] = to[j];
							}
						}
					}
//					if (i == 19)cout << i << " " << ans << endl;
					mn = min(mn, ans);
				}
			}
		}
		cout << mn << endl;
	}
	return 0;
}
