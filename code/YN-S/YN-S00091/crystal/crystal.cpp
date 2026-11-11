#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n, m;
long long a[maxn], b[maxn], dp[maxn], ans;
set<long long>b2;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, greater<long long>());
	for (long long i = 0; i < n - 1; i++) {
		b[i + 1] = a[i + 1] - a[i];
		b2.insert(b[i + 1]);
	}
	if (b2.size() == 1) {
		if ((*b2.begin()) == 0) {
			cout << n << "\n";
		}
		cout << m / - (*b2.begin()) << "\n";
		return 0;
	}
	ans = 0;
	for (long long i = 0; i < n - ans + 1; i++) {
		dp[1] = 0;
		long long j;
		for (j = 2; j <= n - i + 1; j++) {
			dp[j] = dp[j - 1] + a[i] - a[i + j - 1];
			if (dp[j] > m) {
				dp[j] = 0;
				j--;
				break;
			}
		}
		ans = max(j, ans);
	}
	cout << ans << "\n";
	return 0;
}