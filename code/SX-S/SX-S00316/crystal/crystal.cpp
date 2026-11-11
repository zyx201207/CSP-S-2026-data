#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define endl "\n"
using namespace std;
const int M = 5e5+10;
int n;
ll m, a[M], ans, sum, anss, m1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	fast;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i] > a[j]) {
				int b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
		}
	}
	for (int j = n; j >= 2; j--) {
		m1 = m;
		ans = 1;
		for (int i = j - 1; i >= 1; i--) {
			sum = a[j] - a[i];
			if (m1 - sum > 0) {
				ans++;
			} else if (m1 - sum == 0) {
				ans++;
				break;
			} else {
				break;
			}
		}
		anss = max(anss, ans);
	}
	cout << anss;
	return 0;
}
