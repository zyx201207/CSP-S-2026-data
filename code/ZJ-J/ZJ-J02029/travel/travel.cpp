#include <bits/stdc++.h>
#define int long long
using namespace std;
string a, b, c, d;
int q, w, e, r;
bool check(char z, char x) {
	if (z == x + 1 || z == x - 1) return true;
	if (z == 'D' && x == 'F' || z == 'F' && x == 'D') return true;
	return false;
}
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> a >> b >> c >> d;
	if (a == c) {
		q = 1;
		if (b[0] == d[0] && b[1] == d[1]) {
			w = 1;
			if ((b[2] <= 'C') == (d[2] <= 'C')) {
				e = 1;
				if (check(b[2], d[2])) {
					r = 1;
				}
			}
		}
	}
	cout << q << w << e << r;
	return 0;
}