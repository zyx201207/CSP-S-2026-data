#include <bits/stdc++.h>
using namespace std;
const int MJ = 1e6 + 10;
long long n, m, ss = 0;
long long a[MJ], b[MJ], c[MJ], d[MJ];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[a[i]]++;
		if (a[i] < a[i - 1] && i != 1) {
			ss = 1;
		}
		if (c[a[i]] == 0) {
			c[a[i]] = i;
		}
		if (b[a[i]] == 0) {
			b[a[i]] += i;
		} else if (b[a[i]] > 0) {
			for (int j = c[a[i]]; j < i; j++) {
				if (b[a[j]] > 0) {
					b[a[j]]--;
				}
			}
			b[a[i]] += i;
		}
	}
	if (ss = 0) {
		for (int i = 1; i <= m; i++) {
			cout << d[i] << ' ';
		}
	} else {
		for (int i = 1; i <= m; i++) {
			cout << b[i] << ' ';
		}
	}
	return 0;
}
