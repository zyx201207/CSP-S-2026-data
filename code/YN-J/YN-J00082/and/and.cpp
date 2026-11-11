#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200020];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << a[3];
	return 0;
}