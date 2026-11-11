#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int x[N];
bool v[N];
int mx;
int n, m;

void dfs(int pos, int k) {
	if (pos == m) {
		int s = x[0];
		for (int i = 1; i < pos; i++) {
			s = (s & x[i]);
		}
		mx = max(mx, s);
		return ;
	}

	for (int i = k; i <= n; i++) {
		if (v[i] == 0) {
			v[i] = 1;
			x[pos] = a[i];
			dfs(pos + 1, i + 1);
			v[i] = 0;
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	mx = 0;
	dfs(0, 1);
	cout << mx;
	return 0;
}