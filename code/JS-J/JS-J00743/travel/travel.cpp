#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
	}
	else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	char px1 = s1[0], px2 = s1[1], py1 = s2[0], py2 = s2[1];
	char z1 = s1[2], z2 = s2[2];
	if (px1 == py1 && px2 == py2) {
		cout << 1;
		if (((z1 == 'A' || z1 == 'B' || z1 == 'C') && (z2 == 'A' || z2 == 'B' || z2 == 'C')) || ((z1 == 'D' || z1 == 'F') && (z2 == 'D' || z2 == 'F'))) {
			cout << 1;
			if (abs((z1 - 'A') - (z2 - 'A')) == 1 || (z1 == 'D' && z1 == 'F') || (z1 == 'F' && z2 == 'D')) {
				cout << 1;
			}
			else {
				cout << 0;
			}
		}
		else {
			cout << 0 << 0;
			return 0;
		}
	}
	else {
		cout << 0 << 0;
	}
	
}
