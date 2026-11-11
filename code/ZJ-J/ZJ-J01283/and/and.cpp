#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 5;
int n, m, ans;
int a[Maxn];
void dfs(int dep, int res, int k){
	if(k == m){
		ans = max(ans, res);
		return;
	}
	if(dep == n + 1){
		return;
	}
	int temp = (res == 0 ? a[dep] : res & a[dep]);
	dfs(dep + 1, temp, k + 1);
	dfs(dep + 1, res, k);
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n <= 20){
		dfs(1, 0, 0);
	}
	else if(n <= 2000){
		if(m == 1){
			for(int i = 1; i <= n; i++){
				ans = max(ans, a[i]);
			}
		}
		else if(m == n){
			ans = a[1];
			for(int i = 2; i <= n; i++){
				ans = ans & a[i];
			}
		}
		else if(m == 2){
			for(int i = 1; i <= n; i++){
				for(int j = i + 1; j <= n; j++){
					ans = max(ans, a[i] & a[j]);
				}
			}
		}
	}
	else{
		sort(a + 1, a + n + 1);
		ans = a[n - m + 1];
	}
	cout << ans << endl;
	return 0;
}

