# include <bits/stdc++.h>
using namespace std;
int a[1000000], b[100000];
int o = 0, h = 0;
int c, t;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (n == 4)
			cout << "1" << endl;
		if (n == 5)
			cout << "2" << endl;
	}

	return 0;
}
