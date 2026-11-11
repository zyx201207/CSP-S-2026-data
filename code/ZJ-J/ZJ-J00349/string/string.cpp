#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Substr {
	int len;
	char ch;
} a[200005];
int sum;
int ending[200005];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].len >> a[i].ch;
		sum += a[i].len;
		ending[i] = sum;
	}
	int l = 1, r = n, ans = 0, lpos = 1, rpos = sum;
	while (l <= r) {
		if (ending[l] - lpos + 1 <= rpos - ending[r - 1]) {
			int delta = ending[l] - lpos + 1;
			if (a[l].ch == a[r].ch) {
				;
			}
			else {
				ans += delta;
			}
			lpos = ending[l] + 1;
			l++;
			rpos = rpos - delta;
		}
		else {
			int delta = rpos - ending[r - 1];
			if (a[l].ch == a[r].ch) {
				;
			}
			else {
				ans += delta;
			}
			lpos = lpos + delta;
			rpos = ending[r - 1];
			r--;
		}
	}
	cout << ans;
	return 0;
}
