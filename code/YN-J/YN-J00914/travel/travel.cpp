#include <bits/stdc++.h>
using namespace std;
char c1[5], s1[5], c2[5], s2[5];
int box = 0, line = 0, which = 0, near = 0;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1[1] >> c1[2];
	cin >> s1[1] >> s1[2] >> s1[3];
	cin >> c2[1] >> c2[2];
	cin >> s2[1] >> s2[2] >> s2[3];
	if (c1[1] == c2[1] && c1[2] == c2[2]) {
		box = 1;
	}
	if (s1[1] == s2[1] && s1[2] == s2[2]) {
		line = 1;
	}
	if ((s1[3] == 'D' && s2[3] == 'C') || (s1[3] == 'C' && s2[3] == 'D')) {
		which = 0;
	} else if (s1[3] - '0' == s2[3] - '0' - 1) {
		which = 1;
		near = 1;
	} else if (s1[3] - '0' - 1 == s2[3] - '0') {
		which = 1;
		near = 1;
	}
	if ((s1[3] == 'A' && s2[3] == 'C') || (s1[3] != 'C' && s2[3] != 'A')) {
		near = 0;
	}

	cout << box << line << which << near;
	return 0;
}