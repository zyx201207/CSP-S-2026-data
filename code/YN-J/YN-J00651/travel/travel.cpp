#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, s1;
	int c2, s2;
	int a, b, c, d;
	cin >> c1 >> c2 >>  s1 >> s2;
	if (c1 == s1) {
		a = 1;
		if (c2 == 'A' && s2 == 'A' && c2 == 'B' && s2 == 'B' && c2 == 'C' && s2 == 'C' && c2 == 'D' && s2 == 'D' && c2 == 'E'
		        && s2 == 'E') {

			b = 0;
			if (c2 == 'A' && s2 == 'B' && c2 == 'B' && s2 == 'C' && c2 == 'C' && s2 == 'D' && c2 == 'D' && s2 == 'E') {
				c = 1;

			}
		}
	}
	cout << a << b << c << d;
	return 0;
}