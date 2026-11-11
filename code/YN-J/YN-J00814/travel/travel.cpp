#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, s1;
	string c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == s1) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0 << 0 ;
		return 0;
	}
	if (c2[1] == s2[1]) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0;
		return 0;
	}
	if (c2[2] == 'A' && s2[2] == 'B' || c2[2] == 'B' && s2[2] == 'A' || c2[2] == 'B' && s2[2] == 'C' || c2[2] == 'C'
	        && s2[2] == 'B' || c2[2] == 'C' && s2[2] == 'D' || c2[2] == 'D' && s2[2] == 'C' || c2[2] == 'D' && s2[2] == 'E'
	        || c2[2] == 'E' && s2[2] == 'D' || c2[2] == 'E' && s2[2] == 'F' || c2[2] == 'F' && s2[2] == 'E') {
		cout << 1;
	} else {
		cout << 0 << 0;
		return 0;
	}
	if (c2[2] == 'A' && s2[2] == 'B' || c2[2] == 'B' && s2[2] == 'A' || c2[2] == 'B' && s2[2] == 'C' || c2[2] == 'C'
	        && s2[2] == 'B' || c2[2] == 'C' && s2[2] == 'D' || c2[2] == 'D' && s2[2] == 'C' || c2[2] == 'D' && s2[2] == 'E'
	        || c2[2] == 'E' && s2[2] == 'D' || c2[2] == 'E' && s2[2] == 'F' || c2[2] == 'F' && s2[2] == 'E') {
		cout << 1;
	} else {
		cout << 0 << 0;
		return 0;
	}
	return 0;
}
