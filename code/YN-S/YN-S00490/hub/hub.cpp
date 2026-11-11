#include <bits/stdc++.h>
using namespace std;
int c, t, n, k;
int w[1000][1000];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> w[i][j];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}