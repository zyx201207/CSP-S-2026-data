#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1000010;
ll n, m, ans, a[N], dp[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	//cout << n << m << endl;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		//cout << a[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			if (j == 1) {
				dp[j] = max(a[i], dp[j]);
			} else {
				dp[j] = max(dp[j - 1] & a[i], dp[j]);
			}
			//cout << "dp[" << j << "]=" << dp[j] << endl;
		}
	}
	cout << dp[m];
	return 0;
}
