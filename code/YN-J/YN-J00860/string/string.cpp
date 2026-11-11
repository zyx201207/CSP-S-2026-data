#include <bits/stdc++.h>
using namespace std;


struct N {
	int n;
	char t;
};


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int n;
	cin >> n;
	N s[n + 3];
	long long num = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i].n >> s[i].t;
		num += s[i].n ;
	}
	long long nl, nr;
	nl = num / 2;
	nr = num / 2;
	int t1 = 0, t2 = n - 1;
	long long ans = 0;
	bool l = 1, r = 1;
	while (nl > 0 && nr > 0) {
		if (nl - s[t1].n < 0) {
			l = 0;
		}
		if (nr - s[t2].n < 0) {
			r = 0;
		}

		if (s[t1].t != s[t2].t) {
			ans += min (s[t1].n, s[t2].n);
			if (s[t1].n > s[t2].n) {
				s[t1].n -= s[t2].n;
				nl -= s[t2].n;
				nr -= s[t2].n;
				t2--;
			} else {
				if (s[t1].n < s[t2].n) {
					s[t2].n -= s[t1].n;
					nl -= s[t1].n;
					nr -= s[t1].n;
					t1++;
				} else {
					nl -= s[t1].n;
					nr -= s[t2].n;
					t2--;
					t1++;
				}
			}
		} else {
			if (nl - s[t1].n < 0 && r) {
				nr -= s[t2].n;
				t2--;
			} else {
				if (nr - s[t2].n < 0 && l) {
					nl -= s[t1].n;
					t1++;
				} else {
					if (l && r) {
						nl -= min (s[t1].n, s[t2].n);
						nr -= min (s[t1].n, s[t2].n);
						if (s[t1].n > s[t2].n) {

							s[t1].n -= min (s[t1].n, s[t2].n);
							t2--;
						} else {

							s[t2].n -= min (s[t1].n, s[t2].n);
							t1++;
						}
					}
				}
			}
		}

		if (s[t1].n < 0) {
			s[t1 + 1].n += s[t1].n;
			t1++;
		}

		if (s[t2].n < 0) {
			s[t2 - 1].n += s[t2].n;
			t2--;
		}
		if (t1 == t2) {
			break;
		}
	}

	cout << ans;



	return 0;
}