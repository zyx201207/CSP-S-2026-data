#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a1, a2, s1, s2;
	cin >> a1 >> s1 >> a2 >> s2;
	string a = " ", b = " ";
	char x = s1[2], y = s2[2];
	a = s1[1] + s1[0];
	b = s2[1] + s2[0];
	bool  n, m, p, q;
	n = (a1 == a2);
	m = ((a == b) && n == 1);
	p = ((x <= 'C' && y <= 'C' || x >= 'D' && y >= 'D') && m == 1);
	q = ((abs(x - y) == 1 && (x == 'C' && y != 'D' || x == 'D' && y != 'C')) && p);
	cout << n << m << p << q;
	return 0;
}