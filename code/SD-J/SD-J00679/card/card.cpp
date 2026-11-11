#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = 3e5 + 10;
int n, m;
int a[N];
int ans[M];
int zh[M]; 

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		zh[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		int x = i;
		while (x <= n) {
			ans[a[x]]++;
			x = zh[a[x]];
			x++;
		}
	}
	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << " ";
	}
	
	return 0;
}
