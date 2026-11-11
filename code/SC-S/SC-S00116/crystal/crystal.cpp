#include <bits/stdc++.h>
using namespace std;
int n;
long long m, a[500005], b[500005], c[500005], maxxai = 0;
int cnti = 0, ans = 0;
bool checkb() {
	int k = a[2] - a[1];
	for (int i = 3; i <= n; i++) {
		if (a[i] - a[i - 1] != k) return false;
	}
	return true;
}
int main() {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == i) cnti++;
	}
	sort(a + 1, a + 1 + n);
//b[i]表示a[1]到a[i]要加多少次 ——> a[r]变a[l] = b[l] - b[r]
	b[1] = 0;
	for (int i = 2; i <= n; i++) {
		b[i] = a[i] - a[i - 1] + b[i - 1];
	}
	if (checkb()) {
		maxxai = 0;
		long long cntm = 0;
		for (int i = 1; i <= n; i++) {
			c[a[i]]++;
			maxxai = max(maxxai, c[a[i]]);
		}
		ans =  maxxai;
		int k = a[2] - a[1];
		for (long long i = 1; i <= m; i++) {
			m -= i*k;
			cntm++;
		}
		ans += cntm;
		cout << ans;
		return 0;
	}
	if (m == 0) {
		cout << maxxai;
		return 0;
	}
	else {
		long long x = 0;
		for (int i = 1; i <= n; i++){
			int l = i, k = 1;
			while (x <= m && k <= l){
				x += b[k];
				k++;
			}
			ans = max(ans, k);
		}
		cout << ans;
		return 0;
	}
	
	cout << n;
	return 0;
}