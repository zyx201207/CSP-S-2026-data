#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 101;

int head[N], cnt;
struct node {
	int to;
	int nex;
};

void add(int x, int y) {
	e[++cnt] = (node) {y, head[x]};
	head[x] = cnt;
}

int c, t;

inline void work() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	if (c == 13 || c == 14) {
		if (n == k) {
			cout << 0 << endl;
			return ;
		}
		int m = n / 2;
		if (k >= m) {
			cout << 1 << endl;
			return ;
		}
		int flag = m / 2;
	}
}

int main() {
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) {
		work();
	}
	
	return 0;
}
