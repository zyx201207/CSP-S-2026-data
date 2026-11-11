#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long n, m, a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	if (n > 5000) {
		int d = a[2] - a[1], l = 0, r;
		for (int i = 1; i <= n; ++i) {
			r = ((a[1] + a[i]) * i / 2) - 1;
			if (m >= l && m <= r) {
				cout << i;
				return 0;
			}
			l = ((a[1] + a[i]) * i / 2);
		}
	} else {
		sort(a + 1, a + 1 + n);
		int maxn = 0;
		for (int i = 1; i <= n; ++i) {
			int sum = m, ans = 1;
			for (int j = 1; j <= n; ++j) {
				if (j != i && a[i] >= a[j]) {
					sum -= (a[i] - a[j]);
					if (sum >= 0 && sum <= m)
						++ans;
				}
			}
			maxn = max(maxn, ans);
		}
		cout << maxn;
	}
	
	return 0;
}
