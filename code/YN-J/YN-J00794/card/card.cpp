#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int a[N];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cout << i << " ";
	}
	return 0;
}