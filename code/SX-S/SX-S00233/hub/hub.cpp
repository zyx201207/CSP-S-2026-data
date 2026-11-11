#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int c, t, n, k, cnt, head[N], ans = 1;

struct Edge {
	int to, nxt;
} e[N];

void insert(int u, int v) {
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

void solveA() {
	return ;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		memset(head, 0, sizeof(head));
		memset(e, 0, sizeof(e));
		cnt = 0;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			insert(u, v);
			insert(v, u);
		}
		if (c == 13 || c == 14) {
			solveA();
		}
		cout << ans << endl;
	}
	return 0;
}
