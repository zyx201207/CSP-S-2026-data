#include <bits/stdc++.h>
using namespace std;
string out_;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		out_[1] = 1;
	}
	if ((s1[1] == s2[1]) && (s1[0] == s2[0]) && out_[1] == 1) {
		out_[2] = 1;
	}
	if ((s1[1] == 'A' || s1[1] == 'B' || s1[1] == 'C') && out_[2] == 1) {
		if ((s2[1] == 'A' || s2[1] == 'B' || s2[1] == 'C') && out_[2] == 1) {
			out_[3] = 1;
		}
	}
	if ((s1[1] == 'F' || s1[1] == 'D')) {
		if ((s2[1] == 'F' || s2[1] == 'D')) {
			out_[3] = 1;
		}
	}
	if (out_[3] == 1) {
		if (s1[2] + 1 == s2[2]) {
			out_[4] = 1;
		}
		if (s1[2] - 1 == s2[2]) {
			out_[4] = 1;
		}
		if (s1[2] == 'F' && s2[2] == 'D') {
			out_[4] = 1;
		}
		if (s2[2] == 'F' && s1[2] == 'D') {
			out_[4] = 1;
		}
	}
	for (int i = 1; i <= 4; i++) {
		cout << out_[i];
	}
	return 0;
}