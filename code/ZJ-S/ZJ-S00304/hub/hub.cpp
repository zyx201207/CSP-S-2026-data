#include <bits/stdc++.h>
using namespace std;
int T, n, m;
int main () {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	scanf ("%*d%d", &T);
	while (T --> 0) {
		scanf ("%d%d", &n, &m);
		for (int i = 1; i < n; i++) {
			scanf ("%*d%*d");
		}
		n = (n - 1) / 2;
		if (m > n && m < 2 * n + 1) {
			puts ("1");
		} else if (m == 2 * n + 1) {
			puts ("0");
		} else {
			printf ("%d\n", (n - m + 3) / 4 + 1);
		}
	}
	return 0;
}