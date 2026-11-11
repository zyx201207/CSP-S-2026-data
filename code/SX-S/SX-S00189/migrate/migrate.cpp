#include <bits/stdc++.h>
using namespace std;

int a[2000010];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int c, T;
	cin >> c >> T;
	while (T --) {
		int ans = 0;
		int n, l;
		cin >> n >> l;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
		}

		for (int i = 1; i <= n; i ++) {
			for (int j = i; j <= n; j ++) {
				int len = j - i;
				int zheng = (len / l), sheng = (len % l);
				if (len != 0 && (zheng == sheng) ) {
					//cout << "jiben : " << len << ' ' << l << '\n';
					//cout << "jieguo : " << (len / l) << ' ' << (len / l) << '\n';
					//cout << "ans : " << i << ' ' << j << '\n';
					ans ++;
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}
