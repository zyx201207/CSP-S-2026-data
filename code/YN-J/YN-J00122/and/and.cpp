#include <bits/stdc++.h>
using namespace std;
int a[500005];
int sum;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= n - m; i--) {
		sum = sum and a[i];
	}
	cout << sum;
}