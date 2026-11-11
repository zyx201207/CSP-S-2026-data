#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], ans[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int x = 1; x <= n; x++) {
		stack<int>q;
		map<int, bool>v;
		for (int i = x; i <= n; i++) {
			if (!v[a[i]])
				q.push(a[i]), v[a[i]] = 1;
			else {
				while (!q.empty()) {
					if (q.top() == a[i])
						break;
					else
						v[q.top()] = 0, q.pop();
				}
			}
		}
		while (!q.empty()) {
			int t = q.top();
			ans[t]++;
			q.pop();
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}