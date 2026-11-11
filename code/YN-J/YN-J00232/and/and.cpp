#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1000005], num, ant;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	num = a[n] & a[n - 1];
	for (int i = 1; i < m - 1; i++) {
		num = num & a[n - i - 1];
	}
	cout << num;
}