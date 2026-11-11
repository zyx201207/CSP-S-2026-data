#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n = 0, m = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a, a + n + 1);
	long long sum = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int t = 1;
		sum = 0;
		for (int j = i - 1; j >= 1; j--) {
			sum += a[i] - a[j];
			if (sum <= m) {
				t++;
			}
			if (sum >= m) {
				break;
			}
		}
		ans = max(ans, t);
	}
	cout << ans;
	return 0;
}