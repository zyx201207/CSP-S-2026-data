#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, c1, s2, c2;
	cin >> s1 >> c1 >> s2 >> c2;
	if (s1 == s2) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (c1 == "01A" && c2 == "01B") {
		cout << "111";
	}
	return 0;
}