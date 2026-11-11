#include <bits/stdc++.h>
using namespace std;
#define int long long
#define freopen(io) freopen(io".in", "r", stdin), freopen(io".out", "w", stdout)

const int MAXN = 500007;
int n, m, a[MAXN], sum[MAXN], ans;

signed main()
{
	freopen("crystal");
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = a[i] + sum[i - 1];
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = i;
		int j = 0;
		while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if ((i - mid + 1) * a[i] - sum[i] + sum[mid - 1] <= m)
				j = mid, r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans << '\n';
}