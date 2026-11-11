#include <bits/stdc++.h>
using namespace std;

bool cx(int i, int j) {
	if (i == j) {
		return 1;
	} else {
		return 0;
	}
}

bool pai(string k, string l) {
	// m = k[0] * 10 + k[1], n = l[0] * 10 + l[1];
	//cout << k[1] << l;
	//cout << "m:" << m << ";" << "n:" << n;
	int m = (k[0] - '0') * 10 + (k[1] - '0'), n = (l[0] - '0') * 10 + (l[1] - '0');
	//cout << "m:" << m << ";" << "n:" << n;
	if (m == n) {
		return 1;
	} else {
		return 0;
	}
}

bool ca(string o, string p) {
	char q = o[2], r = p[2];
	//cout << "m:" << q << ";" << "n:" << r;
	if ((q == 'F' and r == 'D') or (q == 'D' and r == 'F') or ((q == 'A' and r == 'B') or (q == 'A' and r == 'C'))
	        or ((q == 'B' and r == 'A') or (q == 'B' and r == 'C')) or ((q == 'C' and r == 'A') or (q == 'C' and r == 'B'))) {
		return 1;
	} else {
		return 0;
	}
}

bool li(string s, string t) {
	char u = s[2], v = t[2];
	if ((u == 'F' and v == 'D') or (u == 'D' and v == 'F') or (u == 'A' and v == 'B') or ((u == 'B' and v == 'A')
	        or (u == 'B' and v == 'C')) or (u == 'C' and v == 'B')) {
		return 1;
	} else {
		return 0;
	}
}
long long a, c;
string b, d;
long long e = 0, f = 0, g = 0, h = 0;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (cx(a, c)) {
		e = 1;
	}
	if (e == 1) {
		if (pai(b, d)) {
			f = 1;
		}
	}
	if (e == 1 and f == 1) {
		if (ca(b, d)) {
			g = 1;
		}
	}
	if (e == 1 and f == 1 and g == 1) {
		if (li(b, d)) {
			h = 1;
		}
	}
	cout << e << f << g << h;
//	cout << cx(a, c);
	return 0;
}