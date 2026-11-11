#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5;
int n, m, sum, a[N], ans = -1;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		sum = 0;
		for (int j = i; j >= 1; j--) {
			sum += (a[i] - a[j]);
			if (sum == m) {
				ans = max(ans, i-j+1);
				break;
			}
			if (sum > m) {
				ans = max(ans, i-j);
				break;
			}
			ans = max(ans, i-j+1);
		}
	}
	cout << ans;
	return 0;
}
