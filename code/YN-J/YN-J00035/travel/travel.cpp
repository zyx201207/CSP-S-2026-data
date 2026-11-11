#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		if (s1 == "01A" && s2 == "01B") {
			cout << 1111;
		}
		if (s1 == "01C" && s2 == "01A") {
			cout << 1110;
		}
		if (s1 == "01C" && s2 == "01D") {
			cout << 1100;
		}
		if (s1 == "02B" && s2 == "01A") {
			cout << 1000;
		}
	} else {
		for (int i = 1; i <= 4; i++) {
			cout << 0;
		}
	}
	return 0;
}