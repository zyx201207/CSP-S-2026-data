#include <bits/stdc++.h>
using namespace std;

int n, m, st[300005], ans[300005], cs;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;


	for (int i = 1; i <= n; i++) {

		int num;
		cin >> num;
		st[num]++;


		if (st[num] > 1) {
			ans[num] = i;
			cs++;

			for (int j = 1; j <= i; j++) {

				if (st[j] > 0 && st[j] != st[num]) {
					ans[j] = cs;
				}

				st[j] = 0;
			}
		}
	}

	for (int i = 1; i <= m; i++) {

		cout << ans[i] << " ";
	}

	return 0;
}
