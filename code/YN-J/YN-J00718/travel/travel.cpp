#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string x, a;
char y, yy, yyy, b, bb, bbb;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> x >> y >> yy >> yyy >> a >> b >> bb >> bbb;
	if (x == a) {
		cout << 1;
		if (y == b && yy == bb) {
			cout << 1;
			if (yyy >= 'A' && yyy <= 'C' && bbb >= 'A' && bbb <= 'C' || yyy == 'D' || yyy == 'F' && bbb == 'D' && bbb == 'F') {
				cout << 1;
				if (ll(yyy) - ll(bbb) == 1  || ll(bbb) - ll(yyy)  == 1  && yyy != 'C' && yyy != 'D' && bbb != 'C' && bbb != 'D') {
					cout << 1;
				} else {
					cout << '0';
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
}