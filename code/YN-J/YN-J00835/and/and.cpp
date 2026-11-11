#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int ans = 0;
	int ans1 = 0;

	for (int i = 0; i < n; i ++) {

		cin >> a[i];
		ans = max(ans, a[i]);
		ans1 &= a[i];
	}

	if (m == 1)
		cout << ans;

	if (m == n)
		cout << ans1;





	return 0;
}