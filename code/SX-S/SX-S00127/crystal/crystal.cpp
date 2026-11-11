#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		long long t = m, k = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (a[i] - a[j] <= t) {
				k++;
				t -= (a[i] - a[j]);
			} else {
				break;
			}
		}
		ans = max(ans, k);
	}
	cout << ans;
	return 0;
}