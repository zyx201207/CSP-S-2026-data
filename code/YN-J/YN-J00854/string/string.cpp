#include <bits/stdc++.h>
using namespace std;
long long  a[200005], g, q[200005], sum = 0, ans = 0, j = 1, d, n, l, r, lq, rq;
string c;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> g >> c[j];
		sum += g;
		if (c[j] == c[j - 1]) {
			a[j - 1] += g;
		} else {
			a[j] = g;
			j++;
		}
	}
	for (int i = 1; i < j; i++) {
		q[i] = a[i] + q[i - 1];
	}
	for (int i = 0; i < j; i++) {
		if ((sum + 1) / 2 >= q[i] && (sum + 1) / 2 <= q[i + 1]) {
			ans += abs(((sum + 1) / 2 - q[i] - 1) - (q[i + 1] - (sum + 1) / 2) );
			l = (sum + 1) / 2 - max(((sum + 1) / 2 - q[i] ), (q[i + 1] - (sum + 1) / 2) ) - 1;
			r = (sum + 1) / 2 + max(((sum + 1) / 2 - q[i] ), (q[i + 1] - (sum + 1) / 2) ) + 1;
			break;
		}
	}
	for (int w = 0; l > 0, r <= sum; w++) {
		for (int i = 0; i < j; i++) {
			if (l >= q[i] && l <= q[i + 1]) {
				lq = i + 1;
			}
			if (r >= q[i] && r <= q[i + 1]) {
				rq = i + 1;
			}
		}
		if (c[lq] == c[rq]) {
			l = l - min((l - q[lq - 1]), (q[rq] - r + 1));
			r = r + min((l - q[lq - 1]), (q[rq] - r + 1));
			break;
		} else {
			ans += min((l - q[lq - 1]), (q[rq] - r + 1));
			l = l - min((l - q[lq - 1]), (q[rq] - r + 1));
			r = r + min((l - q[lq - 1]), (q[rq] - r + 1));
			break;
		}
	}

	cout << ans;
	return 0;
}