#include <bits/stdc++.h>
using namespace std;
long long a[500001];
int dp[500001];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, s = 0, ans = 0;
	cin >> n >> m;
	int k, h = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 2)
			k = a[i] - a[i - 1];
		if (i > 2 && a[i] - a[i - 1] != k) {
			h = 1;
		}
	}
	if (h == 0) {
		int z = 0;
		for (int i = 1; i <= n; i++) {
			ans++;
			z += i * k;
			if (z > m)
				break;

			//	cout << z << " ";
		}
		cout << ans;
	} else {
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			s = m;
			long long h = 0;
			for (int j = i; j >= 1; j--) {
				if (s < a[i] - a[j])
					break;
				s = s - (a[i] - a[j]);
				h++;
			}
			ans = max(ans, h);
		}
		cout << ans;
	}

	return 0;
}
