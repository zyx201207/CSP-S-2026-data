#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int c1, c2;

bool check(char x, char y) {
	if (x == 'A' && y == 'B') {
		return true;
	} else if (x == 'B' && (y == 'C' || y == 'A')) {
		return true;
	} else if (x == 'C' && y == 'B') {
		return true;
	} else if (x == 'D' && y == 'F') {
		return true;
	} else if (x == 'F' && y == 'D') {
		return true;
	}
	return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	} 
	cout << '1';
	int x = int(s1[0]) * 10 + int(s1[1]);
	int y = int(s2[0]) * 10 + int(s2[1]);
	if (x != y) {
		cout << "000";
		return 0;
	}
	cout << '1';
	char a = s1[2], b = s2[2];
	if (check(a, b)) {
		cout << "11";
	} else if ((a == 'A' && b == 'C') || (a == 'C' && b == 'A')) {
		cout << "10";
	} else {
		cout << "00";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
