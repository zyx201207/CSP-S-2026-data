/* construct : OCT 31'26 */
#include	<iostream>
#define		int		long long
using namespace std;
constexpr int maxn = 2e6+4;

int x[maxn];
int nxt[maxn];
int pre[maxn];
int c, t, n, d;

int dfs (int s, int t, int d)
{
	if (!d)
		return s == t;
	int ans = 0;
	for (int i = s + 1; i <= nxt[s] && i <= t; i++)
		ans += dfs (i, t, d - 1);
	return ans;
}

signed main (void)
{
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	scanf ("%lld%lld", &c, &t);
	while (t--)
	{
		scanf ("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf ("%lld", x + i);
		nxt[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			nxt[i] = nxt[i - 1];
			while (nxt[i] < n && x[nxt[i] + 1] - x[i] <= d)
				nxt[i]++;
		}
		pre[n + 1] = n;
		for (int i = n; i; i--)
		{
			pre[i] = pre[i + 1];
			while (pre[i] > 1 && x[i] - x[pre[i] - 1] <= d)
				pre[i]--;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n && x[j] - x[j - 1] <= d; j++)
			{
				int dist = 0;
				for (int k = i; k < j; k = nxt[k])
					dist++;
				if (dfs (i, j, d) == 2)
					ans++;
			}
		}
		printf ("%lld\n", ans);
	}
	return 0;
}
