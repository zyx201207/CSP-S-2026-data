#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll read()
{
	ll f = 1, x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + (ch ^ 48);
		ch = getchar();
	}
	return f * x;
}

inline void write(ll x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

#define DEBUG 0

#if DEBUG
#define dbg(x) cerr << #x << ":" << x << '\n'
#else
#define dbg(x)
#endif

constexpr int N = 2e6 + 2;
ll x[N];
// ll sum[N];
vector<pair<int, long long>> g[N];
int d;
ll cnt[N];
ll dis[N];
bool inq[N];

void bfs(int u)
{
	queue<int> q;
	q.push(u);
	dis[u] = 0;
	cnt[u] = 1;
	inq[u] = true;
	while (!q.empty())
	{
		int f = q.front();
		q.pop();
		inq[f] = false;
		for (auto p:g[f])
		{
			if (p.second > d)
				continue;
			if (dis[p.first] > dis[f] + 1)
			{
				dis[p.first] = dis[f] + 1;
				cnt[p.first] = cnt[f];
				if (!inq[p.first])
				{
					q.push(p.first);
					inq[p.first] = true;
				}
			}
			else if (dis[p.first] == dis[f] + 1)
				cnt[p.first] = cnt[f] + 1;
		}
	}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t, n;
	c = read(), t = read();
	ll cntt;
	while (t--)
	{
		cntt = 0;
		n = read(), d = read();
		for (int i = 1; i <= n; ++i)
		{
			dis[i] = 0x3f3f3f3f;
			inq[i] = false;
		}
		for (int i = 1; i <= n; ++i)
			x[i] = read();
		for (int l = 1; l < n; ++l)
			for (int r = l + 1; r <= n; ++r)
				g[l].push_back({r, x[r] - x[l]});
		for (int l = 1; l < n; ++l)
		{
			bfs(l);
			for (int i = 1; i <= n; ++i)
			{
				dis[i] = 0x3f3f3f3f;
				inq[i] = false;
			}
			for (int r = l + 1; r <= n; ++r)
				if (cnt[r] == 2)
					cntt++;
		}
		cout << cntt << '\n';
	}
	return 0;
}
