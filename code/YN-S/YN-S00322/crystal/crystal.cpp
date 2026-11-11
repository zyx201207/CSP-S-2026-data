#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, m, a[N], maxx, b[N], f[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		long long cnt = 0, ans = 0;
		for (int j = 1; j <= i; j++) {
			if (a[j] > m)
				break;
			cnt += a[i] - a[j];
			ans++;
			if (cnt <= m) {
				maxx = max(maxx, ans);
			} else {
				break;
			}
		}
	}
	cout << maxx;
	return 0;
}