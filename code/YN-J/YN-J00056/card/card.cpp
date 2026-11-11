#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5 + 10;
const int MAXM = 3e5 + 10;
int n, m;
int a[MAXN], nex[MAXM], ans[MAXM], tmp[MAXM];
unordered_set<int>c;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		tmp[a[i]] = max(tmp[a[i]], i);
	}
	for (int i = 1; i <= m; i++) {
		//	cout << tmp[i] << " ";
	}
	for (int i = 1; i <= n; i++) {
		nex[i] = tmp[a[i]];
		//cout << nex[i] << " ";
	}
	for (int k = 1; k <= n; k++) {
		for (int i = k; i <= n; i++) {
			ans[a[i]]++;
			i = nex[i];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}