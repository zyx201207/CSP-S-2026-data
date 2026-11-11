#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], cnt[300005];
bool f[300005];
stack<int> s;
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (f[a[j]]) {
				while (true) {
					int u = s.top();
					f[u] = false;
					s.pop();
					if (u == a[j]) break;
				}
			}
			s.push(a[j]);
			f[a[j]] = true;
		}
		while (!s.empty()) {
//			cout << "Nice\n";
			cnt[s.top()]++;
			f[s.top()] = false;
			s.pop();
		}
	} 
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}