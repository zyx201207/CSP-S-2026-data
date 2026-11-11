#include <bits/stdc++.h>
using namespace std;
int n, m;
string s, t;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> s >> m >> t;
	if (n != m) {
		cout << "0000";
		return 0;
	} else {
		cout << "1";
		string x = "", y = "";
		char z, v;
		for (char c : s) {
			if ((int)c >= 48 && (int)c <= 57) {
				x += c;
			} else
				z = c;
		}
		for (char c : t) {
			if ((int)c >= 48 && (int)c <= 57) {
				y += c;
			} else
				v = c;
		}
		if (x != y) {
			cout << "000";
			return 0;
		} else
			cout << "1";
		int u, p;
		if (z == 'A' || z == 'B' || z == 'C')
			u = 1;
		else
			u = 0;
		if (v == 'A' || v == 'B' || v == 'C')
			p = 1;
		else
			p = 0;
		if (p == u)
			cout << "1";
		else {
			cout << "00";
			return 0;
		}
		if (p == 0 && u == 0)
			cout << "1";
		else {
			if (z == 'A' && v == 'B')
				cout << "1";
			else if (z == 'C' && v == 'B')
				cout << "1";
			else
				cout << "0";
		}
	}
	return 0;
}