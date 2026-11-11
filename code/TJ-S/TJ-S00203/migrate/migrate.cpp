#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e6 + 10;
LL c, t, n, d, p[N];
LL dp[N], ways[N];
int q[N], hh, tt;
map<LL, LL> tong;

int main(){
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> p[i];
		
		LL ans = 0;
		
		for (int u = 1; u <= n; ++u) {
			
			memset(dp, 0x3f, sizeof(dp));
			memset(ways, 0, sizeof(ways));
			tong.clear();
			hh = 0; tt = -1;
			
			dp[u] = 0;
			ways[u] = 1;
			tong[0]++; 
			q[++tt] = u;
			
			for (int i = u + 1; i <= n; ++i) {
				while (hh <= tt && p[i] - p[q[hh]] > d) {
					tong[dp[q[hh]]] -= ways[q[hh]];
					hh++;
				}
				
				if (hh <= tt) {
					LL minn = dp[q[hh]];
					dp[i] = minn + 1;
					ways[i] = tong[minn];
				}
				else ways[i] = 0;
				if (ways[i] == 2) {
					ans++;
				}
				
				while (hh <= tt && dp[q[tt]] > dp[i]) {
					tong[dp[q[tt]]] -= ways[q[tt]];
					tt--;
				}
				q[++tt] = i;
				tong[dp[i]] += ways[i];
			}
		}
		
		cout << ans << "\n";
	}
	return 0;
}
