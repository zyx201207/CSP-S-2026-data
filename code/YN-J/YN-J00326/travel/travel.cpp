#include <bits/stdc++.h>
using namespace std;
#define int long long

string aa, bb, cc, dd;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> aa >> bb >> cc >> dd;
	string s;
	if (aa != cc) {
		s += "0000";
	} else {
		s += '1';
		int a = (bb[0] - '0') * 10 + (bb[1] - '0');
		int b = (dd[0] - '0') * 10 + (dd[1] - '0');
		if (a != b) {
			s += "000";
		} else {
			s += "1";
			if ((bb[2] - 'A' <= 2 && dd[2] - 'A' <= 2) || (bb[2] - 'A' >= 3 && dd[2] - 'A' >= 3)) {
				s += "1";
				if (abs((bb[2] - 'A') - (dd[2] - 'A')) <= 1) {
					s += "1";
				} else
					s += "0";
			} else
				s += "00";
		}
	}
	cout << s;
	return 0;
}