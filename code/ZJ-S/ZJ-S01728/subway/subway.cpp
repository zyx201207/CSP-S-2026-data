#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
using PII = pair <int,int>;
using LL = long long;
using ULL = unsigned long long;
template <typename T1,typename T2> void tomax (T1 &x,T2 y) {if (y > x) x = y;}
template <typename T1,typename T2> void tomin (T1 &x,T2 y) {if (y < x) x = y;}
const int N = 510,M = 500010;
int tid,n,m,d,q;
int w[M];
vector <PII> a[N],v[M];
LL f[N][N];
void mian () {
    cin >> tid >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++) cin >> w[i];
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        while (k--) {
            int x,t;
            cin >> x >> t;
            v[x].pb (make_pair (i,t));
            a[i].pb ({x,t});
        }
    }
    memset (f,0x3f,sizeof (f));
    for (int i = 1;i <= n;i++) f[i][i] = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j < a[i].size ();j++) {
            int x,t;
            tie (x,t) = a[i][j];
            for (int l = 0;l < v[x].size ();l++) tomin (f[i][v[x][l].x],t + v[x][l].y);
        }
    }
    for (int k = 1;k <= n;k++) {
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) tomin (f[i][j],f[i][k] + f[k][j]);
        }
    }
    while (q--) {
        int x,y;
        cin >> x >> y;
        LL ans = 1e18;
        for (int i = 0;i < v[x].size ();i++) {
            for (int j = 0;j < v[y].size ();j++) tomin (ans,v[x][i].y + f[v[x][i].x][v[y][j].x] + v[y][j].y);
        }
        cout << ans + w[x] + w[y] << endl;
    }
}
int main () {
    freopen ("subway.in","r",stdin);
    freopen ("subway.out","w",stdout);
    int T = 1;
    // cin >> T;
    while (T--) mian ();
    return 0;
}