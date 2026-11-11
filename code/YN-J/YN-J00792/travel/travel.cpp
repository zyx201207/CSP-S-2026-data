#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1, c2, s1, s2, ss;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		ss += '1';
		string h1, h2;
		h1 = s1.substr(0, 2);
		h2 = s2.substr(0, 2);
		if (h1 == h2) {
			ss += '1';
			if (s1[2] == 'A') {
				if (s2[2] == 'B')
					ss += "11";
				else if (s2[2] == 'C')
					ss += "10";
				else
					ss += "00";
			} else if (s1[2] == 'B') {
				if (s2[2] == 'A' || s2[2] == 'C')
					ss += "11";
				else
					ss += "00";
			} else if (s1[2] == 'C') {
				if (s2[2] == 'A')
					ss += "10";
				else if (s2[2] == 'B')
					ss += "11";
				else
					ss += "00";
			} else if (s1[2] == 'D') {
				if (s2[2] == 'F')
					ss += "11";
				else
					ss += "00";
			} else if (s1[2] == 'F') {
				if (s2[2] == 'D')
					ss += "11";
				else
					ss += "00";
			}
		} else
			ss += "000";
	} else {
		ss = "0000";
	}
	cout << ss;
	return 0;
}