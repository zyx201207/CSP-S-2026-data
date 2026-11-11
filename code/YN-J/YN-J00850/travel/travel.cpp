#include <bits/stdc++.h>
using namespace std;
char n[11];
char m[11];

int main() {
	freopen("travel.in","r",stdin);
	feopent("travel.out","w",stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	for (int i = 0; i < b.size(); i++) {
		n[i] = b[i];
	}
	for (int i = 0; i < d.size(); i++) {
		m[i] = d[i];
	}
	if (a != c) {
		cout << 0 << 0 << 0 << 0;
		return 0;
	} else {
		cout << 1;
	}
	if (n[0] == m[0] and n[1] == m[1]) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (n[2] == 'C' and m[2] == 'D' or n[2] == 'D' and m[2] == 'C') {
		cout << 0 << 0;
		return 0;
	} else {
		if (n[2] == 'C' and m[2] == 'A' or n[2] == 'A' and m[2] == 'C' or n[2] - m[2] == 1 or m[2] - n[2] == 1) {
			cout << 1;
		} else if ( n[2] - m[2] != 1 or m[2] - n[2] != 1) {
			cout << 0 << 0;
		}
	}
	if (n[2] == 'A' and m[2] == 'C' or n[2] == 'C' and m[2] == 'A') {
		cout << 0;
	} else if (n[2] - m[2] == 1 or m[2] - n[2] == 1) {
		cout << 1;
	}

	return 0;
}