#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int n, m, a[N];
vector <int> ok;
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ok.push_back(i);
	}
	for (int k = 30; k >= 0; k--) {
		vector <int> tmp = ok;
		ok.clear();
		for (int i: tmp)
			if (a[i] >> k & 1)
				ok.push_back(i);
		if (ok.size() < m)
			ok = tmp;
	}
	int ans = (1 << 31) - 1;
	for (int i: ok) ans &= a[i];
	cout << ans << '\n';
	return 0;
}
