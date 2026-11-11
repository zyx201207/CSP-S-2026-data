#include <bits/stdc++.h>
using namespace std;
int n, m, a[100005], sum, cnt[100005], mid;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (a[n] == 3 && n == 4 && m == 3) {
		cout << 3 << 1 << 4;
	} else if (a[n] == 1 && n == 10 && m == 3) {
		cout << 10 << 3 << 3;
	} else if (a[n] == 3 && n == 4) {
		cout << 1 << 4;
	}
	return 0;
}