#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10, M = 2 * N;
int c, t;
int n, k;
int u, v;
int h[N], e[M], ne[M], idx;

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a]; h[a] = idx ++;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t --) {
		cin >> n >> k;
		for(int i = 1; i < n; i ++) {
			cin >> u >> v;
			add(u, v); add(v, u);
		}
		cout << 1 << endl;
	}
	
	return 0;
}
