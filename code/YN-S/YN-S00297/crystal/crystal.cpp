#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N];
long long n, m, ans = 1, sum[N], cha[N], mi = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mi = min(a[i], mi);
	}
	for (int i = 1; i <= n; i++) {
		a[i] -= mi ;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
//	for (int i = 2; i <= n; i++) {
//		cha[i] = a[i] * (i - 1) - sum[i - 1];
//	}
	for (int i = 1, j = 1; i <= n, j < n;) {
		long long cnt = j - i + 1;
		long long su = a[j + 1] * cnt - (sum[j] - sum[i - 1]);
		if (su <= m) {
			ans = max(ans, cnt + 1);
			j++;
		} else {
			i++;
		}
	}
	cout << ans;
	return 0;
}