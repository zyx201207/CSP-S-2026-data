#include <bits/stdc++.h>
using namespace std;
string a, aa, b, bb;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> aa >> b >> bb;
	if (a == b) {
		cout << '1';
		if (aa[0] == bb[0] && aa[1] == bb[1]) {
			cout << '1';
			if (aa[2] < 'D' && bb[2] < 'D') {
				cout << '1';
				if (max(aa[2], bb[2]) - min(aa[2], bb[2]) < 2) {
					cout << '1';
				} else {
					cout << '0';
				}
			} else if (aa[2] >= 'D' && bb[2] >= 'D') {
				cout << '1';
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