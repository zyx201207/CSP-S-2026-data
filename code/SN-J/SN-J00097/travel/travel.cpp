#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d, c1, d1;
	char c2, d2;
	cin >> a>> c >> b >> d;
	c1 += c[0];
	c1 += c[1];
	c2 = c[2];
	d1 += d[0];
	d1 += d[1];
	d2 = d[2];
	if (a == b ) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	if (c1 == d1) cout << 1;
	else {
		cout << "000" ;
		return 0;
	}
	if (c1 == d1 && (c2 >= 'A' && c2 <= 'C' && d2 >= 'A' && d2 <= 'C' || c2 >= 'D' && c2 <= 'E' && d2 >= 'D' && d2 <= 'E')) cout << 1;
	else {
		cout << "00";
		return 0;
	}
	if (c2 == 'A' && d2 == 'B' || c2 == 'B' && d2 == 'C' || c2 == 'D' && d2 == 'E' || d2 == 'B' && c2 == 'C' || d2 == 'A' && c2 == 'B'  || d2 == 'D' && c2 == 'E') cout << 1;
	else cout << 0;
	return 0;
}
