#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int f, k;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != c[i]) {
			cout << '0';
			f = 1;
			break;
		}
	}
	if (f == 1) {
		cout << '0' << '0' << '0';
		return 0;
	} else {
		cout << '1';
	}
	for (int i = 0; i < 2; i++) {
		if (b[i] != d[i]) {
			cout << 0;
			f = 1;
			break;
		}
	}
	if (f == 1) {
		cout << '0' << '0';
		return 0;
	} else {
		cout << '1';
	}
	for (int i = 2; i < 3; i++) {
		if (b[i] == 'C' && (d[i] == 'B' || d[i] == 'A'))
			k = 1;
		else if (b[i] == 'A' && (d[i] == 'B' || d[i] == 'C'))
			k = 1;
		else if (b[i] == 'B' && (d[i] == 'A' || d[i] == 'C'))
			k = 1;
		else if (b[i] == 'D' && d[i] == 'F')
			k = 1;
		else if (b[i] == 'F' && d[i] == 'D')
			k = 1;
		else if (d[i] == 'C' && (b[i] == 'B' || b[i] == 'A'))
			k = 1;
		else if (d[i] == 'A' && (b[i] == 'B' || b[i] == 'C'))
			k = 1;
		else if (d[i] == 'B' && (b[i] == 'A' || b[i] == 'C'))
			k = 1;
		else if (d[i] == 'D' && b[i] == 'F')
			k = 1;
		else if (d[i] == 'F' && b[i] == 'D')
			k = 1;
	}
	if (k == 0) {
		cout << '0' << '0';
		return 0;
	} else {
		cout << '1';
	}
	k = 0;
	for (int i = 0; i < b.size(); i++) {
		if (i == b.size() - 1) {
			if (b[i] == 'C' && d[i] == 'B')
				k = 1;
			else if (b[i] == 'A' && d[i] == 'B')
				k = 1;
			else if (b[i] == 'B' && (d[i] == 'A' || d[i] == 'C'))
				k = 1;
			else if (b[i] == 'D' && d[i] == 'F')
				k = 1;
			else if (b[i] == 'F' && d[i] == 'D')
				k = 1;
			else if (d[i] == 'C' && b[i] == 'B')
				k = 1;
			else if (d[i] == 'A' && b[i] == 'B')
				k = 1;
			else if (d[i] == 'B' && (b[i] == 'A' || b[i] == 'C'))
				k = 1;
			else if (d[i] == 'D' && b[i] == 'F')
				k = 1;
			else if (d[i] == 'F' && b[i] == 'D')
				k = 1;
		}
	}
	if (k == 1)
		cout << '1';
	else
		cout << '0';
	return 0;
}