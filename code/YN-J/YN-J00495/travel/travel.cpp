#include <bits/stdc++.h>
using namespace std;
string s[5];

int cf(string a) {
	int sum = 0;

	for (int i = 0; i < a.size(); i++) {

		if (a[i] >= '0' && a[i] <= '9') {
			sum *= 10;
			sum += a[i] - '0';
		}
	}

	return sum;
}

char cfc(string a) {
	return a[a.size() - 1];
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	for (int i = 0; i < 4; i++) {

		cin >> s[i];
	}

	if (s[0] == s[2]) {
		cout << 1;
	} else
		cout << 0;

	if (s[0] == s[2] && cf(s[1]) == cf(s[3]))
		cout << 1;
	else
		cout << 0;

	if (s[0] == s[2] && cf(s[1]) == cf(s[3]) && (cfc(s[1]) <= 'C' && cfc(s[3]) <= 'C') || (cfc(s[1]) >= 'D'
	        && cfc(s[3]) >= 'D'))
		cout << 1;
	else
		cout << 0;

	if (s[0] == s[2] && cf(s[1]) == cf(s[3]) && (abs(cfc(s[1]) - cfc(s[3])) == 1 ) && (cfc(s[1]) != 'C' && cfc(s[3]) != 'D')
	        && (cfc(s[3]) != 'C' && cfc(s[1]) != 'D'))
		cout << 1;
	else
		cout << 0;

	return 0;
}