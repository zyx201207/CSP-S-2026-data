#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("trevel.in", "r", stdin);
	freopen("trevel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	string ans = "";
	if (a == c) {
		ans += "1";
	} else {
		cout << "0000";
		return 0;
	}
	if (b[0] == d[0] && b[1] == d[1]) {
		ans += "1";
	} else {
		cout << "1000";
		return 0;
	}
	if ((b[2] < 'd' && d[2] < 'd') || (b[2] > 'c' && d[2] > 'c')) {
		ans += "1";
	} else {
		cout << "1100";
		return 0;
	}
	if (b[2] - d[2] == 1 || d[2] - b[2] == 1 || ((b[2] == 'F' || b[2] == 'D') && (d[2] - b[2] == 2 || b[2] - d[2] == 2))) {
		ans += "1";
	} else {
		ans += "0";
	}
	cout << ans ;
	return 0;
}