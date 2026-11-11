#include <bits/stdc++.h>
using namespace std;

struct shuru {
	char c;
	int n;
	int qi, zhi;
};
shuru s[2000005];
long long sum = 1, z, l, r, ans = 0, p = 1, templ, tempr;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].n >> s[i].c;
		s[i].qi = sum;
		sum += s[i].n;
		s[i].zhi = sum - 1;
	}

	templ = s[p].n;
	tempr = s[n].n;
	while (p < n) {
		l = 1;
		r = 1;
		if (s[p].c != s[n].c) {
			ans += min(templ, tempr);
		}
		l += min(templ, tempr);
		r += min(templ, tempr);
		templ = templ - l + 1;
		tempr = tempr - r + 1;
		if (templ <= 0) {
			p++;
			templ = s[p].n;
		}
		if (tempr <= 0) {
			n--;
			tempr = s[n].n;
		}
	}
	cout << ans;
	return 0;
}
