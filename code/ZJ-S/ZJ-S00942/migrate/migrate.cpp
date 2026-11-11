#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 2e6 + 10;
ll c, t, n, d, a[maxn], l[maxn], r[maxn], dis[maxn], discnt[maxn], ans;
queue<ll> q;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while (t--)
	{
		ans = 0;
		cin >> n >> d;
		for (ll i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (ll i = 1, j = 1; i <= n; i++)
		{
			while (j < i && a[i] - a[j] > d)
			{
				j++;
			}
			l[i] = j;
		}
		for (ll i = n, j = n; i; i--)
		{
			while (j > i && a[j] - a[i] > d)
			{
				j--;
			}
			r[i] = j;
		}
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j <= n; j++)
			{
				dis[j] = 1e18;
				discnt[j] = 0;
			}
			while (q.size())
			{
				q.pop();
			}
			q.push(i);
			dis[i] = 0;
			discnt[i] = 1;
			while (q.size())
			{
				ll u = q.front();
				q.pop();
				for (ll v = l[u]; v <= r[u]; v++)
				{
					if (dis[v] > dis[u] + 1)
					{
						dis[v] = dis[u] + 1;
						discnt[v] = discnt[u];
						q.push(v);
					}
					else if (dis[v] == dis[u] + 1)
					{
						discnt[v] += discnt[u];
					}
				}
			}
			for (ll j = i; j <= n; j++)
			{
				ans += discnt[j] == 2;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}