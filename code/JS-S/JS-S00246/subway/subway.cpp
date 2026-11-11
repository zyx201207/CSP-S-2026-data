#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int M = 510;
typedef long long ll;
typedef pair<ll,ll> PII;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;
//vector<vector<PII>> adj(N);

ll w[N];
struct GF{
    ll id, t;
};

vector<vector<GF>> tai(N);


ll dis[M][M];
void solve() {
    memset(dis, 0x3f, sizeof dis);
    ll n, m, d, q;
    cin >> n >> m >> d >> q;
    for(int i = 1; i <= n; i ++) dis[i][i] = 0;
    for(int i = 1; i <= m; i ++) {
        cin >> w[i];
    }

    for(int i = 1; i <= n; i ++) {
        int k; cin >> k;
        for(int j = 1; j <= k; j ++) {
            ll a, t;
            cin >> a >> t;
            GF gf;
            gf.id = i;
            gf.t = t;
            tai[a].push_back(gf);
        }
    }

    for(int i = 1; i <= m; i ++) {
        for(int j = 0; j < tai[i].size(); j ++) {
            for(int z = j + 1; z < tai[i].size(); z ++) {
                ll u = tai[i][j].id, v = tai[i][z].id, w = tai[i][j].t + tai[i][z].t;
                dis[u][v] = dis[v][u] = min(dis[u][v], w);
            }
        }
    }

    for(int k = 1; k <= n; k ++) {
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

   // for(int i = 1; i <= n ;i ++)  for(int j = 1; j <= n; j ++) cout << dis[i][j] << " \n"[j == n];


    while(q --) {
        int s, t;
        cin >> s >> t;
        ll ans = INFll;
        for(int i = 0; i < tai[s].size(); i ++) {
            for(int j = 0; j < tai[t].size(); j ++) {
                ll w = tai[s][i].t + tai[t][j].t;
                w += dis[tai[s][i].id][tai[t][j].id];
                ans = min(ans, w);
            }
        }
        ans += w[s] + w[t];
        cout << ans << endl;
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin >> c;
    int t = 1;
    while(t --) {
        solve();
    }
    return 0;
}
