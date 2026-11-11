#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7;
int n, m, a[N], ans;
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(), cout.tie();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int l = 1, r = 1, sm = 0; r <= n; r++)
	{
		sm += (a[r] - a[r - 1]) * (r - l);
		while (sm > m)
			sm -= a[r] - a[l++];
		ans = max(ans, r - l + 1);
	}
	cout << ans;
}
