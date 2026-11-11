#include <bits/stdc++.h>
using  namespace std;

int  main() {
	freopen("card.in", "r", stdin)
	freopen("card.out", "w", stdout)



	int a[10005], n, m, cs = 0, b[10005]
	                         cin << n << m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (a[i] == i) {
			for (int j == 1; j <= n; j++) {
				if (a[j] != a[i])
					continue;
				if (a[j] == a[i])
					break;
				int k = a[i]
				        a[j - 1] = a[j];
				a[n] = k;
				cs++;
			}
		}
		if (cs == n) {
			for (int j = 1; j <= m; j++) {
				if (a[i] == a[j])
					break
					int k = a[1];
				a[j - 1] = a[j];
				a[n] = k;
			}
		}
		cs++;
	}
}

return 0;
}
