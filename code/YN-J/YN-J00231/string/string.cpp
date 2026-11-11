#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 15;
int a[N];
char b[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	int i = 1, j = n;
	int ni = a[i], nj = a[j];
	char ci = b[i], cj = b[j];
	long long ans = 0;
	while (i < j) {
		if (ni == nj) {
			if (ci != cj) {
				ans += ni;
			}
			i += 1, j -= 1;
			ni = a[i], nj = a[j];
			ci = b[i], cj = b[j];
		} else if (ni > nj) {
			if (ci != cj) {
				ans += nj;
			}
			j -= 1;
			ni = ni - nj, nj = a[j];
			cj = b[j];
		} else if (ni < nj) {
			if (ci != cj) {
				ans += ni;
			}
			i += 1;
			nj = nj - ni, ni = a[i];
			ci = b[i];
		}
	}
	cout << ans;

	return 0;
}