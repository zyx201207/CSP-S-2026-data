#include <bits/stdc++.h>
using namespace std;
long long n, m, a[10000005], k[10000005], ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (long long i = 1; i <= n; i++)
		for (long long j = i + 1; j <= n; j++) {
			long long sum = 0;
			for (int it = 0; it < (i + j - 1) / 2; it++)
				sum += abs(a[j - it] - a[i + it]);
			if (sum > m)
				break;
			ans = max(ans, j - i);
		}
	cout << ans + 1;
	return 0;
}