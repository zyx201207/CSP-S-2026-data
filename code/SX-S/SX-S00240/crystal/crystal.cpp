#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+10;
int n, m;
int ans;
int a[N];
int sum[N];
int l, r;

inline bool check(int x) {
	int res = 0;
	int need = m;
	int dec_r = 0, dec_l = 0;
	for (int i = n; i >= 1 ; i--) {
		if (a[i] > x) {
			dec_r += a[i] - x;
			continue;
		}
		if (a[i] == x) {
			res++;
		}
		if (a[i] < x) {
			dec_l += x - a[i];
			if (need >= x - a[i]) {
				need -= x - a[i];
				res++;
			}
		}
	}
	ans = max(ans, res);
	if (dec_r > dec_l) {
		return 0;
	} else
		return 1;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n;  i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	bool f = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] != ((i - 1) * (a[2] - a[1]) + a[1]))
			f = 1;
	}
	if (f == 0) {
		l = a[1] ;
		r = a[n] + m;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid))
				r = mid - 1;
			else
				l = mid + 1;
		}
		cout << ans;
	} else {
		for (int i = 1; i <= n; i++) {
			int need = m;
			int res = 0;
			for (int j = i - 1; j >= 1; j--) {
				if (need >= a[i] - a[j]) {
					need -= a[i] - a[j];
					res++;
				} else
					break;
			}
			ans = max(ans, res + 1);
		}
		cout << ans;
	}
	return 0;
}
//rp++
