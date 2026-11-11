#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int a[100001];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, greater<int>());
	int cnt = a[1];
	for (int i = 2; i <= m; i++) {
		cnt = cnt & a[i];
	}
	cout << cnt;
	return 0;
}