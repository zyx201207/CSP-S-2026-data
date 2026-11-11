#include <bits/stdc++.h>
using namespace std;
long long a[200001];

string zhuang(long long x) {
	string s, s1;
	for (;;) {
		if (x == 0) {
			break;
		}
		s += x % 2 + '0';
		x /= 2;
	}
	for (long long i = s.size() - 1; i >= 0; i--) {
		s1 += s[i];
	}
	return s1;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long ma = -1;
	if (m == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				string an, z = zhuang(a[i]), y = zhuang(a[j]);
				long long h = 0;
				if (z.size() == y.size()) {
					for (long long v = 0; v < z.size(); v++) {
						if (z[v] == '1' && y[v] == '1') {
							an += '1';
						} else {
							an += '0';
						}
					}
				} else {
					long long bi = min(z.size(), y.size());
					if (bi = y.size()) {
						for (long long v = z.size(); v >= 0 ; v--) {
							bi--;
							if (z[v] == '1' && y[bi] == '1') {
								 an= '1'+an;
							} else {
								an = '0'+an;
							}
						}
					} else {
						for (long long v = y.size(); v >= 0 ; v--) {
							bi--;
							if (z[v] == '1' && y[bi] == '1') {
								an = '1'+an ;
							} else {
								an = '0'+an ;
							}
						}
					}
				}

				int ci = 1;
				for (long long v = an.size() - 1; v >= 0 ; v--) {
					h += ci * (an[v] - '0');
					ci *= 2;
				}
				if (ma < h) {
					ma = h;
				}
			}
		}
		cout << ma;
	} else {
		cout << '0';
	}
	return 0;
}