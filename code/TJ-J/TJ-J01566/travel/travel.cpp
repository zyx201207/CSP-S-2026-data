#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	short l1, l2;
	char w1, w2;
	bool p, Q;
	l1 = s1[0] * 10 + s1[1];
	l2 = s2[0] * 10 + s2[1];
	w1 = s1[2];
	w2 = s2[2];
	if (c1 == c2) {
		cout << "1";
		Q = 1;
	} else {
		cout << "0";
		Q = 0;
	}
	if (l1 == l2 && Q) {
		cout << "1";
		p = 1;
	} else {
		cout << "0";
		p = 0;
	}
	if (((w1 - 'A' + 1 < 4 && w2 - 'A' + 1 < 4) || (w1 - 'A' + 1 >= 4 && w2 - 'A' + 1 >= 4)) && p && Q) {
		cout << "1";
	} else {
		cout << "0";
	}
	if ((((w1 - 'A' + 1 >= 4 && w2 - 'A' + 1 >= 4) && (w1 - w2 == 2 || w2 - w1 == 2)) || ((w1 - 'A' + 1 < 4
	        && w2 - 'A' + 1 < 4) && (w1 - w2 == 1 || w2 - w1 == 1))) && p && Q) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}