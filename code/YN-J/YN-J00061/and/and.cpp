#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define int long long
const int N = 2 * 1e5 + 10;
int n, m, a[N], maxx;

void DFS(int pos, int d, int sum) {
	if (sum == 0) {
		sum = a[pos];
	}
	if (d == m) {
		maxx = max(maxx, sum);
		return ;
	}
	for (int i = pos + 1; i <= n - m + 1; i++) {
		DFS(i, d++, sum & a[i]);
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	DFS(1, 0, 0);
	cout << maxx << '\n';
	return 0;
}