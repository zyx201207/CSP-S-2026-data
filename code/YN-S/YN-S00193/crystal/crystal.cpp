#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
int n, m, a[N], b[N], maxx = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 2; i--) {
		b[i - 1] = a[i] - a[i - 1];
	}
	for (int i = n; i >= 2; i--) {
		int num = m, tot = 1, lst = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (num >= b[j] + lst) {
				num -= b[j] + lst;
				lst += b[j];
				tot++;
			} else {
				break;
			}
		}
		maxx = max(maxx, tot);
	}
	cout << maxx << '\n';

	return 0;
}
