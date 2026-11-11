#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long LL;
const int N = 505, M = 6e5 + 5;
int c, n, m, d, q, x, y, s, en, cnt, w[M], k[N], head[M], nxt[2 * M], to[2 * M], b[2 * M], qu[M];
LL dis[M], e[N][N], ans, z;
priority_queue <pair <LL, int> > pq;
//vector <int> a[N];
void add(int x, int y, int z)
{
	nxt[++cnt] = head[x];
	head[x] = cnt;
	to[cnt] = y;
	b[cnt] = z;
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
//		a[i].reserve(k[i]);
//		a[i].emplace_back(0); 
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> x >> y;
			add(x, m + i, y);
			add(m + i, x, y);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n + m; j++)
		{
			dis[j] = 1e18;
		}
		dis[m + i] = 0;
		if (c >= 12 && c <= 19)
		{
			s = 1, en = 0;
			qu[++en] = m + i;
			while (s <= en)
			{
				x = qu[s++];
				for (int i = head[x]; i; i = nxt[i])
				{
					if (dis[x] + b[i] < dis[to[i]])
					{
						dis[to[i]] = dis[x] + b[i];
						qu[++en] = to[i];
					}
				}
			}
		}
		else
		{
			pq.push(make_pair(0, m + i));
			while (!pq.empty())
			{
				tie(z, x) = pq.top();
				pq.pop();
				if (-z != dis[x])
				{
					break;
				}
				for (int i = head[x]; i; i = nxt[i])
				{
					if (dis[x] + b[i] < dis[to[i]])
					{
						dis[to[i]] = dis[x] + b[i];
						pq.push(make_pair(-dis[to[i]], to[i]));
					}
				}
			}
		}
		for (int j = 1; j <= n; j++)
		{
			e[i][j] = dis[m + j];
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> x >> y;
		ans = 1e18;
		for (int j = head[x]; j; j = nxt[j])
		{
			for (int k = head[y]; k; k = nxt[k])
			{
//				cout << to[j] << " " << to[k] << " " << b[j] << " " << b[k] << " " << e[to[j]][to[k]] << " " << w[x] << " " << w[y] << endl;
				ans = min(ans, b[j] + b[k] + e[to[j] - m][to[k] - m] + w[x] + w[y]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
