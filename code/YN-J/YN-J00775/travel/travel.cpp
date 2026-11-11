#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, aa, b, bb;
	cin >> a >> aa >> b >> bb;
	if (a == b) {
		cout << "1";
		string s1, s2;
		for (int i = 0; i < 2; i++) {
			s1 += aa[i];
			s2 += bb[i];
		}
		if (s1 == s2) {
			cout << "1";
			if ((aa[2] <= 'C' && bb[2] <= 'C') || (aa[2] >= 'D' && bb[2] >= 'D')) {
				cout << "1";
				if ((char(aa[2] + 1) == bb[2]) || (char(bb[2] + 1) == aa[2]) || (aa[2] == 'D' && bb[2] == 'F') || (aa[2] == 'F'
				        && bb[2] == 'D')) {
					cout << "1";
				} else {
					cout << "0";
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
	return 0;
}
