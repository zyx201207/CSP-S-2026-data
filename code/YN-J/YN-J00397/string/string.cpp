#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N = 2e5 + 50;

bool flag = 0;
ull n, a[N], tot, siz, xh, ans;
pair<ull, char>sum[N];
char c[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sum[i].first = sum[i - 1].first + a[i];
		sum[i].second = c[i];
		tot += a[i];
	}
	siz = tot / 2;
	if (tot % 2 == 1)
		siz++, flag = 1;
	for (int i = 1; i <= n; i++) {
		int f = sum[i].first;
		if (f > siz) {
			xh = i;
			break;
		}
	}
	if (flag == 1)
		a[xh]--, tot--, sum[xh].first--;
	else
		xh++;
	ull nai = 0, naj = 0;
	for (int i = xh - 1, j = xh; i > 0 && j <= n;) {
		if (!nai)
			nai = a[i];
		if (!naj)
			naj = a[j];
		if (c[i] == c[j]) {
			if (nai == naj)
				i--, j++, nai = naj = 0;
			else {
				if (nai > naj) {
					j++, nai -= naj;
					naj = 0;
				} else {
					i--, naj -= nai;
					nai = 0;
				}
			}
		} else {
			if (nai == naj) {
				i--, j++, ans += nai;
				nai = naj = 0;
			} else {
				if (nai > naj) {
					j++, nai -= naj, ans += naj;
					naj = 0;
				} else {
					i--, naj -= nai, ans += nai;
					nai = 0;
				}
			}
		}
//		cout << i << ' ' << j << ' ' << nai << ' ' << naj << ' ' << ans << '\n';
	}
	cout << ans;

	return 0;
}
