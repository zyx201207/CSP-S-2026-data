#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int n, m, cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int i = 1;
	while (m && i < n) {
		m -= i * (a[i - 1] - a[i]);
		cnt++;
		i++;
	}
	cout << cnt;
	return 0;
}