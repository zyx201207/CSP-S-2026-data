#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5;
long long a[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int j = 1; j <= d; j++) {
		int mu = a[j];

		for (int i = 1; i <= n; i++) {
			int y = a[i];
			if (mu == y) {
				cout << mu << " " << y;
				break;
			}
		}
	}

}