// SN-S00515 王铂涵 西安市铁一中
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
#define pq priority_queue
#define ull unsigned long long
#define ll long long
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define inf64 (1000000000000000000ll)
using namespace std;
const int N = 505, M = 5e5 + 5, MX = 0x3f3f3f3f3f3f3f3fll;

int c, n, m, d, q;
int w[M], k[N], st[M], ed[M];
vector<int> a[N], t[N];
vector<pii> sub[M]; int dis[N][N]/*第i个地铁线到第j个地铁线的时间*/;
void solve(){
	cin >> c >> n >> m >> d >> q; memset(dis, 0x3fll, sizeof(dis));
	rep(i, 1, m) cin >> w[i];
	rep(i, 1, n){ dis[i][i] = 0;
		cin >> k[i]; a[i].resize(k[i] + 1); t[i].resize(k[i] + 1);
		rep(j, 1, k[i]) cin >> a[i][j] >> t[i][j], sub[a[i][j]].pb({i, t[i][j]});
	}
	rep(x, 1, m) rep(i, 0, (int)sub[x].size() - 1) rep(j, i + 1, (int)sub[x].size() - 1){
		int u = sub[x][i].fir, v = sub[x][j].fir, tu = sub[x][i].sec, tv = sub[x][j].sec;
		dis[u][v] = min(dis[u][v], tu + tv); dis[v][u] = dis[u][v];
	}
	rep(j, 1, n) rep(i, 1, n) rep(k, 1, n) if(dis[i][j] < MX && dis[j][k] < MX && dis[i][j] + dis[j][k] < dis[i][k]) dis[i][k] = dis[i][j] + dis[j][k];
//	rep(i, 1, n) rep(j, 1, n) if(i ^ j) cout << i << " " << j <<":" << dis[i][j] << "\n"; 
	rep(i, 1, q){
		cin >> st[i] >> ed[i]; int res = inf64;
		for(pii a1 : sub[st[i]]) for(pii a2 : sub[ed[i]]){
			if(dis[a1.fir][a2.fir] == inf64) continue;
			res = min(res, a1.sec + a2.sec + dis[a1.fir][a2.fir]);
		} cout << res + w[st[i]] + w[ed[i]] << "\n";
	}
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T = 1;
//	cin >> T;
	while(T--) solve();
}

