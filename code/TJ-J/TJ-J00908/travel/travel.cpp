#include <bits/stdc++.h> 
using namespace std;
string c1, s1, c2, s2, a, b;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		cout << 1;
	else
		cout << 0;
	a += s1[0];
	a += s1[1];
	b += s2[0];
	b += s2[1];
	if (c1 == c2) {
		if (a == b)
			cout << 1;
		else
			cout << 0;
	}
	else
		cout << 0;
	if (c1 == c2) {
		if (a == b) {
			if (('A' <= s1[2] && s1[2] <= 'C') && ('A' <= s2[2] && s2[2] <= 'C') || ('D' <= s1[2] && s1[2] <= 'F') && ('D' <= s2[2] && s2[2] <= 'F'))
				cout << 1;
			else
				cout << 0;
		}
		else
			cout << 0;
	}
	else
		cout << 0;
	if (c1 == c2) {
		if (a == b) {
			if (('A' <= s1[2] && s1[2] <= 'C') && ('A' <= s2[2] && s2[2] <= 'C') || ('D' <= s1[2] && s1[2] <= 'F') && ('D' <= s2[2] && s2[2] <= 'F')) {
				if (((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) || (abs(s1[2] - s2[2]) == 1))
					cout << 1;
				else
					cout << 0;
			}
			else
				cout << 0;
		}
		else
			cout << 0;
	}
	else
		cout << 0;
	return 0;
}
