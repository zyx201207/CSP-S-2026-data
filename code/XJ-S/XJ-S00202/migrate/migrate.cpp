#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005, T=2e5+5;
int c, t, n, d;
int x[N];
int f[N], g[N];
void solve() {
	int ans=0;
	cin >> n >> d;
	for(int i=1; i<=n; ++i) {
		cin >> x[i];
	}
	for(int s=1; s<=n; ++s) { //以s为起点 
		memset(f, 0x3f, sizeof(f)); f[s]=0; int tmp=f[s+1];
		for(int w=s+1; w<=n; ++w) g[w]=0; g[s]=1;
		for(int i=s+1; i<=n; ++i) {
			for(int j=i-1; j>=s; --j) {
				if(abs(x[i]-x[j])<=d) {
					f[i] = min(f[i], f[j]+1);
				} else break;
			}
		}
		for(int i=s+1; i<=n; ++i) {
			for(int j=i-1; j>=s; --j) {
				if(abs(x[i]-x[j])<=d) {
					if(f[i] == f[j]+1) {
						g[i] ++;
					}
				}
				else break;
			}
		}
		//s为u，e为v
		for(int e=s+1; e<=n; ++e) {
			if(g[e] == 2) {
//				cout << s << ' ' << e <<'\n';
				ans ++;
			}
		}
	}
	cout << ans << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t --) {
		solve();
	}
}
