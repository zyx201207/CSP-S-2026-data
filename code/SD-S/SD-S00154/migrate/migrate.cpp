#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int itn;
typedef  __int128 i128;
int test = 1;
const int N = 5e3 + 5;
int c , n , d;
int x[N];
ll dp[N][N] , cnt[N][N];
inline void solve() {
	scanf("%d%d" , &n , &d);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d" , x + i);
		for (int j = i + 1 ; j <= n ; j++) dp[i][j] = -1 , cnt[i][j] = 0;
	}
	ll ans = 0;
	for (int i = 1 ; i <= n ; i++) {
		queue < int > q , p;
		q.push(i);
		p.push(0);
		while (q.size()) {
			int u = q.front();
			int dis = p.front();
			q.pop();
			p.pop();
			for (int j = u + 1 ; j <= n ; j++) {
				if (x[u] + d >= x[j] && (dp[i][j] == -1)) {
					dp[i][j] = dis + 1;
					q.push(j);
					p.push(dis + 1);
				}
				if (dis + 1 == dp[i][j]) cnt[i][j]++;
			}
		}
		for (int j = i + 1 ; j <= n ; j++)
			if (cnt[i][j] == 2)
				ans++;
	}
	printf("%lld\n" , ans);
}

signed main() {
	
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	scanf("%d" , &c);
	scanf("%d" , &test);
	while (test--)
		solve();
	
	return 0;
}
