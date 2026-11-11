#include <bits/stdc++.h>
using namespace std;
int n, m, nx = 0;
int a[200010];
int b[200010];

int c[200010] = {0};

void dfs(int u) {
	if (u == m) {
		int z = b[0];
//		cout << z << " ";

		for (int i = 1 ; i < u ; i++) {

			z &= b[i];
//			cout << z << " ";
		}

//		cout << "\n";
		nx = max(nx, z);
//		cout << nx << ")" << "\n";
		u = 0;
		return;
	}

	for (int i = 0 ; i < n ; i++) {

		if (c[i] == 0) {
			c[i] = 1;
			b[u] = a[i];
			dfs(u + 1);
			c[i] = 0;
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 0 ; i < n ; i++)

		cin >> a[i];

	if (n == m) {
		nx = a[0];

		for (int i = 1 ; i < n ; i++) {

			nx &a[i];
		}
	} else
		dfs(0);
	cout << nx;
	return 0;
}