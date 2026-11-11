#include <bits/stdc++.h>
using namespace std;
int a[500005], f[300005];
bool p[300005];
int n, m;
inline void dfs(int i) {
	stack<int> s;
	memset(p, 0, sizeof(p));
	for (int j = i; j <= n; j++) {
		if (p[a[j]]) {
			while (!s.empty() && s.top() != a[j]) {
				p[s.top()] = 0;
				s.pop();
			}
		} else {
			s.push(a[j]);
		}
		p[a[j]] = 1;
	}
	for (int j = 1; j <= m; j++) {
		if (p[j]) f[j]++;
	}
}
int main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		dfs(i);
	}
	for (int i = 1; i <= m; i++) {
		cout << f[i] << ' ';
	}
	return 0;
}