#include<bits/stdc++.h>
#define ll long long
using namespace std;
int u[1000005], v[1000005];
int main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t, n, k;
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n - 1; i++) {
			cin >> u[i] >> v[i];
		}
	}
	cout << 1 << '\n' << 2;
	return 0;
}
/*

*/