#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
int n, m;
int la[N], a[N], ans[N];
long long sum;
bool c[N];
bool b = 0;

void cl(int x) {
	if (x > n)
		return;

	if (c[a[x]] == 0) {
		c[a[x]] = 1, ans[a[x]]++;
	}

	cl(la[a[x]] + 1);
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		la[a[i]] = i;
	}

	for (int i = 1; i <= n; i++) {

		cl(i);
		memset(c, 0, sizeof(c));
	}

	for (int i = 1; i <= m; i++) {

		cout << ans[i] << " ";
	}

	return 0;
}
/*
4 3
 1 2 1 3*/
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/