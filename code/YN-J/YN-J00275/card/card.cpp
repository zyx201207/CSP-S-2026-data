#include <bits/stdc++.h>
using namespace std;

const long long N = 5e5 + 10; 
long long n, m, a[N], vis[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] <= N)
			vis[a[i]]++;
	}
	for (int i = 1; i <= m; i++)
		cout << vis[i] << ' ';
	return 0;
}
