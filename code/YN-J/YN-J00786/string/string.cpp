#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		cnt += a[i];
	}
	cnt /= 2;
	if (cnt % 2 == 1)
		cnt++;
	int l = 1, r = n, lasta = a[1], flag = 1, ans = 0;
	char lastc = c[1];
	while (l <= r) {
		if (flag == 1) {
			if (c[r] != lastc) {
				ans += min(a[r], lasta);
			}
			if (a[r] >= lasta) {
				flag = 0;
				l++;
				lasta = a[r] - lasta;
				lastc = c[r];
			} else {
				lasta -= a[r];
				r--;
			}

		} else {
			if (c[l] != lastc)
				ans += min(a[l], lasta);
			if (a[l] >= lasta) {
				flag = 1;
				r--;
				lasta = a[l] - lasta;
				lastc = c[l];
			} else {
				lasta -= a[r];
				l++;
			}

		}
	}
	cout << ans;
	return 0;
}