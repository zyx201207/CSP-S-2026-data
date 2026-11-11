#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string rs, rz, xs, xz;
	cin >> rs >> rz >> xs >> xz;
	if (rs == xs) {
		char rss = rz[1];
		char xss = xz[1];
		cout << 1;
		if (rss == xss) {
			cout << 1;
			rss = rz[2];
			xss = xz[2];
			if (rss == 'D' && xss == 'F' || rss == 'F' && xss == 'D') {
				cout << "11" << endl;
				return 0;
			} else if (rss == 'A' || rss == 'B' || rss == 'C' && xss == 'A' || xss == 'B' || xss == 'C') {
				cout << 1;
				if (rss - 1 == xss || rss + 1 == xss) {
					cout << 1 << endl;
					return 0;
				}
				cout << 0 << endl;
				return 0;
			} else {
				cout << "00" << endl;
				return 0;
			}
		}
		cout << "000" << endl;
		return 0;
	}
	cout << "0000" << endl;
	return 0;
}