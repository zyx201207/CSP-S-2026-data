#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 2;
int a[MAXN];

int main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cout << a[n] << ' ';
	return 0;
}