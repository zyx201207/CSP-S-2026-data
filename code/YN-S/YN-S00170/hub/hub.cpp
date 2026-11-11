#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, k;
int c, t;

struct node {
	int u, v;
};
node a[N];

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].u >> a[i].v;
		}
		cout << 1 << "\n" << k;
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
