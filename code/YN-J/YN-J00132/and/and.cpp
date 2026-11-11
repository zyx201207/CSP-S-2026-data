#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[N], n, m;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	int x = a[1];
	for (int i = 1; i <= m ; i ++) {
		x = x & a[i];
	}
	cout << x ;
	return 0;
}