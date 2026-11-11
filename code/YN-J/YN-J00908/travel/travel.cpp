#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travle.in", "r", stdin);
	freopen("travle.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, c1;
	int s, s1;
	char a, a1;
	cin >> c >> s >> a >> c1 >> s1 >> a1;
	if (c == c1)
		cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	if (s == s1)
		cout << 1;
	else {
		cout << "000";
		return 0;
	}
	if (a == 'A' || a == 'B' || a == 'C') {
		if (a1 == 'A' || a1 == 'B' || a1 == 'C') {
			cout << 1;
		} else {
			cout << "00";
			return 0;
		}
	} else {
		if (a1 == 'D' || a1 == 'F')
			cout << 1;
		else {
			cout << "00";
			return 0;
		}
	}
	int q = a - 'A', w = a1 - 'A';
	if (a == 'C' && a1 == 'D' || a == 'D' && a1 == 'C') {
		cout << 0;
		return 0;
	} else if (abs(q - w) == 1)
		cout << 1;
	else
		cout << 0;
	return 0;
}