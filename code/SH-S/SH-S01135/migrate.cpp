#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 7, inf = 3e18;
int c, t, n, ans, d, pre[N], suf[N], chkpre[N], chksuf[N];
int x[N], presm[N], sufsm[N];
void solve()
{
	scanf("%lld%lld", &n, &d);
	for (int i = 1; i <= n; i++)
		scanf("%lld", x + i);
	ans = 0;
	x[0] = inf;
	for (int i = 1; i < n; i++)
		x[i] = x[i + 1] - x[i];
	x[n] = inf;
	for (int l = 1, r = 1, sm = 0; r < n; r++)
	{
		sm += x[r];
		bool flg = 0;
		if (sm + x[r + 1] > d && sm <= d)
			flg = 1;
		while (sm > d)
			sm -= x[l++];
		if (r != 1)
			presm[r - 1] += min(l, r), pre[r - 1] += presm[r - 1];
		presm[r] -= l;
		if (l <= r && sm + x[r + 1] > d)
			pre[r] = pre[l - 1];
		chkpre[r] = flg * pre[l - 1];
	}
	for (int l = n - 1, r = n - 1, sm = 0; r; r--)
	{
		sm += x[r];
		bool flg = 0;
		if (sm + x[r - 1] > d && sm <= d)
			flg = 1;
		while (sm > d)
			sm -= x[l--];
		if (r != n - 1)
			sufsm[r + 1] -= max(l, r), suf[r + 1] += sufsm[r + 1];
		sufsm[r] += l;
		if (l >= r && sm + x[r - 1] > d)
			suf[r] = suf[l + 1];
		chksuf[r] = flg * suf[l + 1];
	}
	for (int i = 2; i <= n - 2; i++)
		ans += (chksuf[i] + sufsm[i] - (x[i] + x[i - 1] > d && x[i] <= d)) * (chkpre[i] + presm[i] - (x[i] + x[i + 1] > d && x[i] <= d));
	printf("%lld\n", ans);
	for (int i = 0; i <= n; i++)
		pre[i] = suf[i] = chkpre[i] = chksuf[i] = presm[i] = sufsm[i] = 0;
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while (t--)
		solve();
}
/*
0 1
10 3
0 3 6 7 8 9 10 13 16 19
 */
