#include <bits\stdc++.h>
using namespace std;
int n, m;
int a[200010], v[200010], b[200010];
long long sum;
long long ans = 0;

void dfs(int x, int y) {
	b[y] = sum;
	if (y == m) {
		ans = max(ans, sum);
//		cout << ans << " " << sum << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (v[i] == 1)
			continue;
//		cout << a[i] << endl;
//		cout << sum << "&";

		sum &= a[i];
//		cout << a[i] << "=" << sum << endl;
		if (sum <= ans) {
			sum = b[y];
			continue;
		}
		v[i] = 1;
		y++;
		dfs(i, y);
		y--;
		v[i] = 0;
		sum = b[y];
//		cout << sum << " " << b[y] << " " << y << endl;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	memset(v, 0, sizeof v);
	cin >> n >> m ;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		sum = a[i];
		v[i] = 1;
		dfs(i, 1);
		v[i] = 0;
	}
	cout << ans;
	return 0;
}