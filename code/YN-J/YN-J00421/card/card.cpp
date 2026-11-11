#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005];
map<int, int> mp;
set<int> s;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]]++;
		s.insert(a[i]);
	}
	for (auto i : s) {
		cout << mp[i] << " ";
	}
	return 0;
}