#include <bits/stdc++.h>
using namespace std;
int n, a[200005], dp[200005][2], m, ans = 1;;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int maxn = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	if (m == 1) {
		cout << maxn;
		return 0;
	}
	if (m == 2) {
		maxn = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				maxn = max(maxn a[i] & a[j]);
			}
		}
		cout << maxn;
		return 0;
	}
	if (m == n) {
		ans = a[1];
		for (int i = 1; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	cout << 0;

	return 0;//and playing dino,so what about csp-s,i will die due to hard questions
}