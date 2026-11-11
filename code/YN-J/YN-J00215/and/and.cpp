#include <iostream>
#include <algorithm>
using namespace std;
int a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, greater<int>());
	int c = a[1];
	for (int i = 1; i <= m; i++) {
		c = a[i] & c;
	}
	cout << c;
	return 0;
}