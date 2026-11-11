#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int N = 5e5 + 10;

int n;
i64 m, a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	i64 sum = 0;
	for (int i = 1, j = 1; i <= n; ++i) {
		sum += a[i];
		while ((i - j + 1) * a[i] - sum > m) {
			sum -= a[j++];
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans << endl;
	return 0;
}