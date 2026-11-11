#include <iostream>
using namespace std;
const int N = 2e5 + 5;
int a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n ; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		a[i] += (a[i] and a[i + 1]);
		int ans = a[i];
		cout << max(a[i], ans);
	}
	return 0;
}