#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
const int maxm = 1e7 + 199;
int n, m, anss, ans[maxm], cnt;
int a[maxn];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int mmax = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		mmax = max(a[i], mmax);
	}
	anss = a[1];
	if (m == 1) {
		cout << mmax;
	} else if (m == n) {
		for (int i = 2; i <= n; i++) {
			anss &= a[i];
		}
		cout << anss;
	} else if (m == 2) {
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				cnt++;
				ans[cnt] = a[i] & a[j];
				anss = max(anss, ans[cnt]);
			}
		}
		cout << anss;
	} else if (m == 3) {
		for (int i = 1; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k <= n; k++) {
					cnt++;
					ans[cnt] = a[i] & a[j] & a[k];
					anss = max(0, ans[cnt]);
				}
			}
		}
		cout << anss;
	}

	return 0;
}