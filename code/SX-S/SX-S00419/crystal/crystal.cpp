#include <bits/stdc++.h>
using namespace std;

long long n, a[500005], ans, m, s[500005];

bool check(long long i, long long x) {
	return m >= 1ll * a[i] * x - s[i] + s[i - x];
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	if (n <= 5000 || m <= 100000000)
		return 0;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (long long i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	for (long long i = 1; i <= n; i++) {
		long long l = 1, r = i;
		while (l < r) {
			long long mid = l + r + 1 >> 1;
			if (check(i, mid))
				l = mid;
			else
				r = mid - 1;
		}
		ans = max(ans, l);
	}
	cout << ans;
	return 0;
}
// Âå¹È¹Ø×¢ Sparse_Table uid = 1046508 Ð»Ð»ß÷
