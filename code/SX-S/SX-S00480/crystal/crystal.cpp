#include <bits/stdc++.h>
using namespace std;//Aƭ
long long m, ans, a[500050], d;
int n;

//priority_queue<int vector<int> greater<int> > a;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int z = 1; z <= n; z++) {
		cin >> a[z];
	}
	sort(a + 1, a + n + 1);
	int d = a[2] - a[1];
	while (m >= 0) {
		ans++;
		m -= ans * d;
	}
	cout << ans;
	return 0;
}