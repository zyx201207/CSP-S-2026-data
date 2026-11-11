#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2000010;

int c, T, n, d, a[maxn], l[maxn], r[maxn], ans, tot, wei[maxn];

void get(int now)
{
	int ret = now;
	for (int i = 1 << 20; i > 0; i >>= 1)
	{
		if (ret + i > n)  continue;
		int nxt = ret + i;
		if (a[nxt] - a[now] <= d)  ret += i;
	}
	r[now] = ret;
	ret = now;
	for (int j = 1 << 20; j > 0; j >>= 1)
	{
		if (ret - j < 1)  continue;
		int nxt = ret - j;
		if (a[now] - a[nxt] <= d)  ret -= j;
	}
	l[now] = ret;
	return;
}

int check(int i, int j)
{
	tot = 0;
	int now = i;
	int ret = 0;
	while (1)
	{
		if (r[now] == now)  break;
		now = r[now];
		if (now >= j)  break;
		wei[++tot] = now;
	}
	if (now < j)  return 0;
	now = j;
	for (int k = tot; k >= 1; k--)
	{
		now = l[now];
		ret += abs(now - wei[k]);
	}
	if (ret == 1)  return 1;
	return 0;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--)
	{
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)  cin >> a[i];
		for (int i = 1; i <= n; i++)  get(i);
		for (int i = 1; i <= n; i++)  for (int j = i + 1; j <= n; j++)  ans += check(i, j);
		cout << ans << "\n";
	}
	return 0;
}
