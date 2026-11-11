#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m;
int math[N];
int sc[N];
int cz[N];

void work(int l, int r) {
	int u = 0;
	map<int, int>mp;
	for (int i = l; i <= r; i++) {
		if (mp[math[i]] == 0) {
			u++;
			cz[u] = math[i];
			mp[math[i]] = u;
		} else {
			for (int s = mp[math[i]] + 1; s <= u; s++)
				mp[cz[s]] = 0;
			u = mp[math[i]];
		}
	}
	for (int i = 1; i <= u; i++)
		sc[cz[i]]++;
}

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> math[i];
	}
	for (int i = 1; i <= n; i++) {
		work(i, n);
	}

	for (int i = 1; i <= m; i++)
		cout << sc[i] << ' ';
	return 0;
}