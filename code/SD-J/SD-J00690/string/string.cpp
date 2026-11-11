#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 200005;

int n;
ll cnt[MAXN], ans;
char c[MAXN];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cnt[i] >> c[i];
	}
	if (n == 1) {cout << "0\n"; return 0;}
	int l = 1, r = n, rl = cnt[1], rr = cnt[n];
	while (l < r) {
		if (rl < rr) {
			if (c[l] != c[r]) {
				ans += rl;
			}
			rr -= rl;
			l++, rl = cnt[l];
		} else if (rl == rr) {
			if (c[l] != c[r]) {
				ans += rl;
			}
			l++, rl = cnt[l];
			r--, rr = cnt[r];
		} else {
			if (c[l] != c[r]) {
				ans += rr;
			}
			rl -= rr;
			r--, rr = cnt[r];
		}
	}
	cout << ans << "\n";
	return 0;
}
