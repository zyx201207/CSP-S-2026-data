#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	int z = (b[0] - '0') * 10 + (b[1] - '0');
	int u = (d[0] - '0') * 10 + (d[1] - '0');
	if (a == c) {
		cout << '1';
		if (z == u) {
			cout << '1';
			if ((b[2] == 'A' && d[2] == 'B') || (d[2] == 'A' && b[2] == 'B') || (b[2] == 'A' && d[2] == 'C') || (d[2] == 'A'
			        && b[2] == 'C') || (b[2] == 'B' && d[2] == 'C') || (d[2] == 'B' && b[2] == 'C') || (b[2] == 'D' && d[2] == 'F')
			        || (d[2] == 'D' && b[2] == 'F')) {
				cout << '1';
				if ((b[2] == 'A' && d[2] == 'B') || (d[2] == 'A' && b[2] == 'B') || (b[2] == 'B' && d[2] == 'C') || (d[2] == 'B'
				        && b[2] == 'C') || (b[2] == 'D' && d[2] == 'F') || (d[2] == 'D' && b[2] == 'F')) {
					cout << '1';

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
//xym
	return 0;
}