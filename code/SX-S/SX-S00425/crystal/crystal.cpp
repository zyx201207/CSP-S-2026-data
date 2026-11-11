#include <bits/stdc++.h>
using namespace std;
long long a[500010], s[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, sum = 0, t = 1, maxx = -1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n - 1; i++) {
		sum += (i - t + 1) * (a[i + 1] - a[i]);
		if (sum > m) {
			if (sum - (a[i + 1] - a[t - 1] + a[i] - a[t - 1]) <= m) {
				sum -= (a[i + 1] - a[t - 1] + a[i] - a[t - 1]);
				t++;
				continue;
			}

			cout << i - t + 1;
			return 0;
		}
	}
	cout << n - t + 1;
	return 0;
}
