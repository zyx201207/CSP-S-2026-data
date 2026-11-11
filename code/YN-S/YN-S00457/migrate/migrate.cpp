#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int id, T;
	cin >> id >> T;
	for (int o = 1; o <= T; o++) {
		bool A = 1;
		int n, d;
		cin >> n >> d;
		cin >> a[1] >> a[2];
		int ch = a[2] - a[1];
		for (int i = 3; i <= n; i++) {
			cin >> a[i];
			if (a[i] - a[i - 1] != ch)
				A = 0;
		}
		if (A) {
			d /= ch;
			d *= 2;
			if (n - d + 1 > 0 && d / 2 != 1)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
	}
	return 0;
}