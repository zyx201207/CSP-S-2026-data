#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 500010;

int n, m, a[maxn], ans, sum[maxn];

void get(int now)
{
	int thi = 0;
	for (int i = 1 << 20; i > 0; i >>= 1)
	{
		int l = now - i - thi;
		if (l < 1)  continue;
		int check = a[now] * (now - l + 1) - sum[now] + sum[l - 1];
		if(check <= m)  thi += i;
	}
	ans = max(ans, thi + 1);
	return;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)  cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)  sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++)  get(i);
	cout << ans;
	return 0;
}
