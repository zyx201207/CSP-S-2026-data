#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vecll = vector<ll>;

#define File
#define FileName "subway7"

#define rep(i, s, t) for(int i = s; i <= t; i++)
#define rrep(i, s, t) for(int i = t; i >= s; i--)

void solve();

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef File
    freopen(FileName ".in", "r" ,stdin);
    freopen(FileName ".out", "w", stdout);
#endif // File
    int T = 1;
    while(T--) solve();
    return 0;
}

int Case, n, m, d, q;
const int MAXN = 510;
const int MAXM = 5e5;
const int MAXQ = 1e5 + 10;

int w[MAXM];
int k[MAXN];
int a[MAXN][MAXN];
int t[MAXN][MAXN];
struct Query{
    int st, ed;
} qr[MAXQ];
//
vector<int> uni[MAXM];
ll dis[MAXN][MAXN];

void solve() {
    memset(dis, 0x3f, sizeof dis);
    cin >> Case >> n >> m >> d >> q;
    rep(i, 1, m) cin >> w[i];
    rep(i, 1, n) {
        cin >> k[i];
        rep(j, 1, k[i]) cin >> a[i][j] >> t[i][a[i][j]], uni[a[i][j]].emplace_back(i);
    }
    rep(i, 1, q) {
        cin >> qr[i].st >> qr[i].ed;
    }

    //
    // rep(i, 1, n) {
    //    cout << k[i]<<" ";
    //    rep(j, 1, k[i]) cout << a[i][j] <<" " << t[i][a[i][j]]<< " ";
    //    cout << "\n";
    //}
    //
    rep(i, 1, n) {
        dis[i][i] = 0;
        rep(j, 1, k[i]) {
            int jj = a[i][j];
            rep(j2, 0, uni[jj].size() - 1){
                int i2 = uni[jj][j2];
                if (i == i2) continue;
                // dis[i][i2] = dis[i2][i] = min(dis[i][i2], (ll)t[i][jj] + t[i2][jj]);
                if ((ll)t[i][jj] + t[i2][jj] < dis[i2][i]) {
                    dis[i][i2] = dis[i2][i] = (ll)t[i][jj] + t[i2][jj];
                    // cout << "upd: dis[" << i <<"][" << i2<<"] = over(" << jj <<") = " << t[i][jj] << " + " << t[i2][jj] << " = " << (ll)t[i][jj] + t[i2][jj] << '\n';
                }
            }
        }
    }

    //
    //rep(i,1 ,n) {
    //    rep(j, 1, n) {
    //        cout << dis[i][j] << " ";
    //    }
    //    cout << '\n';
    //}
    //cout << '\n';
    //

    rep(i, 1, n) rep(j, 1, n) rep(ki, 1, n)
        dis[i][j] = min(dis[i][j], dis[i][ki] + dis[ki][j]);

    //
    //rep(i,1 ,n) {
    //    rep(j, 1, n) {
    //        cout << dis[i][j] << " ";
    //    }
    //    cout << '\n';
    //}

    //

    //
    rep(qi, 1, q) {
        int st = qr[qi].st, ed = qr[qi].ed;
        ll base = w[st] + w[ed];
        ll res = 1e18;
        int i1 = -1, i2 = -2;
        rep(i, 0, uni[st].size() - 1) {
            rep(j, 0, uni[ed].size() - 1) {
                if (dis[uni[st][i]][uni[ed][j]] + t[uni[st][i]][st] + t[uni[ed][j]][ed] < res) {
                    res = dis[uni[st][i]][uni[ed][j]] + t[uni[st][i]][st] + t[uni[ed][j]][ed];
                    i1 = uni[st][i], i2 = uni[ed][i];
                }
            }
        }
        //
        //cout << base << " + " << res << " = ";
        //
        cout << base + res << "\n";
        //
        // cout << " (dis[" << i1 << "]["<< i2 << "])";
        //
    }


}
