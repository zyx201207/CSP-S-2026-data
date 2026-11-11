#include <bits/stdc++.h>
using namespace std;
int n, m;
queue <int>q;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	int a[n + 5], b[n + 5];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= m; i++) {
		cout << i << ' ';
	}

	return 0;
}