#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, a[N];
long long m;
long long sum[N];
int nobs[202];

void pian() {
	bool S = true, A = true, B = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (abs(a[i]) > 100) {
			S = false;
		} else if (a[i] != i) {
			A = false;
		} else if (i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
			B = false;
		}
	}
	if (S) {
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++) {
			nobs[a[i] + 100]++;
		}
		int maxx = 0;
		long long ms;
		for (int i = 200; i >= 1; i--) {
			ms = m;
			int maxs = 0;
			for (int j = i; j >= 1; j--) {
				if (ms - nobs[j] * (i - j) < 0) {
					maxs += ms / (i - j);
					break;
				} else {
					maxs += nobs[j];
					ms -= nobs[j] * (i - j);
				}
			}
			maxx = max(maxx, maxs);
		}
		cout << maxx;
	} else if (A) {
		int maxx = 1;
		int o = 0;
		while (m > 0 && maxx <= n) {
			o++;
			m -= o;
			maxx++;
		}
		if (m < 0) {
			cout << maxx - 1;
		} else {
			cout << maxx;
		}
	} else if (B) {
		int p = a[2] - a[1];
		int maxx = 1;
		long long o = 0;
		while (m > 0 && maxx <= n) {
			o += p;
			m -= o;
			maxx++;
		}
		if (m < 0) {
			cout << maxx - 1;
		} else {
			cout << maxx;
		}
	} else {
		int maxx = 0;
		sort(a + 1, a + 1 + n);
		for (int i = n; i <= 1; i--) {
			long long mx = m;
			int mo = 0;
			for (int j = i; j >= 1, mx >= 0; j--) {
				mo++;
				mx -= (a[i] - a[j]);
			}
			mo--;
			maxx = max(maxx, mo);
		}
		cout << maxx;
	}
	return ;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("cryctal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	if (n > 5000) {
		pian();
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		sum[i] = sum[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}
	int l = 1, r = 1, maxx = 0;
	while (r < n) {
		if (sum[r + 1] - sum[l] <= m) {
			r++;
		} else if (sum[r + 1] - sum[l + 1] <= m) {
			l++;
		} else {
			l++;
			r = l;
		}
		maxx = max(maxx, r - l + 1);
	}
	cout << maxx;
	return 0;
}