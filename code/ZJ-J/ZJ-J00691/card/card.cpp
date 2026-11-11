#include <bits/stdc++.h>
using namespace std;
int a[500005], cnt[500005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if (m <= 2) {
		int cnt = 0;

		for (int i = 1; i <= n; i ++) {
			if (a[i] != a[n]) {
				cnt ++;
			}
		}
		if (m == 1) {
			cout << n;
		} else {
			cout << cnt << ' ' << n;
		}
		return 0;
	} else {
		for (int i = 1; i <= n; i ++) {
			set <int> s;
			for (int j = i; j <= n; j ++) {
				s.insert(a[j]);
			}
			int st = m - s.size() + 1;
			for (int j = st; j <= m; j ++) {
				cnt[j] ++;
			}
		}
		for (int i = 1; i <= m; i ++) {
			cout << cnt[i] << ' ';
		}
	}
	return 0;
}
