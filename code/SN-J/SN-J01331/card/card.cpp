#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 5e5 + 10, M = 3e5 + 10;

int n, m, a[N], ans[M];
int main() {
	freopen("card.in", "r", stdin); freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int lst = 0;
		for (int j = i; j <= n; j++) {
			if (lst != a[j]) {
				ans[a[j]]++;
				lst = a[j];
			}
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}

