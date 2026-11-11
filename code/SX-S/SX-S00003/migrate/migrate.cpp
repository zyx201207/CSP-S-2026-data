#include <bits/stdc++.h>
using namespace std;
int y[2000100];
int c, t;
int n, m;
int minn = INT_MAX, lj = 0;

void fly(int x, int sum, int zd) {
	if (x == zd) {
		if (minn == sum) {
			lj++;
		} else if (minn > sum ) {
			minn = sum;
			lj = 1;
		}
		return ;
	}
	for (int i = 1; i <= m; i++) {
		if (y[x + i] - y[x] > m)
			break;
		if (y[x + i] - y[x] <= m   && zd >= x + i   ) {
			fly(x + i, sum + 1, zd);
		} else
			break;
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	int sum = 0;
	for (int i = 1; i <= t; i++) {
		cin >> n >> m;
		sum = 0;
		for (int j = 1; j <= n; j++) {
			cin >> y[j];
		}
		for (int j = 1; j <= n; j++) {
			for (int z = n; z >= j + 3; z--) {
				fly(j, 1, z);

				if (lj == 2)
					sum++;


				minn = INT_MAX;
				lj = 0;
			}
		}
		cout << sum << endl;
	}
	return 0;
}