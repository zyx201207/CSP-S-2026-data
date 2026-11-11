#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
char p[1000005];

long long s[1000005] = {0};

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long z = 0, ans = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> p[i];
		z += a[i];
		s[i] = s[i - 1] + a[i];
	}

	long long z2 = (z + 1) / 2;
	long long jl1, jl2;
	int b = 0;

	if (z2 < s[1]) {
		jl1 = 1;
		jl2 = z2;
		b = 1;
	}

	for (int i = n; i >= 1; i--) {

		if (z2 >= s[i]) {
			jl1 = i;
			jl2 = z2 - s[i];
			break;
		}
	}

	if (jl2 != 0) {
		if (z % 2 == 0) {
			for (int i = n; i >= jl1; i--) {

				a[i + 1] = a[i];
				p[i + 1] = p[i];
			}

			if (b == 0) {
				jl1 += 1;
			}

			a[jl1] = jl2;
			p[jl1] = p[jl1 + 1];
			a[jl1 + 1] -= jl2;
		} else {
			for (int i = n; i >= jl1; i--) {

				a[i + 1] = a[i];
				p[i + 1] = p[i];
			}

			if (b == 0) {
				jl1 += 1;
			}

			a[jl1] = jl2 - 1;
			p[jl1] = p[jl1 + 1];
			a[jl1 + 1] -= jl2;
		}
	}

	int l = jl1, r = jl1 + 1;

	while (l > 0) {
		if (p[l] != p[r]) {
			if (a[l] > a[r]) {
				ans += a[r];
				a[l] -= a[r];
				r += 1;
			} else if (a[r] > a[l]) {
				ans += a[l];
				a[r] -= a[l];
				l -= 1;
			} else {
				ans += a[l];
				r += 1;
				l -= 1;
			}
		} else {
			if (a[l] > a[r]) {
				a[l] -= a[r];
				r += 1;
			} else if (a[r] > a[l]) {
				a[r] -= a[l];
				l -= 1;
			} else {
				r += 1;
				l -= 1;
			}
		}
	}

	cout << ans;
	return 0;
}





































