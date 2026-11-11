#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, j, k;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	j = s1[0] * 10 + s1[1] * 10;
	k = s2[0] * 10 + s2[1] * 10;
	if (c1 == c2) {
		cout << "1";

	} else {
		cout << "0";
	}
	if (c1 == c2 && j == k) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (c1 == c2 && j == k && s1 == s2) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (c1 == c2 && j == k && s1 == s2) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}