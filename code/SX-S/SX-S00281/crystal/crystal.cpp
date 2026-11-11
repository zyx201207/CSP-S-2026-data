#include <bits/stdc++.h>
using namespace std;
const int M = 5e5+10;
long long n, m;
long long a[M], sum[M];
long long ans = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = a[i] + sum[i - 1];
	}
	for (long long i = 1; i <= n; i++) {
		for (long long j = i + ans; j <= n; j++) {
			if ((j - i + 1) * a[j] - sum[j] + sum[i - 1] > m) {
				ans = max(ans, j - i);
				break;
			}
		}

	}
	cout << ans;
	return 0;
}
