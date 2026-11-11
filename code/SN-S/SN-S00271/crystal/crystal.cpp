//14:49 
#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace Sci {
	const int N = 1e6;
	int n, m, a[N];
	int c[N];
	void qud() {
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; i++)
			c[i] = a[i] - a[i-1];
		int l = 1, r = 1, x = 1;
		int sum = 0, maxn = 0;
		for(int i = 2; i <= n; i++) {
			sum += c[i] * x;
			x++;
			//cout << i << " " << l << " " << x << '\n';
			while(sum > m) {
				//cout << i << " ";
				l++; x--;
				sum -= a[i] - a[l];
			}
			maxn = max(maxn, i - l+1);
		}
		cout << maxn;
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	Sci::qud();
	return 0;
}
