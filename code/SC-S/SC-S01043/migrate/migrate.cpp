#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;

int a[N], L[N], R[N], f[N], g[N];
int sl[N], sr[N], d[N];

inline int Abs(int x) {
    return (x < 0) ? (-x) : x;
}

void Add(int limit, int up, int v, int w) {
    int tl = sl[v], tr = sr[v];
    tl = max(tl, limit);
    up = min(up, tr);
    if(tl > up) return;
    // if(w) {
    //     cerr << limit << "\n";
    // }
    d[tl] += w, d[up + 1] -= w;
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);
    int cid; cin >> cid;
    int T; cin >> T;
    for(int qwq = 1; qwq <= T; qwq ++) {
        int n, D; cin >> n >> D;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++) sl[i] = N, sr[i] = 0;
        
        for(int i = 1, j = 1; i <= n; i++) {
            while(Abs(a[i] - a[j]) > D) j ++;
            L[i] = j;
            sl[L[i]] = min(sl[L[i]], i);
            sr[L[i]] = max(sr[L[i]], i);
            // cout << L[i] << " ";
        }
        // cout << "\n";
        for(int i = n, j = n; i >= 1; i--) {
            while(Abs(a[i] - a[j]) > D) j --;
            R[i] = j;
            // cout << i  << " " << R[i] << "\n";
        }
        // cout << "\n";
        f[1] = 1;
        for(int i = 1; i <= n; i++) {
            int j = R[i];
            int k = R[j];
            if(j == i || k == j) continue;
            if(i > 1) f[i] ++;
            // cerr << " " << i << "\n";
            Add(j + 1, k - 1, j - 1, f[i]);
            Add(j + 1, k - 1, j + 1, f[i]);
            Add(j + 1, k - 1,j, g[i]);
            if(Abs(L[k] - R[i]) == 0) {
                f[j] += f[i];
                g[j] += g[i];
            }
            if(Abs(L[k] - R[i]) == 1) {
                g[j] += f[i];
            }
        }
        int Ans = 0;
        for(int i = 1; i <= n; i++) {
            d[i] += d[i - 1];
            Ans += d[i] + g[i];
        }
        for(int i = 0; i <= n + 1; i++) d[i] = 0, f[i] = g[i] = 0;


        cout << Ans << "\n";
    }
    return 0;
}
// g++ std.cpp -o std --std=c++14 -Wall -W &&  ulimit -s &&./std
// 524288
// 131072