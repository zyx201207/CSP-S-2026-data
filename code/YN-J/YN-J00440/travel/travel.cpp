#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c, s, c1, s1;
	cin >> c >> s >> c1 >> s1;
	int cx = 0, ps = 0, cx1 = 0, ps1 = 0;
	int cs, cs1;
	for (int i = 0; i < c.size(); i++) {
		cx = cx * 10 + (c[i] - '0');
		cx1 = cx1 * 10 + (c1[i] - '0');
	}
	cout << (cx == cx1) ? 1 : 0;
	for (int i = 0; i < s.size() - 1; i++) {
		ps = ps * 10 + (s[i] - '0');
		ps1 = ps1 * 10 + (s1[i] - '0');
	}
	cout << ((ps == ps1) && (cx == cx1)) ? 1 : 0;
	cs = (s[2] < 'D') ? 1 : 2;
	cs1 = (s1[2] < 'D') ? 1 : 2;
	cout << ((cs == cs1) && (cx == cx1) && (ps == ps1)) ? 1 : 0;
	if (((cs == cs1) && (cx == cx1) && (ps == ps1)) && abs(s1[2] - s[2]) == 1) {
		cout << 1;
	} else {
		if ((s1[2] == 'D' && s[2] == 'F') || (s[2] == 'D' && s1[2] == 'F')) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}