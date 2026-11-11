#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct T {
	ll len = 0;
	char word;
} a[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll n, lenn = 0, needs = 0;
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].len >> a[i].word;
		if (i - 1 >= 0 && a[i].word == a[i - 1].word)
			a[i - 1].len += a[i].len, n--, i--;
	}
	ll xbf = 0, xbb = n - 1;
	ll flen = a[xbf].len, blen = a[xbb].len;
	while (xbf <= xbb) {
		if (flen > blen) {
			if (a[xbf].word != a[xbb].word)
				needs += blen;
			flen -= blen;
			xbb--;
			blen = a[xbb].len;
		} else if (flen < blen) {
			if (a[xbf].word != a[xbb].word)
				needs += flen;
			blen -= flen;
			xbf++;
			flen = a[xbf].len;
		} else {
			if (a[xbf].word != a[xbb].word)
				needs += flen;
			xbf++, xbb--;
			flen = a[xbf].len;
			blen = a[xbb].len;
		}
	}
	cout << needs;
	return 0;
}