#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[210000];
int q = 0;
int w = -1;
int k[210000];
int o = 0;



void dfs(int u, int o) {
	if (u == m) {
		q = max(q, w);
		return ;
	}

	for (int i = o; i < n; i ++) {

		int w1 = w;

		if (w == -1)
			w = a[i];
		else {
			w = w &  a[i];
		}

		dfs(u + 1, i + 1);
		w = w1;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 0; i < n; i ++) {

		cin >> a[i];

		if (n == m)
			q &= a[i];
	}


	if (n != m)
		dfs(0, 0);
	cout << q;

	return 0;
}