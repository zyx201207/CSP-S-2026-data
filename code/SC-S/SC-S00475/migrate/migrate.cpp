#include <bits/stdc++.h>
using namespace std;
long long n,d;
long long x[5000];
map<long long, int> ans;
long long cnt;
void dfs(long long l, long long r, long long changdu) {
	if (l == r) {
		cnt = min(changdu, cnt);
		ans[changdu]++;
	}
	for (int i = l + 1; i <= r && x[i] - x[l] <= d; i++) {
		dfs(i,r, changdu + 1);
	}
	
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c,t ;
	cin >> c >> t;
	while(t--) {
		memset(x, 0, sizeof(x));
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		int ans2 = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				map<long long, int> s;
				ans = s;
				
				cnt = 2000000000000000000;
				dfs(i, j, 0);
				if (cnt == 2000000000000000000) {
					continue;
				}
				if (ans[cnt] == 2) {
					ans2++;
				}
			}
		}
		cout << ans2<< endl;
		
	}
	return 0;
}