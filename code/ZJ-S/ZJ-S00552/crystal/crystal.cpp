#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N], ans = 1, sum[N];
signed main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.in", "r", stdin);
	ios :: sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (int l = 1, r = 2; r <= n; r++) {
		while (l <= r && (r - l) * a[r] - (sum[r - 1] - sum[l - 1]) > k) l++;
		ans = max (r - l + 1, ans);
	}
	return cout << ans, 0;
}
//追忆
//我常常追忆过去。
//生命瞬间定格在脑海，我将背后的时间裁剪、折叠、蜷曲，揉捻成天上朵朵白云
//时间原因，打不了了，T2 硬控 2h，luogu UID: 995899