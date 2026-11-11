#include <bits/stdc++.h>
using namespace std;

int hui(char ap, char bp) {
	if (ap == 'A') {
		if (bp == 'B') {
			return 1;
		} else {
			return 0;
		}
	}
	if (ap == 'B') {
		if (bp == 'A') {
			return 1;
		} else if (bp == 'C') {
			return 1;
		} else {
			return 0;
		}
	}
	if (ap == 'C') {
		if (bp == 'B')
			return 1;
		else {
			return 0;
		}
	}
	if (ap == 'D') {
		if (bp == 'F')
			return 1;
		else {
			return 0;
		}
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int A, B;
	string Aa, Bb;
	cin >> A >> Aa >> B >> Bb;
	if (A == B) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	char a = Aa[0];
	char aa = Aa[1];
	char b = Bb[0];
	char bb = Bb[1];
	if (a == b && aa == bb) {
		cout << 1;
	} else {
		cout << 0;
	}
	if ((Aa[2] < 'D' && Bb[2] < 'D') || (Aa[2] > 'C' && Bb[2] > 'C')) {
		if (a == b && aa == bb) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}
	int o = a - '0';
	int m = aa - '0';
	int p = b - '0';
	int h = bb - '0';
	int u = o * 10 + m;
	int i = p * 10 + h;
	if (u == i && hui(Aa[2], Bb[2])) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}