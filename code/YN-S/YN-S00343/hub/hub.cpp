#include <bits/stdc++.h>
using namespace std;
int a[100005], t[1000005];

//AK!!!AK!!!AK!!!AK!!!AK!!!AK!!!AK!!!AK!!!AK!!!
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, T;
	cin >> c >> T;
	for (int i = 1; i <= T; i++) {
		int n, k;
		cin >> n >> k;
		for (int j = 1; j < n; j++) {
			cin >> a[j] >> t[j];
		}
		cout << k << "\n";
	}
	return 0;
}
