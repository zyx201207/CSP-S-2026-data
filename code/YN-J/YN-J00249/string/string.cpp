#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
char c[N];
int n;
long long ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	for (int i = 1; i <= n; i++) {
		int k = n;
		for (int j = a[i]; j >= 1; j -= a[k], k--) {
			if (k == 0)
				break;
			if (c[i] != c[k] && j >= a[k])
				ans += a[k];
			else if (c[i] != c[k]) {
				ans += j, a[k] -= j;
				break;
			} else if (c[i] == c[k] && j < a[k]) {
				a[k] -= j;
				break;
			}
		}
		n = k;
	}
	cout << ans << endl;
	return 0;
}