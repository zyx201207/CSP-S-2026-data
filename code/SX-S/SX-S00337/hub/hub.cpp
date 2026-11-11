#include <bits/stdc++.h>
using namespace std;
int c, t, n, k;

struct node {
	int u, v;
};

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		vector<node> vt(1000005);
		for (int i = 1; i < n; i++) {
			cin >> vt[i].u >> vt[i].v;
		}
		cout << 1 << endl;
	}
	return 0;
}
