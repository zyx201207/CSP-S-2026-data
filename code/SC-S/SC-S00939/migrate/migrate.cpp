#include <bits/stdc++.h>

using namespace std;

int c, t;
int main() {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	int time = 1;
	while (t--) {
		int n ,d;
		cin >> n >> d;
		int x[200005];
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		cout << time << endl;
		time++;
	}
	return 0;
}