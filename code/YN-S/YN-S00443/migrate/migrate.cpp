#include <bits/stdc++.h>
using namespace std;
long long x[1000000];
int d;
int sum[1000000];
int f[100000];

bool check(int a, int b) {
	if (b - a <= d)
		return true;
	else
		return false;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		d = 0;
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> x[j];
		}
		f[1] = 1;
		for (int j = 1; j <= n; j++) {
			for (int z = j + 1; z < n; z++) {
				if (check(x[j], x[z]))
					f[z] = f[z] + f[j];
			}
		}
		for (int j = n; j >= 1; j--) {
			for (int z = j - 1; z > 1; z--) {
				if (f[j] - f[z] == 2)
					sum[i]++;
			}
		}

	}
	for (int i = 1; i <= t; i++) {
		cout << sum[i] << endl;
	}
	return 0;
}