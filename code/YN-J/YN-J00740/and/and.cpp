#include <bits/stdc++.h>
using namespace std;
//暴力出奇迹，骗分过样例
int a[200005], b[200005];

int main() {

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, p = 0, pp = 0, p1 = 0, p2 = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	cout << a[n - m + 1];//A

	return 0;
}
