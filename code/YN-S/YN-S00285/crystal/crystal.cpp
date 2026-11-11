#include <bits/stdc++.h>
using namespace std;

long long a[5], m;
int n, ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	int d = abs(a[1] - a[0]);
	for (int i = 0; (i * (i + 1)*d) / 2 <= m; i++)
		ans++;
	cout << ans;
	return 0;
}