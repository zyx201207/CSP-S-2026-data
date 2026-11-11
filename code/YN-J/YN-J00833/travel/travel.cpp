//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
int c1[4];

int main() {
	freopen("travle.in", "r", stdin);
	freopen("travle.out", "w", stdout);

//02 01A 02 01B


	int a, c;
	string b, d;
	cin  >> a >>  b  >> c >> d;
//	cout << a << " " << b  << " " << c << " "  << d << endl;
	if (a == c && a != 1 && a != 17) {
		c1[0] = 1;
		if (b[0] == d[0] && b[1] == d[1]) {
			c1[1] = 1;
			if (b[2] <= 'C' && d[2] <= 'C' || b[2] > 'C' && d[2] > 'C') {
				c1[2] = 1;
				if (b[2] + 1 == d[2] || b[2] - 1 == d[2]) {
					c1[3] = 1;
				}
			}
		}
	}
	for (int i = 0; i < 4; i ++)
		cout << c1[i];
	return 0;
}