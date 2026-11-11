#include <bits/stdc++.h>
using namespace std;

struct node {
	int wz, z;
};
stack<node> a;
int b[500005], n, m;
bool v[300005];
bool v2[300005];
int vis2[300005];
int vis[300005];
int ans[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = n; i > 0; i--) {

		if (!v[b[i]]) {
			a.push({i, b[i]});
			v[b[i]] = 1;
			v2[b[i]] = 1;
			vis2[b[i]] = i;
		} else {
			while (!a.empty() && vis2[b[i]] >= vis2[a.top().z]) {
				ans[a.top().z] += a.top().wz - i;
				a.pop();
			}
			a.push({i, b[i]});
		}
	}
	while (!a.empty()) {
		ans[a.top().z] += a.top().wz;
		a.pop();
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}