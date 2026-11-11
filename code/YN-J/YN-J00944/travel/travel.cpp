#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("travel.in""r"stdin)
	//freopen("travel.out""w"stdout)
	int c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 = c2) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (c1 = c2 && s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (c1 = c2 && s1[0] == s2[0] && s1[1] == s2[1] && s2[2] >= 'A' && s1[2] >= 'A' && s1[2] >= 'c' && s2[2] >= 'c'
	         || s2[2] >= 'D' && s1[2] >= 'D') {
		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}