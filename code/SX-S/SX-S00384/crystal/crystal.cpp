#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n, m;
int a[N];
int l;
int r;
int ans = INT_MIN, sum;

int check(int x) {
	int c = 0, d = 0;
	for (int i = n; i >= 1; i--) {
		if (a[i] <= x) {
			c += (x - a[i]);
			d++;
			if (c > m)
				return d - 1;
		}
	}
	return d;
}

int search(int l, int r) {
	if (l > r)
		return INT_MIN;
	int mid = (l + r) / 2, anss = INT_MIN;
	int t = check(mid);
	anss = max(anss, t);
	int li = search(l, mid - 1);
	int ri = search(mid + 1, r);
	anss = max(anss, max(li, ri));
	return anss;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	r = a[n];
	l = a[1];
	ans = search(l, r);
	cout << ans;
	return 0;
}