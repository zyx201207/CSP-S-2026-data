#include <bits/stdc++.h>
using namespace std;
long long a[200010], lo[200010], aq[200010], loq[200010];
long long n, jsq = 0, zw, yw, l = 0, r = 0, js = 0;
char q;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> lo[i] >> q;
		a[i] = int(q - 'a');
		loq[i] = lo[i];
		aq[i] = a[i];
		js += lo[i];
	}
	reverse(aq, aq + n);
	reverse(loq, loq + n);
	while (l * 2 < js && r * 2 < js) {
		if (a[l] == aq[r]) {
			if (min(lo[l] - zw, loq[r] - yw) == lo[l] - zw) {
				l++;
				yw += lo[l] - zw;
				zw = 0;
			} else {
				r++;
				zw += loq[l] - yw;
				yw = 0;
			}
		} else {
			if (min(lo[l] - zw, loq[r] - yw) == lo[l] - zw) {
				l++;
				yw += lo[l] - zw;
				zw = 0;
				jsq += lo[l] - zw;
			} else {
				r++;
				zw += loq[r] - yw;
				yw = 0;
				jsq += loq[r] - yw;
			}
		}
	}
	cout << jsq / 2;
	return 0;
}