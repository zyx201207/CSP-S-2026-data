#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5;
int n, m;
int a[MAXN + 7];
int sum = 0;
int HE = 0;
bool spA = true;
bool cmp(int x, int y) {
	return x > y;
}
int check(int x) {
	int sum = 0;
	int l = 0;
	for (int i = 1; i <= n; i++) {
		int e = x - a[i];
		if (e < 0) sum += 0;
		else sum += e, l++;//cout << e << ' ', 
		if (sum > m){//printf("\t%lld\n", l - 1); 
			HE = sum; return l - 1;}
	}
	HE = sum;
	//printf("\t%lld\n", l);
	return l;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	//cout << n << ' ' << m << '\n';
	int mn = LLONG_MAX;
	int mx = LLONG_MIN;
	for (int i = 1; i <= n; i++) {
		//cout << i << '\n';
		cin >> a[i];
		sum += a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
		if (a[i] != i)
			spA = false;
	}
	int l = mn, r = mx;
	sort(a + 1, a + n + 1, cmp);
//	for (int i = 1; i <= n; i++)
	//	cout << a[i] << ' ';
//	cout << '\n';
	int ans = check(mx);
	int lstHEE = HE;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		// cout << l << ' ' << r << ' ' << mid << '\n';
		int w = check(mid);
		if (w == ans) {
			if (HE > lstHEE)
				r = mid - 1;
			else l = mid + 1;
		}
		else if (w > ans) ans = w, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << '\n';

	return 0;
}
/*
 * for (int i = 1; i <= 5; i++) {
		int l, r, v;
		cin >> l >> r >> v;
		dif[l] += v;
		dif[r] -= v;
	}
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + dif[i];
		cout << pre[i] << ' ';
	}*/
/*	int l = mn, r = mx;
	while (l < r) {
		int mid = (r - l) / 2;
		cout << setw(5) << l << ' '<< setw(5) << r << ' ' << setw(5) << mid << '\n';
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << l << '\n';
*/
