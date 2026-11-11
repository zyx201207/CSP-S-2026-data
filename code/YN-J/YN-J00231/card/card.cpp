#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 15;
const int M = 3e5 + 15;
int a[N], ans[M], id[M];
set<int>s, l;
map<int, int>mp;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (s.count(a[i]) == 0) {
			s.insert(a[i]);
			id[a[i]] = i;
		} else {
			l.insert(id[a[i]]);
			mp.insert({id[a[i]], i});
			id[a[i]] = i;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = k; i <= n;) {
			if (l.count(i) == 0) {
				ans[a[i]] += 1;
				i++;
			} else {
				i = mp[i];
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}