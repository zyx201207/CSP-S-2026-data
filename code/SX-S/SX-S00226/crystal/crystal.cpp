#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	int len = 1, hei = a[1], sum = 0;
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] > hei)
			sum += (a[i] - hei) * len;
		hei = a[i], len++;
		while (sum > m) {
			sum -= (hei - a[i - len + 1]);
			len--;
		}
		ans = max(ans, len);
	}
	cout << ans;
	return 0;
}
