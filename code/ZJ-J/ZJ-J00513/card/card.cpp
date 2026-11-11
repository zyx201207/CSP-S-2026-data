#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], ans[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		map<int, bool> mp;
		for(int j = i; j <=n; j++) {
			mp[a[j]] = true;
		}
		for(int j = 1; j <= m; j++) {
			ans[j]++;
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
