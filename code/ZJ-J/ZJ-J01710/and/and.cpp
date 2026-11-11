#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m;
int a[N];
int maxa = -1, ans = -1;
void dfs(int pos ,int x, int sum) {
	if (x >= m) {
		ans = max(ans, sum);
		return ;
	}
	
	for (int i = pos + 1; i <= n; i++) {
		if (x == 0) dfs(i, x + 1, a[i]);
		else dfs(i, x + 1, sum&a[i]);
	}
} 
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxa = max(maxa, a[i]);
	}
	if (m == 1) {
		cout << maxa;
		return 0;
	}
	int maxans = -1;
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if(i != j) {
					maxans = max(maxans, a[i]&a[j]);
				}
			}
		}
		cout << maxans;
		return 0;
	}
	if (m == n) {
		ans = a[1];
		for (int i = 2; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}
