#include <bits/stdc++.h>
using namespace std;

#define int long long

int read()
{
	int x = 0;
	bool f = true;
	char c = getchar();
	while (c < '0' || c > '9')
		f = (c != '-'), c = getchar();
	while (c >= '0' && c <= '9')
		x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return f ? x : -x;
}

void write(int x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar((x % 10) ^ 48);
}

const int INF = 0x3f3f3f3f3f3f3f3f;
int n, d;
int ans;
int pos[5005];
int dist[5005];
int cnt[5005];

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	c = read(), t = read();
	while (t--)
	{
		n = read(), d = read();
		for (int i = 1; i <= n; ++i)
			pos[i] = read();
		ans = 0;
		for (int i = 1; i < n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
				dist[j] = INF, cnt[j] = 0;
			dist[i] = 0;
			cnt[i] = 1;
			for (int j = i; j < n; ++j)
			{
				for (int k = j + 1; k <= n && pos[k] - pos[j] <= d; ++k)
				{
					int dis = dist[j] + 1;
					if (dis < dist[k])
					{
						dist[k] = dis;
						cnt[k] = cnt[j];
					}
					else if (dis == dist[k])
					{
						cnt[k] += cnt[j];
					}
				}
			}
			for (int j = i + 1; j <= n; ++j)
				if (cnt[j] == 2)
					++ans;
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}