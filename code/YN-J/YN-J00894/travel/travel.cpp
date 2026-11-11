#include <bits/stdc++.h>
using namespace std;
char r, x;
string r1, r2, x1, x2;
int a, b, c, d, r11, x11, r22, x22;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> r1 >> r2 >> x1 >> x2;
	r11 = int(r1[0] - '0') * 10 + int(r1[1] - '0');
	x11 = int(x1[0] - '0') * 10 + int(x1[1] - '0');
	a = (x11 == r11);
	r22 = int(r2[0] - '0') * 10 + int(r2[1] - '0');
	x22 = int(x2[0] - '0') * 10 + int(x2[1] - '0');
	b = (r22 == x22);
	r = r2[2];
	x = x2[2];
	if (r >= 'A' && r <= 'C' && x >= 'A' && x <= 'C')
		d = 1;
	else if (r >= 'D' && r <= 'F' && x >= 'D' && x <= 'F')
		d = 1;
	if (r == 'D' && x == 'F' || r == 'F' && x == 'D')
		c = 1;
	else if (r == 'A' && x == 'B' || r == 'B' && x == 'A')
		c = 1;
	else if (r == 'B' && x == 'C' || r == 'C' && x == 'B')
		c = 1;
	cout << a << (b == 1 && a == 1) << (a == 1 && d == 1 && b == 1) << (a == 1 && b == 1 && c == 1 && d == 1);
	return 0;
}