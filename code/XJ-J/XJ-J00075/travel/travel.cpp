#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 != s3) {
		cout << "0000";
		return 0;
	}
	cout << "1";
	int a, b;
	if (s2[0] == '0') {
		a = (s2[1] - '0') + (s2[0] - '0');
	} else {
		a = (s2[1] - '0') + (s2[0] - '0') * 10;
	}
	if (s4[0] == '0') {
		b = (s4[1] - '0') + (s4[0] - '0');
	} else {
		b = (s4[1] - '0') + (s4[0] - '0') * 10;
	}
	if (a == b) {
		cout << "1";
		if ((s2[2] == 'A' or s2[2] == 'B' or s2[2] == 'C') and (s4[2] == 'A' or s4[2] == 'B' or s4[2] == 'C')) {
			cout << "1";
		} else if ((s2[2] == 'F' or s2[2] == 'D') and (s4[2] == 'F' or s4[2] == 'D')) {
			cout << "1";
		} else {
			cout << "0";
		}
	} else {
		cout << "000";
		return 0;
	}
	if (s2[2] == 'A' and s4[2] == 'B') {
		cout << "1";
	} else if (s2[2] == 'B' and s4[2] == 'C') {
		cout << "1";
	} else if (s2[2] == 'D' and s4[2] == 'F') {
		cout << "1";
	} else if (s2[2] == 'B' and s4[2] == 'A') {
		cout << "1";
	} else if (s2[2] == 'C' and s4[2] == 'B') {
		cout << "1";
	} else if (s2[2] == 'F' and s4[2] == 'D') {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
} 
