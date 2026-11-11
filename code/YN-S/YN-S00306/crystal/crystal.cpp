#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, k, a[N], sum[N], ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (long long i = 1; i <= n; i++) {
		long long l = 1, r = i;
		while (l <= r) {
			long long mid = (l + r) / 2;
			if (a[i]*mid - (sum[i] - sum[i - mid]) <= k)
				ans = max(ans, mid), l = mid + 1;
			else
				r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}