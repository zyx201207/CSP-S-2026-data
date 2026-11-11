#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string snum_1 = "";
	snum_1 += s1[0];
	snum_1 += s1[1];
	char sletter_1 = s1[2];
	string snum_2 = "";
	snum_2 += s2[0];
	snum_2 += s2[1];
	char sletter_2 = s2[2];
	bool sside_1, sside_2;
	if ((sletter_1 <= 'C') && (sletter_1 >= 'A'))
		sside_1 = 0;
	else
		sside_1 = 1;
	if ((sletter_2 <= 'C') && (sletter_2 >= 'A'))
		sside_2 = 0;
	else
		sside_2 = 1;

	if (c1 == c2) {
		cout << 1;
	} else {
		cout << 0;
	}
	if ((c1 == c2) && (snum_1 == snum_2)) {
		cout << 1;
	} else {
		cout << 0;
	}
	if ((c1 == c2) && (snum_1 == snum_2) && (sside_1 == sside_2)) {
		cout << 1;
	} else {
		cout << 0;
	}
	if ((c1 == c2) && (snum_1 == snum_2) && (sside_1 == sside_2) && (abs(short(sletter_1) - short(sletter_2)) == 1)) {
		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}