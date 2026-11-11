#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		long long x = 0;
		long long cnt = 1;
		for (int j = 1; j < i; j++) {
			x += (i - j);
			cnt++;
		}
		if (x <= m) {
			ans = cnt;
		}
	}
	cout << ans;
	return 0;
}