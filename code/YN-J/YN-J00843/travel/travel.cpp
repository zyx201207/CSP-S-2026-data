#include <bits/stdc++.h>
using namespace std;

int n, m, st[300005], ans[300005], cs, a[300005];

int main() {
	//freopen("card.in", "r", stdin);
	//freopen("card.out", "w", stdout);
	cin >> n >> m;


	for (int i = 0; i <= n - 1; i++) {

		int num;
		cin >> num;
		st[num]++;
		a[num] = i;
		cs++;

		if (st[num] > 1) {
			for (int j = 1; j <= i; j++) {

				ans[j] = cs - a[j];
				st[j] = 0;
			}
		}
	}

	for (int i = 1; i <= m; i++) {

		cout << ans[i] << " ";
	}

	return 0;
}