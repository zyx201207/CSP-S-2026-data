#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}
int a[1000000];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	long long num = a[1];
	for (int i = 2; i <= m; i++) {
		num = num & a[i];
	}
	cout << num;
	return 0;
}