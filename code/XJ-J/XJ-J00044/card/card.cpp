#include <bits/stdc++.h>
using namespace std;
// #define int long long

int a[20][20];
int mp[20];

signed main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			mp[j] = a[i][j];
		}
		sort(mp + 1, mp + m + 1);
		for(int j = 1; j <= m; j++) {
			a[i][j] = mp[j];
		}
	}
	for(int j = 1; j <= m; j++) {
		for(int i = 1; i <= n; i++) {
			mp[i] = a[i][j];
		}
		sort(mp + 1, mp + n + 1);
		for(int i = 1; i <= n; i++) {
			a[i][j] = mp[i];
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}
