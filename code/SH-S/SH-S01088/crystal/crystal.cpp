#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
long long a[maxn];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) flag = false;
	}
	sort(a + 1, a + n + 1);
	if (flag) {
		int k;
		long long sum = 0, d = a[2] - a[1];
		for (k = 1; k < n; k++) {
		 	sum += d * k;
		 	if (sum > m) break;
		}
		cout << k;
		return 0;
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int j;
		long long sum = 0;
		for (j = i - 1; j >= 1; j--) {
			sum += a[i] - a[j];
			if (sum > m) break;
		}
		ans = max(ans, i - j);
	}
	cout << ans;
	return 0;
}
