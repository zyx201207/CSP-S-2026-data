// CSP RP++
// luv wsj
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 2e6, INF = 0x3f3f3f3f;
int C, T, n;
ll d, x[N + 5];

template<typename T>
inline void chmin(T& a, const T b){ a = min(a, b); }
template<typename T>
inline void chmax(T& a, const T b){ a = max(a, b); }

namespace S10{
	int ds[N + 5], ans;
	ll dp[N + 5];
	
	inline void solve(){
		ans = 0;
		ll sm;
		for(int s = 1, l, r; s <= n; ++ s){
			ds[s] = 0;
			sm = dp[s] = 1;
			l = r = s;
//			cout << "proc " << s << '\n';
			for(int i = s + 1; i <= n; ++ i){
				while(x[i] - x[l] > d) sm -= dp[l ++];
				ds[i] = ds[l] + 1;
				if(l >= i){
					ds[i] = INF;
					break;
				}
				while(r < l || (r < i - 1 && ds[r + 1] < ds[i])) sm += dp[++ r];
				dp[i] = sm;
				if(dp[i] == 2) ++ ans;
//				cout << l << ' ' << r << endl;
			}
//			for(int i = s; i <= n; ++ i) cout << ds[i] << ' ';
//			cout << '\n';
//			for(int i = s; i <= n; ++ i) cout << dp[i] << ' ';
//			cout << '\n';
		}
//		cout << "ans: ";
		cout << ans << '\n';
	}
}

namespace S12{
	inline void solve(){
//		cout << "s12" << endl;
		const ll sd = x[2] - x[1];
		if(d < sd){
			cout << "0\n";
			return;
		}
//		cout << sd << endl;
		const ll meow = d / sd;
//		cout << meow << endl;
		if((meow << 1) - 1 >= n || meow == 1) cout << "0\n";
		else cout << n - (meow << 1) + 1 << '\n';
	}
}

//namespace S18{
//	int dp[N + 5];
//	
//	inline void solve(){
//		ll ans = 0;
//		for(int s = 1, l, r, ls; s <= n; ++ s){
//			dp[s] = 1;
//			dp[s - 1] = 0;
//			ls = s;
//			l = s + 1;
//			while(l <= n){
//				r = upper_bound(x + r, x + n + 1, x[ls] + d) - x - 1;
//				if(dp[ls] == 1){
//					if(dp[ls - 1] == 1){
//						int p = upper_bound(x + l, x + r + 1, x[ls - 1] + d) - x;
//						if(p > )
//					}
//				}
//				l = (ls = r) + 1;
//			}
//		}
//	}
//}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> C >> T;
	while(T --){
		cin >> n >> d;
		for(int i = 1; i <= n; ++ i) cin >> x[i];
		if(n == 1) cout << "0\n";
		else if(C <= 10) S10::solve();
		else if(C <= 12) S12::solve();
	}
}

