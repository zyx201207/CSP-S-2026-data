#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.ans", "w", stdout);
	int a1, a2;
	string b1, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	bool f = 1;
	if (a1 == a2)
		cout << 1;
	else {

		cout << 0;
		f = 0;

	}
	int s1 = b1[2], s2 = b2[2];
	if ((s1 == s2 + 1 || s1 + 1 == s2 || s1 - 1 == s2 || s2 - 1 == s1) || (s1 == s2 + 2 || s1 + 2 == s2 || s1 - 2 == s2
	        || s2 - 2 == s1) || (s1 == s2 + 3 || s1 + 3 == s2 || s1 - 3 == s2 || s2 - 3 == s1) || (s1 == s2 + 4 || s1 + 4 == s2
	                || s1 - 4 == s2 || s2 - 4 == s1) || (s1 == s2 + 5 || s1 + 5 == s2
	                        || s1 - 5 == s2 || s2 - 5 == s1) && f)
		cout << 1;
	else {
		cout << 0;
		f = 0;
	}

	if ((char(s1) == 'D' || char(s2) == 'D') || char(s2) != 'A' || char(s1) != 'A') {
		cout << 0;
		f = 0;
	}
	else if (f) {
		cout << 1;
	} else {
		cout << 0;
		f = 0;
	}

	int n1 = b1[0] * 10 + b1[1], n2 = b2[0] * 10 + b2[1];
	if ((n1 == n2) && f)
		cout << 1;
	else {
		cout << 0;
	}

	return 0;
}