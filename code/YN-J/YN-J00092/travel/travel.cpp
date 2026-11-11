#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;
bool f = 0;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> s1 >> s2 >> s3 >> s4;

	if (s1 == s3) {
		f = 1;
		cout << "1";
	}

	if (f == 1) {
		if (s2[0] == s4[0] && s2[1] == s4[1]) {
			f = 0;
			cout << "1";
		} else
			cout << "00";
	} else {
		cout << "0000";
		return 0;
	}

	if (f == 0) {
		if ((s2[2] < 'D' && s4[2] < 'D') || (s2[2] > 'C' && s4[2] > 'C')) {
			cout << "1";
			f = 1;
		} else
			cout << "0";
	} else
		f = 0;

	if (f == 1) {
		if (abs(s2[2] - s4[2]) == 1)
			cout << "1";
		else
			cout << "0";
	} else
		cout << "0";
	cout << "\n";
	return 0;
}