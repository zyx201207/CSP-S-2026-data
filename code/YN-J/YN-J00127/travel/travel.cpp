#include <bits/stdc++.h>
using namespace std;
string x, xx, y, yy;
int a = 0, b = 0, c = 0, d = 0;
int n, m;
char p, q;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> x >> xx >> y >> yy;
	if (x == y) {
		n = (xx[0] - '0') * 10 + (xx[1] - '0');
		m = (yy[0] - '0') * 10 + (yy[1] - '0');
		p = xx[2];
		q = yy[2];
		if (n == m) {
			if (('A' <= p && p <= 'C' && 'A' <= q && q <= 'C') || ('D' <= p && p <= 'F' && 'D' <= q && q <= 'F')) {
				if (p - '0' + 1 == q - '0' || q - '0' + 1 == p - '0') {
					cout << "1111";
				} else {
					cout << "1110";
				}
			} else {
				cout << "1100";
			}
		} else {
			cout << "1000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}
