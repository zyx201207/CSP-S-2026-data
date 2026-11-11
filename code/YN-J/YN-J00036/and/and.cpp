#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int sum = a[n - 1], j = n - 2;
	for (int i = 0; i < m - 1; i++) {
		sum &= a[j];
		j--;
	}
	cout << sum;
	return 0;
}