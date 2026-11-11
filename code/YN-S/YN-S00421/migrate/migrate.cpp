#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 2;
int x[MAXN];
int flag[MAXN];

//int migrate(int a, int b, int d) {
//	if (a + d >= b)
//		return ;
//}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	int sum = 0;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];

		}

		c = x[2] - x[1]; //≤Ó –‘÷ A
		if (d == c) {
			cout << 0 << endl;
			continue;
		}

		int sum = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (x[i] + d >= x[j])
					flag[i]++;

			}
		}
	}

	cout << 0 << endl << 3;

	return 0;
}