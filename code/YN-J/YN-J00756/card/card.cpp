#include <bits/stdc++.h>
using namespace std;
int a[1000005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int cnt = 1;
	for (int i = 1; i <= n - 1; i++) {
		if (a[i] != a[i + 1]) {
			cnt++;
		}
	}
	for (int i = 1; i <= cnt; i++) {
		cout << 1 << "\n";
	}
	return 0;
}