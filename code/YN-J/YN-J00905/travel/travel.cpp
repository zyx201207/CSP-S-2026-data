#include <bits/stdc++.h>
using namespace std;
string cx1, wz1, cx2, wz2;
string c = "";

bool pd(string a, string b) {
	for (int i = 0; i < 2; i++) {
		if (a[i] != b[i])
			return true;
	}
	return false;
}

bool pd2(string a, string b) {
	char x = a[2];
	char y = b[2];
	if (x == 'A' && y == 'D')
		return false;
	if (y == 'A' && x == 'D')
		return false;
	if (x == 'A' && y == 'F')
		return false;
	if (y == 'A' && x == 'F')
		return false;
	if (x == 'B' && y == 'D')
		return false;
	if (y == 'B' && x == 'D')
		return false;
	if (x == 'B' && y == 'F')
		return false;
	if (y == 'B' && x == 'F')
		return false;
	if (x == 'C' && y == 'D')
		return false;
	if (y == 'C' && x == 'D')
		return false;
	if (x == 'C' && y == 'F')
		return false;
	if (y == 'C' && x == 'F')
		return false;
	return true;
}

bool pd3(string a, string b) {
	char x = a[2];
	char y = b[2];
	if (x == 'C' && y == 'D')
		return false;
	if (y == 'C' && x == 'D')
		return false;
	if (x == 'F' && y != 'D')
		return false;
	if (x == 'D' && y != 'F')
		return false;
	if (x == 'F' && y != 'D')
		return false;
	if (abs(abs(int(x)) - abs(int(y))) != 1)
		return false;
	return true;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> cx1 >> wz1 >> cx2 >> wz2;
	if (cx1 != cx2)
		c += '0';
	else
		c += '1';

	if (cx1 != cx2 || pd(wz1, wz2))
		c += '0';
	else
		c += '1';

	if (cx1 != cx2 || pd(wz1, wz2) || !pd2(wz1, wz2))
		c += '0';
	else
		c += '1';

	if (cx1 != cx2 || pd(wz1, wz2) || !pd2(wz1, wz2) || !pd3(wz1, wz2))
		c += '0';
	else
		c += '1';

	cout << c;
	return 0;
}