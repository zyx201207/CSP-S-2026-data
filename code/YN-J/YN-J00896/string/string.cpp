#include <bits/stdc++.H>
using namespace std;

struct pat {
	int  m;
	char s;
};

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long  n;
	cin >> n;
	pat a[200001];
	long long sum;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].m >> a[i].s;
		sum += a[i].m;
	}
	long long l = 1, r = n, al = a[1].m, ar = a[n].m, ans = 0, cnt = 0;
	if (sum % 2 == 0)
		sum /= 2;
	else
		sum = sum / 2 + 1;
	while (cnt < sum) {
		cnt += al;
		if (a[l].s == a[r].s) {
			if (al > ar) {
				al -= ar;
				r--;
				l++;
				if (a[l].s != a[r].s)
					ans += al;
				else {
					ar = a[r].m - al;
				}
				al = a[l].m;
			} else if (al < ar) {
				ar -= al;
				r--;
				l++;
				if (a[r].s != a[l].s)
					ans += ar;
				else {
					al = a[l].m - ar;
				}
				ar = a[r].m;
			} else {
				r--;
				l++;
				al = a[l].m;
				ar = a[r].m;
			}
		} else if (a[l].s != a[r].s) {
			if (al > ar) {
				al -= ar;
				ans += ar;
				l++;
				r--;
				if (a[l].s != a[r].s)
					ans += al;
				else {
					ar = a[r].m - al;
				}
				al = a[l].m;
			} else if (al < ar) {
				ar -= al;
				ans += al;
				l++;
				r--;
				if (a[r].s != a[l].s)
					ans += ar;
				else {
					al = a[l].m - ar;
				}
				ar = a[r].m;
			} else {
				r--;
				l++;
				ans += al;
				al = a[l].m;
				ar = a[r].m;
			}
		}
	}
	cout << ans;
	return 0;
}