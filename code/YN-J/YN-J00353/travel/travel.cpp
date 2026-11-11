#include <bits/stdc++.h>
using namespace std;
int c1, c2;
char s1[4], s2[4];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1;
	for (int i = 1; i <= 3; i++) {
		cin >> s1[i];
	}
	cin >> c2;
	for (int i = 1; i <= 3; i++) {
		cin >> s2[i];
	}
	if (c1 == c2)
		cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	if (s1[1] == s2[1] && s1[2] == s2[2]) {
		cout << '1';
	} else {
		cout << "000";
		return 0;
	}
	if (s1[3] <= 'C' && s2[3] <= 'C') {
		cout << '1';
	} else if (s1[3] > 'C' && s1[3] <= 'F' && s1[3] > 'C' && s2[3] <= 'F') {
		cout << '1';
	} else {
		cout << "00";
		return 0;
	}
	if (s1[3] <= 'C' && s2[3] <= 'C') {
		if (int(s1[3] - s2[3]) == 1 || int(s1[3] - s2[3]) == -1)
			cout << '1';
		else {
			cout << '0';
			return 0;
		}
	} else if (s2[3] > 'C' && s2[3] <= 'F' && s1[3] > 'C' && s1[3] <= 'F') {
		cout << '1';
	} else {
		cout << '0';
		return 0;
	}
}