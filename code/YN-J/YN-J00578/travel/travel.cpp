#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c, s, v, d, a, b, e, f;
	cin >> c >> s >> v >> d;
	if (c == v) {
		a = "1";

	} else {
		a = "0";
	}
	if (a == "1") {
		if (s[0] == d[0] && s[1] == d[1]) {
			b = "1";
		} else {
			b = "0";
		}
	} else {
		b = "0";
	}
	if (b == "1") {
		if (s[2] == 'A' || 'B' || 'C' && d[2] == 'A' || 'B' || 'C') {
			e = "1";
		}
		if (s[2] == 'A' || 'B' || 'C' && d[2] == 'D' || 'F') {
			e = "0";
		}
		if (s[2] == 'D' || 'F' && d[2] == 'D' || 'F') {
			e = "1";
		}
		if (s[2] == 'D' || 'F' && d[2] == 'A' || 'B' || 'C') {
			e = "0";
		}
	} else {
		e = "0";
	}
	if (b == "1") {
		if (s[2] == 'A') {
			if (d[2] == 'B') {
				f = "1";
			} else {
				f = "0";
			}

		} else {
			if (s[2] == 'B') {
				if (d[2] == 'A' || 'C') {
					f = "1";
				} else {
					f = "0";
				}
			} else {
				if (s[2] == 'C') {
					if (d[2] == 'B') {
						f = "1";
					} else {
						f = "0";
					}
				} else {
					if (s[2] == 'D') {
						if (d[2] == 'F') {
							f = "1";
						} else {
							f = "0";
						}
					} else {
						if (s[2] == 'F') {
							if (d[2] == 'D') {
								f = "1";
							} else {
								f = "0";
							}
						}
					}
				}
			}
		}
	} else {
		f = "0";
	}
	cout << a << b << e << f;
	return 0;
}