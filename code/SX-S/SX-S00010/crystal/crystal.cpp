#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5+5;
long long n, m, a[N], sum[N], res;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (long long i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (long long i = 1; i <= n; i++) {
		long long l = 1, r = i, ans = i;
		while (l <= r) {
			long long mid = (l + r) / 2;
			long long x = a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]);
			if (x <= m) {
				ans = mid;
				r = mid - 1;
			} else
				l = mid + 1;
		}
		res = max(res, i - ans + 1);
	}
	cout << res;
	return 0;
}
