#include <bits/stdc++.h>
using namespace std;

#define NAME "subway"
//#define CASE
#define int long long
const int N = 5e5+5, mod = 1e9+7;

#define File(name) freopen(name".in", "r" ,stdin), freopen(name".out","w",stdout);
#define For(i,l,r) for (int i = l; i <= r; i++)
#define rFor(i,l,r) for (int i = r; i >= l; i--)
#define rg(c) c.begin(), c.end()
#define ms(c,v) memset(c, v, sizeof c)
#define l first
#define r second
#define endl '\n'
#define ll long long
#define pii pair<int,int>

int qpow(int a, int b, int m = mod) {
    if (b == 0) return 1;
    int v = qpow(a, b>>1, m);
    return (ll)v * v % m * ((b&1)?a:1) % m;
} 

void solve();

signed main() {
    //time_t beg = clock();
    File(NAME);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
#ifdef CASE
    cin >> t;
#endif
    while(t--) {
        solve();
    }
    //cerr << (clock()-beg) * 1.0 / CLOCKS_PER_SEC;
    return 0;
}

int n,m,q;

int d[505][505];

pii hav[N][21];
int cnt[N];

int t[N];

void solve() {
    int _; 
    cin >> _ >> n >> m >> _ >> q;
    For(i,1,m) cin >> t[i];
    For(i,1,n) {
        int k; cin >> k;
        For(j,1,k) {
            int a,t1; cin >> a >> t1;
            hav[a][++cnt[a]] = {i, t1};
        }
    } 
    ms(d,0x3f);
    For(i,1,n) d[i][i] = 0;
    For(i,1,m) {
        int nn = cnt[i];
        For(j,1,nn) {
            For(k,j+1,nn) {
                int f = hav[i][j].first, s = hav[i][k].first;
                d[s][f] = d[f][s] = min(d[f][s], hav[i][j].second + hav[i][k].second);
            }
        }
    }

    For(k,1,n) {
        For(i,1,n) {
            For(j,1,n) {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }

    while (q--) {
        int x,y; cin >> x >> y;
        int ans = 1e18;
        For(i, 1, cnt[x]) For(j, 1, cnt[y]) {
            pii a = hav[x][i], b = hav[y][j];
            ans = min(ans, d[a.first][b.first] + a.second + b.second);
        }
        cout << ans + t[x] + t[y] << endl;
    }
}