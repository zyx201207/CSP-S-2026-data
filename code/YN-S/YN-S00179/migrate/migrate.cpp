#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n, m;
int a[2000010];
int b[2000010];
int c[2000010];
int sam;

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> T >> T;
	while (T--) {
		cin >> n >> m;
		for (int i  = 1; i <= n; i++)
			cin >> a[i];
		for (int l = 1; l < n; l++) {
			memset(b, 0x3f, sizeof(b));
			b[l] = 0;
			c[l] = 1;
			for (int i = l + 1; i <= n; i++) {
				for (int j = i - 1; j >= l; j--) {
					if (a[i] - a[j] <= m) {
						if (b[i] > b[j] + 1)
							c[i] = c[j], b[i] = b[j] + 1;
						else if (b[i] == b[j] + 1)
							c[i] += c[j];
					} else
						break;
				}
			}
//			for (int i = 1; i <= n; i++)
//				cout << b[i] << ' ' << c[i] << endl;
			for (int i = 1; i <= n; i++)
				if (c[i] == 2)
					sam++;
		}
		cout << sam << endl;
	}
	return 0;
}
