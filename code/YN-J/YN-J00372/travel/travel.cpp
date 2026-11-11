#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("traval.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, c, b, d;
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << "1";
		if (b[0] == d[0] && b[1] == d[1]) {
			cout << "1";
			if (b[3] == 'A' && d[3] == 'C' || b[3] == 'C' && d[3] == 'A') {
				cout << "10";
			} else if (b[2] == 'A' && d[2] == 'B' || b[2] == 'B' && d[2] == 'A' || b[2] == 'B' && d[2] == 'C' || b[2] == 'C'
			           && d[2] == 'B' || b[2] == 'D' && d[2] == 'F' || b[2] == 'F' && d[2] == 'D') {
				cout << "11";
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}