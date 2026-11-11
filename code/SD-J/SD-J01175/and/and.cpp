#include<bits/stdc++.h>
using namespace std;
#define CLOSE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n, m, ans;
int a[200010];
void dfs(int i, int j, int goal) {
	if(j == m) {
		ans = max(ans, goal);
		//cout << ans << "\n" ;
		return;
	}
	if(i != n) {
		if(n - i > m) dfs(i + 1, j, goal);
		dfs(i + 1, j + 1, goal & a[i + 1]);
	}
}
int main() {
	CLOSE
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(m == n) {
		ans = a[1];
		for(int i = 2; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans ;
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		dfs(i, 1, a[i]);
	}
	cout << ans ;
}
