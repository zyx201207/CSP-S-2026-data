#include <bits/stdc++.h>
using namespace std;

//#define int long long
//struct node{
//};
int c, t, n, d, yyx = 0;
long long a[2000005];
long long f[2000005];
long long su[2000005];


void dfs1(int fa, int x) {
	f[fa] = 1;
	su[0] = 0;

	for (int i = 1; i <= n; i++) {

		dfs1(x + i, x);
		f[x + 1] = f[x] + a[i];
		su[x] += f[x + 1];

		if (f[x] == fa || x == fa) {
			return;
		}
	}
}

long long un(int x, int y) {
	long long ans = 0;

	if (su[x] == 0) {
		swap(x, y);
	}

	dfs1(0, 1);

	for (int i = 1; i <= n; i++) {

		if (f[x] == f[y]) {
			ans += su[x];
		} else {
			ans += su[y];
		}

		dfs1(x, y);
	}

	return ans;
}

void dfs(int x) {
	if (x > a[n]) {
		return ;
	}

	if (x == a[n]) {
		yyx++;
		return;
	}

	for (int i = 1; i <= d; i++) {

		dfs(x + i);
	}
}

main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;

	while (t--) {
		cin >> n >> d;

		for (int i = 1; i <= n; i++) {

			cin >> a[i];
		}

		dfs(a[1]);
		cout << yyx - 1 << endl;
	}


	return 0;
}