#include <bits/stdc++.h>
using namespace std ;

struct st {
	long long l;
	char n;
} s[200010];
int n, h, t;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].l >> s[i].n;
	}
	h = 0;
	t = n - 1;
	long long cnt = 0;
	while (h <= t) {
		if (s[h].n == s[t].n) {
			if (s[h].l > s[t].l) {
				s[h].l = s[h].l - s[t].l;
				t--;
			} else if (s[h].l < s[t].l) {
				s[t].l = s[t].l - s[h].l;
				h++;
			} else if (s[h].l == s[t].l) {
				t--;
				h++;
			}
		} else {

			if (s[h].l > s[t].l) {
				s[h].l = s[h].l - s[t].l;
				cnt += s[t].l;
				t--;
			} else if (s[h].l < s[t].l) {
				s[t].l = s[t].l - s[h].l;
				cnt += s[h].l;
				h++;
			} else if (s[h].l == s[t].l) {
				cnt += s[h].l;
				t--;
				h++;
			}

		}
	}

	cout << cnt;
	return 0;
}