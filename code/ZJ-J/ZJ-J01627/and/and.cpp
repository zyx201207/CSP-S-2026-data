#include<bits/stdc++.h>
#define int long long
//#define endl '\n'
using namespace std;
#define rp(i, a) for(int i = 1; i <= a; i++)
#define rd(i, a) for(int i = 0; i < a; i++)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define per(i, a, b) for(int i = b; i >= a; i--)
#define vt vector
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 2e5 + 10;
int n, m, a[N], ans, flag = 30;
vt<int> g[31], t[31];
void init() {
	rd(i, 31) t[i].clear();
	return ;
}
void ban() {
	rd(i, 31) g[i] = t[i];
	return ;
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rp(i, n) {
		cin >> a[i];
		per(k, 0, 30) {
			if((a[i] >> k) & 1) t[k].pb(a[i]);
		}
	}
	 while(1) {
		ban();
		int pre = flag - 1;
		flag = -1;
		per(k, 0, pre) {
			if(g[k].size() >= 1ull * m) {
				flag = k;
				ans += (1 << k);
				break;
			}
		}
		if(flag == -1) break;
		init();
		for(auto to : g[flag]) {
			per(k, 0, flag) {
				if((to >> k) & 1) t[k].pb(to);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
/*

*/

