#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;

int c, T, n, cnt[N];
ll minn;
ll d, a[N], ans, flag;

void dfs(int x, int y, int sum) {
	if(x == y) {
		flag = 1;
		if(sum > minn) return ;
		else if(sum == minn) cnt[minn] ++;
		else minn = sum, cnt[sum] ++;
		return ;
	}
	for(int i = x + 1; i <= y; i ++) {
		if(a[i] - a[x] <= d) dfs(i, y, sum + 1);
		else break;
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T --) {
		cin >> n >> d, ans = 0;
		for(int i = 1; i <= n; i ++) cin >> a[i];
		for(int i = 1; i <= n; i ++) {
			for(int j = i + 1; j <= n; j ++) {
				for(int k = 1; k <= n; k ++) cnt[k] = 0;
				minn = 3e18, flag = 0;
				dfs(i, j, 0);
				if(flag && cnt[minn] == 2) ans ++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

