#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, x[N];
long long ans, tot;
char s[N];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> s[i];
		tot += x[i];
	}
	bool flag = 0;
	if (tot % 2 == 0) {
		flag = 0;
	}  else {
		flag = 1;
	}
	int f = 2;
	int la = 0;
	long long L = 0, R = tot; 
	int l = 1, r = n;
	while (l <= r) {
		if (la == 0) {
			if (s[l] != s[r]) {
				if (x[l] > x[r]) {
					la = x[l] - x[r];
					ans += x[r];
					R -= x[r];
					f = 0;
					--r;
				} else if (x[l] == x[r]) {
					la = x[l] - x[r];
					ans += x[r];
					L += x[l];
					R -= x[r];
					++l, --r;
					f = 2;
				} else if (x[l] < x[r]) {
					la = x[r] - x[l];
					ans += x[l];
					L += x[l];
					f = 1;
					++l;
				}
			} else {
				if (x[l] > x[r]) {
					la = x[l] - x[r];
					R -= x[r];
					f = 0, --r;
				} else if (x[l] == x[r]) {
					la = x[l] - x[r];
					L += x[l];
					R -= x[r];
					++l, --r;
					f = 2;
				} else if (x[l] < x[r]) {
					la = x[r] - x[l];
					L += x[l];
					f = 1, ++l;
				}
			}
		} else {
			if (s[l] != s[r]) {
				if (f == 0) {
					if (la == x[r]) {
						++l, --r;
						L += x[l];
						R -= x[r]; 
						ans += la;
						la = 0;
					} else if (la > x[r]) {
						la = la - x[r];
						ans += x[r];
						R -= x[r];
						f = 0, --r;
					} else if (la < x[r]) {
						ans += la;
						la = x[r] - la;
						f = 1, ++l;
						L += x[l];
					}
				} else if (f == 1) {
					if (la == x[l]) {
						++l, --r;
						L += x[l];
						R -= x[r]; 
						ans += la;
						la = 0;
					} else if (la > x[l]) {
						la = la - x[l];
						ans += x[l];
						L += x[l];
						f = 1, ++l;
					} else if (la < x[l]) {
						ans += la;
						la = x[l] - la;
						R -= x[r];
						f = 0, --r;
					}
				}
			} else {
				if (f == 0) {
					if (la == x[r]) {
						la = 0;
						L += x[l];
						R -= x[r];
						++l, --r;
					} else if (la > x[r]) {
						la = la - x[r];
						R -= x[r];
						f = 0, --r;
					} else if (la < x[r]) {
						la = x[r] - la;
						R -= x[r];
						f = 1, ++l;
					}
				} else if (f == 1) {
					if (la == x[l]) {
						la = 0;
						L += x[l];
						R -= x[r];
						++l, --r;
					} else if (la > x[l]) {
						la = la - x[l];
						L += x[l];
						f = 1, ++l;
					} else if (la < x[l]) {
						la = x[l] - la;
						R -= x[r];
						f = 0, --r;
					}
				}
			}
		}
//		cout << l << ' ' << r << '\n';
	}
	cout << ans;
	return 0;
}
/*
6
100000000 a
100000000 a
100000000 a
100000000 b
100000000 b
100000000 b


*/
