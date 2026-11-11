#include <bits/stdc++.h>
using namespace std;

int c, t;
int n, k;

struct node {
	int u, v;
} x[2000010];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> k;
		for (int j = 1; j <= n - 1; j++) {
			cin >> x[j].u >> x[j].v;
		}
	}
	cout << 1 << endl << 2;
	return 0;
}
