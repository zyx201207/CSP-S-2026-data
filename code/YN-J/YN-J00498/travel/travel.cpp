#include <bits/stdc++.h>
using namespace std;
#define int long long
string c1, s1, c2, s2;
char b1, b2;
int z1, z2;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> z1 >> b1 >> c2 >> z2 >> b2;
	if (c1 == c2) {
		cout << 1;
	} else {
		cout << 0;
	}

	if (c1 == c2 and z1 == z2) {
		cout << 1;
	} else {
		cout << 0;
	}

	if (c1 == c2 and z1 == z2 and b1 == 'A' and b2 == 'B' or b1 == 'B' and b2 == 'A' or b1 == 'B' and b2 == 'C'
	        or b1 == 'C' and b2 == 'B' or b1 == 'F' and b2 == 'D' or b1 == 'D' and b2 == 'F' or  b1 == 'A' and b2 == 'C'
	        or  b1 == 'C' and b2 == 'A') {
		cout << 1;
	} else {
		cout << 0;
	}

	if (c1 == c2 and z1 == z2 and b1 == 'A' and b2 == 'B' or b1 == 'B' and b2 == 'A' or b1 == 'B' and b2 == 'C'
	        or b1 == 'C' and b2 == 'B' or b1 == 'F' and b2 == 'D' or b1 == 'D' and b2 == 'F') {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
