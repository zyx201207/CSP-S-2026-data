#include <bits/stdc++.h>
typedef long long ll;
const int N = 5e5 + 5;
#define endl '\n'

using namespace std;

int n, m, a[N];

int main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= m; ++i) cout << i << ' ';
	return 0;
}
