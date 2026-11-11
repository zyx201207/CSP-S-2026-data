#include <bits/stdc++.h>
using namespace std;
string a, b, c, d, ans = "";

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	int x1 = 0, x2 = 0;
	for (int i = 0; i < a.size(); i++) {
		x1 *= 10;
		x2 *= 10;
		x1 += (a[i] - '0');
		x2 += (c[i] - '0');
	}
	if (x1 == x2) {
		ans += "1";
	} else {
		ans = "0000";
		cout << ans;
		return 0;
	}
	int y1 = 0, y2 = 0;
	for (int i = 0; i < b.size() - 1; i++) {
		y1 *= 10;
		y2 *= 10;
		y1 += (b[i] - '0');
		y2 += (d[i] - '0');
	}
	if (y1 == y2) {
		ans += "1";
	} else {
		ans += "000";
		cout << ans;
		return 0;
	}
	int len = b.size();
	char c1 = b[len - 1];
	char c2 = d[len - 1];
	if ((c1 > 'C' && c2 > 'C') || (c1 <= 'C' && c2 <= 'C')) {
		ans += '1';
	} else {
		ans += "00";
		cout << ans;
		return 0;
	}
	if (abs(int(c1 - c2)) == 1) {
		ans += '1';
	} else {
		ans += '0';
	}
	cout << ans;
	return 0;
}
