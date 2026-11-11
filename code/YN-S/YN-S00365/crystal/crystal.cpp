#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n;
long long m;
long long a[N], sum[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in ", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = a[i] + sum[i - 1];
	}
	int ans = 0, l = 0;
	long long tot = 0;
	for (int r = 1; r <= n; r++) {
		tot = a[r] * (r - l);
		tot -= sum[r] - sum[l];
		while (tot > m) {
			tot -= a[r];
			l++;
			tot += a[l];
		}
		ans = max(ans, r - l);
	}
	cout << ans;
	return 0;
}
