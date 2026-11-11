#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];

int main() {
	freopen("end.in", "r", stdin);
	freopen("end.out", "w", stdout);
	int n, m;
	int sum = 0, num = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum = a[i] & a[j];
		}
		num = max(sum, a[i]);
	}
	cout << num;
	return 0;
}