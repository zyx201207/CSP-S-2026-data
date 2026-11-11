#include <bits/stdc++.h>
using namespace std;
int a[32423];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	long long  q;
	string w;
	long long  e;
	string r;
	cin >> q >> w >> e >> r;
	for (int i = 1; i <= 4; i++) {
		if (q == e) {
			long long  s = w[1], d = r[1];
			if (s == d) {
				for (int j = 1; j <= 3; j++) {
					int z = w[2], x = r[2];
					if (z + 1 == x && z  == 67 && z  == 68 || z - 1 == x && z  != 67 && z  != 68) {
						cout << 1111;
						return 0;
					} else if (z  == 67 && z  == 68 ) {
						cout << 1110;
						return 0;
					} else {
						cout << 1100;
						return 0;
					}
				}
			} else {
				cout << 1000;
				return 0;
			}
		} else {
			cout << 0000;
		}
	}
	return 0;
}