#include <bits/stdc++.h>
using namespace std;
int c1, c2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int q = 0, w = 0, e = 0;
	if (c1 == c2) {
		cout << "1";
		q = 1;
	} else {
		cout << "0";
	}
	if (q == 1 && (s1[0] + '0') * 10 + (s1[1] + '0') == (s2[0] + '0') * 10 + (s2[1] + '0')) {
		cout << "1";
		e = 1;
	} else {
		cout << "0";
	}
	if (e == 1 && ((s1[2] >= 'D' && s2[2] >= 'D') || (s1[2] <= 'C' && s2[2] <= 'C'))) {
		cout << "1";
		w = 1;
	} else {
		cout << "0";
	}
	if (w == 1 && !((s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A'))) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}