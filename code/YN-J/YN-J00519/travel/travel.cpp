#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
int c, s, C, S;
char f[] = {'0', '0', '0', '0'};

int main() {

//	freopen("travel.in", "w", stdin);
//	freopen(" travel.out", "r", stdout);

	cin >> c1 >> s1 >> c2 >> s2;

	if (c1[0] - '0' == 0) {
		c = c1[1] - '0';
	} else {
		c = (c1[0] - '0') * 10 + (c1[1] - '0');
	}
	if (s1[0] - '0' == 0) {
		s = s1[1] - '0';
	} else {
		s = (s1[0] - '0') * 10 + (s1[1] - '0');
	}
	if (c == s) {
		f[0] = '1';
	} else {
		cout << f;
		return 0;
	}

	if (c2[0] - '0' == 0) {
		C = c2[1] - '0';
	} else {
		C = (c2[0] - '0') * 10 + (c2[1] - '0');
	}
	if (s2[0] - '0' == 0) {
		S = s2[1] - '0';
	} else {
		S = (s2[0] - '0') * 10 + (s2[1] - '0');
	}
	if (C == S) {
		f[1] = '1';
	} else {
		cout << f;
		return 0;
	}

	if ( (char(c2[2]) >= 'A' && char(c2[2]) <= 'C' && char(s2[2]) >= 'A' && char(s2[2]) <= 'C') || (char(c2[2]) == 'D'
	        && char(s2[2]) == 'F' || char(s2[2]) == 'D'
	        && char(c2[2]) == 'F') ) {
		f[2] = '1';
	} else {
		cout << f;
		return 0;
	}

	if (char(c2[2]) >= 'A' && char(c2[2]) <= 'C' && char(s2[2]) >= 'A' && char(s2[2]) <= 'C') {
		if ( ((c2[2] - '0') - (s2[2] - '0') == 1) || ((s2[2] - '0') - (c2[2] - '0') == 1)) {
			f[3] = '1';
			cout << f;
		} else {
			cout << f;
			return 0;
		}
	} else if (char(c2[2]) == 'D' && char(s2[2]) == 'F' || char(s2[2]) == 'D' && char(c2[2]) == 'F') {
		f[3] = '1';
		cout << f;
	} else {
		cout << f;
		return 0;
	}

	return 0;
}