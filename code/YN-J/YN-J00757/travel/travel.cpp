#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main() {

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);


	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 != c2) {
		cout << "0000" << "\n";
		return 0;
	}

	string p1 = "", p2 = "";
	p1 += s1[0];
	p1 += s1[1];
	p2 += s2[0];
	p2 += s2[1];
	if (p1 != p2) {
		cout << "1000" << "\n";
		return 0;
	}

	if (s1[2] <= 'C' && s2[2] >= 'D') {
		cout << "1100" << "\n";
		return 0;
	}
	if (s1[2] >= 'D' && s2[2] <= 'C') {
		cout << "1100" << "\n";
		return 0;
	}

	if (abs(s1[2] - s2[2]) != 1) {
		cout << "1110" << "\n";
		return 0;
	}

	cout << "1111" << "\n";

	return 0;
}