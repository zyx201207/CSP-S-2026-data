#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, ans, mx = -1;
long long a[N], sum,  m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = n; i >= 1; i--) {
		if (a[i] == a[i + 1]) {
			continue;
		}
		ans = 1;
		sum = m;
		for (int j = i - 1; j >= 1; j--) {
			sum -= a[i] - a[j];
			if (sum >= 0) {
				ans++;
			}
			if (sum <= 0) {
				break;
			}
		}
		mx = max(ans, mx);
	}
	cout << mx;
	return 0;
}