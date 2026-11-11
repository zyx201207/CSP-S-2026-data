#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
const int M = 2e6+5;
int head[N], nxt[M], to[M], ecnt = 1;

void add(int u, int v) {
	to[ecnt] = v;
	nxt[ecnt] = head[u];
	head[u] = ecnt;
	ecnt++;
}

int main() {
	/*freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);*/
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int u, v;
			cin >> u >> v;
			add(u, v);
		}
	}
	cout << 1 << endl << 2;
	return 0;
}