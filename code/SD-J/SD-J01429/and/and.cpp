#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
/*====================*/
const int N = 2e5 + 10;
int a[N];
/*====================*/
void Solve() {
	int n, m;
	cin >> n >> m;
	int maxn = -LLONG_MAX;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	if (m == 1 || n == 1) {
		cout << maxn << endl;
		return;
	} 
	if (m == n) {
		int ans = a[1];
		for (int i = 2; i <= n; i++) ans &= a[i];
		cout << ans << endl;
		return;
	}
	if (m == 2) {
		int ans = -LLONG_MAX;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans << endl;
		return;
	}
	if (m == n - 1) {
		int ans = -LLONG_MAX;
		for (int i = 1; i <= n; i++) {
			int res = 0, flag = false;
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (flag) res &= a[j];
				else res = a[j], flag = true;
			}
			ans = max(ans, res);//511

		}
		cout << ans << endl;
		return;
	}
	if (n <= 20) {
		vector<int> v;
		for (int i = 1; i <= m; i++) v.push_back(i);
		for (int i = 1; i <= n - m; i++) v.push_back(-i);
		int ans = -LLONG_MAX;
		do {
			int res = 0;
			bool flag = false;
			int i = 1;
			for (auto it : v) {
				if (it > 0) {
					if (flag) res &= a[i];
					else res = a[i], flag = true;
				}
				i++;
			}
			ans = max(ans, res);
		} while(next_permutation(v.begin(), v.end()));
		cout << ans << endl;
	}
}
/*====================*/
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	Solve();
	return 0;
}
