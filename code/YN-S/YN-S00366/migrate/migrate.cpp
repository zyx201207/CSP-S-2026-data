#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N1 = 5050;
const int INF = 1e18;
const int N2 = 2e6 + 10;
int C, T;
int n, d;
int x[N2];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> C >> T;

	while (T--) {
		cin >> n >> d;
		int flag1 = 1; //µÈ²îÊıÁĞ

		for (int i = 1; i <= n; i++) {

			cin >> x[i];

			if (i >= 3 && x[i] - x[i - 1] != x[i - 1] - x[i - 2])
				flag1 = 0;
		}

		sort(x + 1, x + 1 + n);
		int cnt = 0;

		for (int i = 1; i <= n; i++) {

			int id = i, lst_id = 0, lst_loc = 0, loc = x[i];
//			cout << "loc:" << loc << "\n";

			while (id < n) {
				lst_id = id, lst_loc = loc;
				id = upper_bound(x + 1, x + 1 + n, loc + d) - x ;
//				cout << "id:" << id << "\n";

				if (id > n) {
					for (int j = n; j >= lst_id + 1; j--) {

						int lft_id = lower_bound(x + 1, x + 1 + n, x[j] - d) - x;

						if (lst_id - 1 == lft_id && lft_id > i) {
							cnt++;
//							cout << "lst:" << lst_id << " now:" << j << "\n";
						} else if (lst_id - 1 > lft_id)
							break;
					}

					break;
				}

				id--;

				if (x[id] <= x[lst_id])
					break;
//				cout << "l:" << lst_id << " r:" << id << "\n";
				loc = x[id];

				int lft_id = lower_bound(x + 1, x + 1 + n, loc - d) - x;

				if (lst_id - 1 == lft_id && lft_id > i) {
//					cout << "lst:" << lst_id << " now:" << id << "\n";
					cnt++;
					break;
				}

				for (int j = id - 1; j >= lst_id + 1; j--) {

					int lft_id = lower_bound(x + 1, x + 1 + n, x[j] - d) - x;

					if (lst_id - 1 == lft_id && lft_id > i) {
//						cout << "lst:" << lst_id << " now:" << j << "\n";
						cnt++;
					} else if (lst_id - 1 > lft_id)
						break;
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}