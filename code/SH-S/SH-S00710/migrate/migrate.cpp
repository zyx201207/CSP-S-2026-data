#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N], n, d, cnt, ans;
void dfs(int s, int e, int step) {
	if(s == e) cnt++;
	if(step == 0) return ;
	for(int k = s+1; a[k] - a[s] <= d && k <= e; k++) {
		dfs(k, e, step-1);
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--) {
		ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) {
			for(int j = i+1; j <= n; j++) {
				for(int st = 1; st <= 10; st++) {
					cnt = 0;
					dfs(i, j, st);
					if(cnt == 1) break;
					if(cnt == 2) {
						ans++;
						break;
					}
				}	
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 
