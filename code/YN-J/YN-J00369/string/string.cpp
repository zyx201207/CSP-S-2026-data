#include <bits/stdc++.h>
using namespace std;
string c[1005];

int main() {
	int a = 0, b, f = 1;
	string d;
	cin >> a;
	for (int i = 1; i <= a; i++) {
		cin >> b >> d;
		for (int j = 1; j <= b; j++) {
			c[f] = d;
			f++;
		}
	}
	string n = c[1], o;
	bool p = 1;
	int u = 0;
	for (int i = 2; i <= f - 1; i++) {
		p = 1;
		for (int j = 1; j <= f / 2; j++) {
			if (c[j] != c[f - j]) {
				p = 0;

				break;
			}
		}
		if (p == 1) {
			cout << u;
		}
		if (c[i] == n) {
			o = c[i];
			c[i] = c[f - i];
			c[f - i] = o;
			u++;
		}
		n = c[i];
	}
	cout << u;
}