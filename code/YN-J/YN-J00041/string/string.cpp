#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

struct {
	ll l, r, len;
	char c;
} a[MAXN];
ll sum = 0;
int n;

ll check(ll st, ll end, char tar) {
	ll res = 0LL;
	int le = 1, ri = n, mid, posl, posr;
	while (le <= ri) {
		mid = (le + ri) / 2;
		if (a[mid].l <= st) {
			posl = mid;
			le = mid + 1;
		} else
			ri = mid - 1;
	}
	le = 1, ri = n;
	while (le <= ri) {
		mid = (le + ri) / 2;
		if (a[mid].r >= end) {
			posr = mid;
			ri = mid - 1;
		}
		le = mid + 1;
	}

	for (int i = posl; i <= posr; i++) {
		ll x = max(st, a[i].l), y = min(a[i].r, end);
		if (a[i].c != tar)
			res += y - x + 1;
	}
	return res;

}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	a[0].r = 0;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].len >> a[i].c;
		sum += a[i].len;
		a[i].l = a[i - 1].r + 1;
		a[i].r = a[i].l + a[i].len - 1;
	}

	ll mid = (sum + 1LL) / 2LL;
	int pos1, pos2;
	for (int i = 1; a[i].l < mid; i++) {
		if (a[i].r >= mid) {
			ans += check(sum - mid + 2, sum - a[i].l + 1, a[i].c);
			if (mid > a[i].r) {
				pos1 = i + 1;
				if (a[i + 1].len > 1)
					pos2 = i + 1;
				pos2 = i + 2;
			} else {
				pos1 = i;
				pos2 = i + 1;
			}
		}

		else
			ans += check(sum - a[i].r + 1, sum - a[i].l + 1, a[i].c);
	}
	if (sum % 2 == 1)
		cout << ans;
	else {
		if (pos1 != pos2)
			ans++;
		cout << ans;
	}
	return 0;
}