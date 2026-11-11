#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 5e5 + 10;
int a[N];
int ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= m; i++) {
		a[i] += 1;
		for (int j = 1; j <= n; j++) {
			if (a[i] == a[j])
				ans++;
			break;
		}
	}
	cout << ans;
	return 0;
}
