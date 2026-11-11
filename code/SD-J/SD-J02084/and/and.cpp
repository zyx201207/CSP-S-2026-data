#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long ans;
void dfs(long long mu,int ii,int im) {
	if (im == m) {
		ans = max(ans, mu);
		return ;
	}
	if (ii == n) return ;
	dfs((mu & a[ii]), ii + 1, im + 1);
	dfs(mu, ii + 1, im);
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i ++) cin >> a[i];
	for (int i = 0;i < n;i ++) {
		dfs(a[i],i + 1,1);
	}
	cout << ans << endl;
	return 0;
}
