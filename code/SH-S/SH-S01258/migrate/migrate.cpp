#include <iostream>
#include <fstream>
using namespace std;

#define FILE_IO "migrate"

#ifdef FILE_IO
ifstream fin(FILE_IO ".in");
ofstream fout(FILE_IO ".out");
#define cin fin
#define cout fout
#endif

#define int long long

const int N = 2e6 + 5;
const int INF = 1e15;

int n, d;
int a[N];

namespace bf {
    const int N = 5005;
    int dis[N][N];
    int cnt[N][N];
    inline void solve() {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = INF;
                cnt[i][j] = 0;
            }
            dis[i][i] = 0;
            cnt[i][i] = 1;
        }
        int l = 1;
        for (int i = 1; i <= n; i++) {
            while (a[i] - a[l] > d && l < i) {
                l++;
            }
            for (int j = 1; j < i; j++) {
                for (int k = l; k < i; k++) {
                    if (dis[j][k] + 1 > dis[j][i]) continue;
                    if (dis[j][k] + 1 == dis[j][i]) cnt[j][i] += cnt[j][k];
                    else {
                        dis[j][i] = dis[j][k] + 1;
                        cnt[j][i] = cnt[j][k];
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (cnt[j][i] == 2) ans++;
            }
        }
        cout << ans << "\n";
    }
}

namespace c3 {
    const int N = 5005;
    int dis[N][N];
    int pdi[N][N];
    int pcn[N][N];
    int nxt[N][N];
    int ad[N][N];
    int cnt[N][N];
    inline void solve() {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = INF;
                cnt[i][j] = 0;
                nxt[i][j] = 0;
                ad[i][j] = 0;
                pcn[i][j] = 0;
                pdi[i][j] = 0;
            }
            dis[i][i] = 0;
            cnt[i][i] = 1;
        }
        int l = 1;
        for (int i = 1; i <= n; i++) {
            while (a[i] - a[l] > d && l < i) {
                l++;
                // for (int j = 1; j <= l; j++) {
                //     pcn[j][l] += ad[j][l];
                //     ad[j][l + 1] += ad[j][l];
                // }
            }
            for (int j = 1; j < i; j++) {
                if (l == i) continue;
                dis[j][i] = pdi[j][l] + 1;
                cnt[j][i] = pcn[j][l];
                for (int k = l; k < i; k++) {
                    if (pdi[j][k] == dis[j][i]) pcn[j][k] += cnt[j][i];
                    // if (pdi[j][k] > dis[j][i]) cout << "ERROR!";
                }
                // if (!nxt[j][l]) nxt[j][l] = i;
                // ad[j][nxt[j][l]] += cnt[j][i];
                // for (int k = l; k < i; k++) {
                //     if (dis[j][k] + 1 > dis[j][i]) continue;
                //     if (dis[j][k] + 1 == dis[j][i]) cnt[j][i] += cnt[j][k];
                //     else {
                //         dis[j][i] = dis[j][k] + 1;
                //         cnt[j][i] = cnt[j][k];
                //     }
                // }
            }
            for (int j = 1; j <= i; j++) {
                pdi[j][i] = dis[j][i];
                pcn[j][i] = cnt[j][i];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << pcn[i][j] << " ";
            }
            cout << "\n";
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (cnt[j][i] == 2) ans++;
            }
        }
        cout << ans << "\n";
    }
}

signed main() {
    int c, t; cin >> c >> t;
    while (t--) {
        if (true) {
            bf::solve();
        }
        // c3::solve();
    }
}
