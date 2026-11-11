#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define fore(x, v) for(const auto& x : (v))
#define trav(x, v) for(auto& x : (v))
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define bug(x) do{ cout << #x << ':' << x << '\n'; }while(0)

using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;

template<class T> inline bool chmax(T& a, T b) { if(a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if(a > b) { a = b; return 1; } return 0; }

const int N = 500 + 7, M = 5e5 + 7;
const ll inf = 1ll << 60;
//d <= 20 | q <= 1e5 | w[v] <= 1e9 | t[i][j] <= 1e9
int C, n, m, d, Q, len[N], outans[100007];
ll W[M], dis[1007];
vector<int> ti[N], a[N], inc[M];
vector<pii> G[1007], inr[1007];

void Kruskall(int st) {
	set<pii> s;
	s.clear();
	rep(i, 1, m) dis[i] = (i == st ? 0 : inf), s.insert({dis[i], i});
	while(!s.empty()) {
		int u = s.begin()->se; s.erase(s.begin());
		fore(eg, G[u]) {
			int v = eg.fi; ll w = eg.se;
			if(dis[u] + w < dis[v]) {
				s.erase({dis[v], v});
				dis[v] = dis[u] + w;
				s.insert({dis[v], v});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway4.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> C >> n >> m >> d >> Q;
	rep(i, 1, m) cin >> W[i];
	W[0] = 0;
	rep(i, 1, n) {
		cin >> len[i];
		ti[i].resize(len[i] + 1);
		a[i].resize(len[i] + 1);
		ti[i].pb(0), a[i].pb(0);
		rep(j, 1, len[i]) {
			cin >> a[i][j] >> ti[i][j];
			inc[a[i][j]].pb(i);
		}
//		a[i][0] = ti[i][0] = 0;
	}
//	st-...-ed : Eg1+Eg2+...+Egx+ w[st] + w[ed]	
	if(C <= 11) {
		rep(id, 1, n) {
			rep(i, 1, len[id])
				rep(j, i + 1, len[id]) {
					ll ww = ti[id][i] + ti[id][j];
					int u = a[id][i], v = a[id][j];
					G[u].pb({v, ww}), G[v].pb({u, ww});
				}	
		}
		rep(id, 1, Q) {
			int u, v;
			cin >> u >> v;
			inr[u].pb({v, id});
		}
		rep(i, 1, m) if(sz(inr[i])) {
			Kruskall(i);
			fore(j, inr[i])
				outans[j.se] = dis[j.fi] + W[i] + W[j.fi];
		}
		rep(i, 1, Q) cout << outans[i] << '\n';
	}
	
	return 0;
}

