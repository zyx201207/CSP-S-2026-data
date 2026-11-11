#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N];
int n;
long long m;
long long sum[N];

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
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1, r = 1;
	int ans = 0;
	while (r <= n) {
		while (a[r] * (r - l + 1) - (sum[r] - sum[l - 1]) > m) {
			l++;
		}
		int k = a[r] * (r - l + 1) - (sum[r] - sum[l - 1]);
		ans = max(ans, r - l + 1);
		r++;
	}
	cout << ans;

	return 0;
}
