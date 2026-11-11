#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, ans, zlen, len1, len2, cnt1, cnt2, pre[200005];

struct cade {
	ll a, c;
} a[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char s;
		cin >> a[i].a >> s;
		pre[i] = pre[i - 1] + a[i].a, a[i].c = s - 'a';
	}
	ll pos = lower_bound(pre + 1, pre + 1 + n, pre[n] / 2) - pre;
	len1 = pre[n] / 2 - pre[pos - 1], cnt1 = pos;
	if (pre[n] % 2 != 0) {
		if ((pre[n] + 1) / 2 == pre[pos])
			len2 = pre[pos + 1] - pre[pos], cnt2 = pos + 1;
		else if ((pre[n] + 1) / 2 > pre[pos]) {
			if (pre[pos + 1] == (pre[n] + 1) / 2)
				len2 = pre[pos + 2] - pre[pos + 1], cnt2 = pos + 2;
			else
				len2 = pre[pos + 1] - 1 - pre[pos], cnt2 = pos + 1;
		} else
			len2 = pre[pos] - pre[pos - 1] - len1 - 1, cnt2 = pos;
	} else {
		if (pre[pos] == n / 2)
			len2 = pre[pos + 1] - pre[pos], cnt2 = pos + 1;
		else
			len2 = pre[pos] - len1 - pre[pos - 1], cnt2 = pos;
	}
	for (int i = cnt1; i >= 1;) {
		while (1) {
			if (len1 - len2 < 0) {
				if (a[i].c == a[cnt2].c)
					len2 -= len1, i--, len1 = a[i].a;
				else
					len2 -= len1, ans += len1, i--, len1 = a[i].a;
				break;
			}
			if (a[i].c == a[cnt2].c)
				len1 -= len2, cnt2++, len2 = a[cnt2].a;
			else
				len1 -= len2, ans += len2, cnt2++, len2 = a[cnt2].a;
		}
	}
	cout << ans << endl;
	return 0;
}