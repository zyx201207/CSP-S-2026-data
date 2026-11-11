#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	cin >> n;
	long long m, a[n + 10] = {}, s[n + 10] = {}, ma;
	cin >> m;
	ma = -1;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort (a + 1, a + 1 + n);
	for (int i = 1; i <= n; i ++) {
		s[i] = s[i - 1] + abs(a[i] - a[i - 1]);
	}

	for (int i = 1; i <= n ; i ++) {
		int j = i + 1;
		long long yu = m;
		while ( yu >= 0) {
			long long shu = s[j] - s[j - 1] ;
			if (yu >= shu * (j - i) && j < n) {
				if (s[j] == s[j - 1]) {
					j ++;
				} else {
					yu -= shu * (j - i);
					j ++;
				}
			} else {
				break;
			}
		}
		if (ma < j - i)
			ma = j - i;
	}
	cout << ma;

	return 0;
}