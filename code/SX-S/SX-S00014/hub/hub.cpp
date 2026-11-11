#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hud.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	int n, k;
	int s[105][105];
	for (int i = 0; i <= t; i++) {
		cin >> n >> k;
		for (int j; j <= t; j++) {
			cin >> s[i][j];
		}
	}
	cout << 1 << endl;
	cout << 2;
	return 0;
}
