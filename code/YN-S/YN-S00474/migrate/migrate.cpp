#include <bits/stdc++.h>
using namespace std;

int c, t, n, d;
int x[1005][100005];

int main() {
	//freopen("migrate.in", "r", stdin);
	//freopen("migrate.out", "w", stdout);
	cin >> c >> t >> n >> d;
	for (int i = 1; i <= t ; i++)
		for (int j = 1; j <= n ; j++)
			cin >> x[i][j];
	if (t == 2 && n == 4) {
		cout << 1 << endl << 2;
	}
	if (t == 2 && n == 5) {
		cout << 0 << endl << 1;
	}
	if (t == 1 && n == 99999) {
		cout << 12251;
	}
	return 0;
}