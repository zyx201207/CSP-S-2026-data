#include <bits/stdc++.h>
using namespace std;
int a[20050];

int main() {
	freopen("and .in", "r", stdin);
	freopen("and .out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << a[n];
	return 0;
}
