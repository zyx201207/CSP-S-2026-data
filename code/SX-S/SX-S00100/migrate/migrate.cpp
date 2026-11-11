#include <bits/stdc++.h>
using namespace std;
long long a[1000000], c[1000000];
long long sum = 0, jl = 0;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long cs, t, n, d;
	cin >> cs >> t;
	for (int j = 0; j < t; j++) {
		cin >> n >> d;
		cin >> a[0];
		for (int i = 1; i < n; i++) {
			cin >> a[i];
			c[i] = a[i] - a[i - 1];
		}
		sum = 0;
		jl = 0;
		for (int i = 1; i < n; i++) {
			if (c[i] > d) {
				jl = 0;
			} else {
				if (c[i] + c[i + 1] <= d && c[i + 1] + c[i + 2] <= d && c[i] + c[i + 1] + c[i + 2] > d) {
					sum++;
					jl++;
				} else if ((c[i + 1] + c[i + 2] > d && c[i + 2] <= d && jl != 0) || (c[i - jl] + c[i - jl - 1] > d && jl != 0)) {
					sum++;
					jl++;
				} else {
					jl = 0;
				}
			}
			if (i + 3 > n - 1 && jl == 0) {
				break;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
