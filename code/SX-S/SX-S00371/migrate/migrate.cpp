#include <bits/stdc++.h>
using namespace std;

long long c, t, jl[1000010], n, d;

long long qread() {
	string sr;
	long long x = 1;
	long long num = 0;
	cin >> sr;
	for (int i = 0; i < sr.size(); i++) {
		if (sr[i] == '-' && i == 0) {
			x = -1;
			continue;
		}
		num *= 10;
		num = num + (sr[i] - '0');
	}
	return num * x;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if (c == 11 || c == 12) {
		for (long long T = 1; T <= t; T++) {
			cin >> n >> d;
			for (long long i = 1; i <= n; i++) {
				jl[i] = qread();
			}
			long long cha = max(jl[2] - jl[1], jl[1] - jl[2]);
			long long flym = d / cha;

			if (d <= cha) {
				cout << 0 << endl;
				continue;
			}
			flym = flym * 2 ;
			if (n < flym) {
				cout << 0 << endl;
				continue;
			} else
				cout << n - flym + 1 << endl;
		}
	}
	if (c == 13 || c == 14) {
		for (long long T = 1; T <= t; T++) {
			cin >> n >> d;
			for (long long i = 1; i <= n; i++) {
				jl[i] = qread();
			}
			if (n > 3 || n <= 2) {
				if (jl[n] - jl[2] <= d && jl[n] - jl[1] > d && jl[3] - jl[1] <= d && jl[4] - jl[1] > d) {
					cout << 1 << endl;
					continue;
				}
				if (jl[n - 1] - jl[1] <= d && jl[n] - jl[1] > d && jl[n] - jl[n - 2] <= d && jl[n] - jl[n - 3] > d) {
					cout << 1 << endl;
					continue;
				}
				cout << 0 << endl;
				continue;
			}
			if (n == 3 && jl[3] - jl[1] <= d) {
				cout << 1 << endl;
				continue;
			}
			cout << 0 << endl;
		}
	}
	return 0;
}
