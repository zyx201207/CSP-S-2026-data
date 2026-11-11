#include <bits/stdc++.h>
using namespace std;

bool check1(char a, char b) {
	if (a - 'A' <= 2) {
		if (b - 'A' <= 2) return true;
		return false;
	}
	if (b - 'A' <= 2) return false;
	return true;
}

bool check2(char a, char b) {
	if (a == 'A' && b == 'B') return true;
	if (a == 'B' && b == 'C') return true;
	if (a == 'D' && b == 'F') return true;
	return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, s1, c2, s2;
	char v1, v2;
	cin >> c1 >> s1 >> v1 >> c2 >> s2 >> v2;
	if (c1 != c2) {
		cout << "0000";
	} else if (s1 != s2) {
		cout << "1000";
	} else if (!check1(v1, v2)) {
		cout << "1100";
	} else if (!check2(v1, v2)) {
		cout << "1110";
	} else {
		cout << "1111";
	}
	return 0;
}