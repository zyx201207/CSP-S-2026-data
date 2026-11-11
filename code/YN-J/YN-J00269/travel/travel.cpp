#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a = c1[0];
	int a1 = c1[1];
	int b = c2[0];
	int b1 = c2[1];
	if (a == b && a1 == b1) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	int a2 = s1[0];
	int a3 = s1[1];
	int a4 = s1[2];
	int b2 = s2[0];
	int b3 = s2[1];
	int b4 = s2[2];
	if (a2 == b2 && a3 == b3) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	if (65 <= a4 && a4 <= 67 && 65 <= b4 && b4 <= 67 || 68 <= a4 && a4 <= 70 && 68 <= b4 && b4 <= 70) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (68 <= a4 && a4 <= 70 && 68 <= b4 && b4 <= 70) {
		cout << 1;
		return 0;
	}
	if (a4 == 67 && b4 == 68 || b4 == 67 && a4 == 68) {
		cout << 0;
		return 0;
	}
	if (a4 - b4 == 1 || b4 - a4 == 1) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}