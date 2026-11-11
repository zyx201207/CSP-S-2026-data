#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i = (l); i <= (r); ++i)
#define per(i,l,r) for(int i = (l); i >= (r); --i)
#define pii pair<ll,ll>
#define ll long long
#define fr first
#define sc second
using namespace std;
const int N = 610, M = 5e5 + 10, inf = 0x3f3f3f3f, mod1 = 1e9+7, mod2 = 998244353;
const ll mod3 = 114514191981007219ll;
int c, n, m, d, q;
vector<pii> sta[M];
ll dis[N][N], w[M], k[N];
unordered_map<int,ll> cst[N];
void solve(){
    cin >> c >> n >> m >> d >> q;
    rep(i,1,m) cin >> w[i];
    rep(i,1,n){
        cin >> k[i];
        rep(j,1,k[i]){
            int s, t;
            cin >> s >> t;
            cst[i][s] = t;
            sta[s].push_back({i,t});
        }
    }
    rep(i,0,n) rep(j,0,n) dis[i][j] = 4557430888798830399ll;
    rep(i,1,n) dis[i][i] = 0;
    rep(K,1,m){
        int sz = sta[K].size();
        rep(i,0,sz-1) rep(j,i+1,sz-1)
            dis[sta[K][j].fr][sta[K][i].fr] = dis[sta[K][i].fr][sta[K][j].fr] = min(dis[sta[K][i].fr][sta[K][j].fr], sta[K][i].sc + sta[K][j].sc);
    }
    rep(k,1,n)
        rep(i,1,n)
            rep(j,1,n)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while(q--){
        ll minn = mod3;
        int x, y; cin >> x >> y;
        for(pii p1 : sta[x]) for(pii p2 : sta[y]){
            minn = min(minn, cst[p1.fr][x] + cst[p2.fr][y] + dis[p1.fr][p2.fr]);
        }
        cout << minn + w[x] + w[y] << '\n';
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while(T--) solve();
    return 0;
}