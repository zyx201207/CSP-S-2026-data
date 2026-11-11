#include <bits/stdc++.h>//Chinese can fly !
using namespace std;
#define int long long
string a, b, c, d;
int z, s, t, e;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (a == c) {
		z = 1;
		if (b[0] == d[0] && b[1] == d[1]) {
			s = 1;
			if ((b[2] <= 'C' && d[2] <= 'C') || (b[2] >= 'D' && d[2] >= 'D')) {
				t = 1;
				if ((b[2] + 1 == d[2]) || (d[2] + 1 == b[2]) || (b[2] == 'D' && d[2] == 'F') || (b[2] == 'F' && d[2] == 'D')) {
					e = 1;
				}
			}
		}
	}
	cout << z << s << t << e << "\n";
	return 0;
}