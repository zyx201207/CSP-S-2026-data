#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1e6;
int arr[M];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;

	for (int i = 1; i <= T; i++) {
		int n, m;
		cin >> n >> m;
		int cha = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		cha = arr[2] - arr[1];

		if (cha * 2 > m) {
			cout << 0 << "\n";
			continue;
		}
		cout << n - signed(m / cha) - m + 1 << "\n";
	}



	return 0;
}

/*
11 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
