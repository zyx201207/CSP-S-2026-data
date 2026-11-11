#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m, ans;
int a[N], sum[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)

		cin >> a[i];
	sort(a + 1, a + 1 + n);

	for (int i = 1; i <= n; i++)

		sum[i] = sum[i - 1] + a[i];

//	for (int i = 1; i <= n; i++) {
//
//		int tmp = a[i] * (i - 1);
////		cout << " tmp:" << tmp << " ans:" << ans << "\n";
//
//		if (m - tmp >= 0)
//			ans = max(ans, i);
//	}

	int l = 1;

	for (int i = 1; i <= n; i++) {

		int tmp = a[i] * (i - l);
//		cout << "i:" << i << " l:" << l << " r:" << i << " tmp:" << tmp << "\n";

		if (tmp - sum[i - 1] + sum[l - 1] <= m)
			ans = max(ans, i - l + 1);
		else {
			while (tmp - sum[i - 1] + sum[l - 1] > m) {
				tmp -= a[i];
				l++;
			}

			ans = max(ans, i - l + 1);
		}
	}

	cout << ans << "\n";
	return 0;
}