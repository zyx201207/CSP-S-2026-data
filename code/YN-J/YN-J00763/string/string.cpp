#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, suma = 0, sum = 0;
string s = "", sa = "";

struct ch {
	int gs;
	char zm;
};
ch a[200005];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].gs >> a[i].zm;
		suma += a[i].gs;
		s += a[i].zm;
	}
	int l = 1, r = n, sy = 0;
	while (l <= r) {
		sy = abs(a[l].gs - a[r].gs);
		if (a[l].zm != a[r].zm) {
			if (a[l].gs > a[r].gs) {
				a[l].gs = sy;
				sum += a[r].gs;
				r--;
			} else if (a[l].gs < a[r].gs) {
				a[r].gs = sy;
				sum += a[l].gs;
				l++;
			} else {
				sum += a[l].gs;
				l++;
				r--;
			}
		} else {
			l++;
			r--;
		}
	}
	cout << sum;
	return 0;
}