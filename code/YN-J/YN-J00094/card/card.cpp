#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, b[N], tot[N], f[N], last[N];
queue<int> q[N];

void solve(int p) {
	if (p > n)
		return;

	if (!f[b[p]]) {
		tot[b[p]]++;
		f[b[p]] = 1;
	}

	solve(last[b[p]] + 1);
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> b[i];
		last[b[i]] = i;
	}

	for (int i = 1; i <= n; i++) {

		memset(f, 0, sizeof(f));
		solve(i);
	}

	for (int i = 1; i <= m; i++)

		cout << tot[i] << " ";
	return 0;
}
