#include <bits/stdc++.h>
using namespace std;
int n;
long long ztt = 0, m = 0;
string s = " ";

struct node {
	long long x;
	char y;
};
node a[200005];

main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a[i].x >> a[i].y;
		m += a[i].x;

		for (int k = 1; k <= a[i].x; k++) {

			s += a[i].y;
		}
	}

	for (int i = 1, j = m; i <= m / 2; i++, j--) {

		if (s[i] != s[j]) {
			ztt++;
		}
	}

	cout << ztt;

	return 0;
}