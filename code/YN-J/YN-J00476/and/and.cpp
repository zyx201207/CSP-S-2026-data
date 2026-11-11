#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
map<int, int>mp;
int n, m;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int maxn = 0, ans;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1) {
			ans = a[i];
		} else
			ans &= a[i];
		mp[a[i]]++;
		if (mp[a[i]] >= m) {
			maxn = max(maxn, a[i]);
		}
	}
	if (m == n) {
		cout << ans;
	} else {
		ans = a[n];
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= m; i++) {
			ans &= a[n - i + 1];
		}
		cout << max(ans, maxn);
	}
}