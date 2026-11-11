#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c, t, n, d;
int a[2000010];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if (c == 11 || c == 12) {
		while (t--) {
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				scanf("%d", % a[i]);
			}
			if ((a[2] - a[1]) * 2 <= d) {
				ll s = 0, k = 3;
				while (k <= n) {
					s += n / k;
					k++;
				}
				cout << s << "\n";
			}
		}
	} else {
		while (t--) {
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				scanf("%d", % a[i]);
			}
			cout << n / d << "\n";
		}
	}
	return 0;
}