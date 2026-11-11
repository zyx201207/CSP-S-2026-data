#include <bits/stdc++.h>
using namespace std;

#define int long long

int a[500000];
unsigned int s[500000];

signed main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k = 0;
  unsigned int m;
  cin >> n >> m;
	for (int i = 0; i != n; ++ i) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i != n - 1; ++ i) {
		s[i] = a[i + 1] - a[i];
	}
	int ans = -1;
	for (int i = 0; i != n; ++ i) {
		int tm = m;
		int j;
		for (j = i; j != n && tm >= 0; ++ j) {
			tm -= s[j] * (j + 1);
		}
		ans = max(ans, j - i);
	}
	cout << ans;
  return 0;
}
