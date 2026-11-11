// CSP RP++
// luv wsj
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e6, M = N << 1, INF = 0x3f3f3f3f;
int C, T, n, k, hd[N + 5], to[M + 5], nx[M + 5], ce;

template<typename T>
inline void chmin(T& a, const T b){ a = min(a, b); }
template<typename T>
inline void chmax(T& a, const T b){ a = max(a, b); }

inline void ae(int u, int v){
	nx[++ ce] = hd[u];
	to[ce] = v;
	hd[u] = ce;
}

//namespace S14{
//	inline bool check(int s, int m){
//		int l1 = m + 1, r1 = s - m, l2 = s + m + 1, r2 = n - m;
//		return max(r1 - l1 + 1, 1) + max(r2 - l2 + 1, 1) <= k;
//	}
//	
//	inline void solve(){
//		int ans = INF;
//		for(int s = 1, l, r, m, res; s < n; ++ s){
//			l = 0, r = n - 2, res = n - 1;
//			while(l <= r){
//				m = l + r >> 1;
//				if(check(s, m)){
//					res = m;
//					r = m - 1;
//				}
//				else l = m + 1;
//			}
//			chmin(ans, res);
//		}
//		cout << ans << '\n';
//	}
//}

namespace S8{
	int bn, d[N + 5], mx[N + 5], sc[N + 5], fs[N + 5];
	
	void dfs1(int u, int f){
		mx[u] = sc[u] = 0;
		for(int x = hd[u]; ~x; x = nx[x]) if((x >> 1) != bn && x != (f ^ 1)){
			const int v = to[x];
			d[v] = d[u] + 1;
			dfs1(v, x);
			if(mx[v] + 1 > mx[u]){
				sc[u] = mx[u];
				mx[u] = mx[v] + 1;
			}
			else if(mx[v] + 1 > sc[u]) sc[u] = mx[v] + 1;
		}
	}
	
	void dfs2(int u, int f, int& tar){
		chmin(tar, max(fs[u], mx[u]));
//		cout << "u " << u << ' ' << mx[u] << ' ' << sc[u] << ' ' << fs[u] << endl;
		for(int x = hd[u]; ~x; x = nx[x]) if((x >> 1) != bn && x != (f ^ 1)){
			const int v = to[x];
			fs[v] = max(fs[u], mx[v] + 1 == mx[u] ? sc[u] : mx[u]) + 1;
			dfs2(v, x, tar);
		}
	}
	
	inline void solve(){
		int ans = INF;
		for(int x = 0; x < n - 1; ++ x){
			bn = x;
			int r1 = INF, r2 = INF;
			d[to[x << 1]] = d[to[x << 1 | 1]] = fs[to[x << 1]] = fs[to[x << 1 | 1]] = 0;
			dfs1(to[x << 1], -1);
			dfs2(to[x << 1], -1, r1);
			dfs1(to[x << 1 | 1], -1);
			dfs2(to[x << 1 | 1], -1, r2);
			chmin(ans, max(r1, r2));
//			cout << to[x << 1] << ' ' << to[x << 1 | 1] << ' ' << r1 << ' ' << r2 << endl;
		}
		cout << ans << '\n';
	}
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> C >> T;
	while(T --){
		cin >> n >> k;
		ce = -1;
		memset(hd, 0xff, sizeof(hd));
		for(int i = 1, u, v; i < n; ++ i){
			cin >> u >> v;
			ae(u, v);
			ae(v, u);
		}
		S8::solve();
	}
}

