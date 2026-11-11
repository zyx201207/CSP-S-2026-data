#include <bits/stdc++.h>
using namespace std;
#define int long long
#define get getchar
inline int read() {
    int x = 0, f = 1;
    char ch = get();
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -f;
        ch = get();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - 48);
        ch = get();
    }
    return x * f;
}
int n, m, a[500005], vis[300005], ans[300005], v[300005], cv[500005];
signed main() {
    freopen("card.in", "r", stdin);
   freopen("card.out", "w", stdout);
    n = read();
    m = read();
    bool f = 1;
    for(int i = 1; i <= n; i++) {
            a[i] = read();
            if(a[i] - a[i-1] > 1) f = 0;
    }
    if(f) {
        for(int i = 1; i <= n; i++) {
            if(a[i] != a[i+1]) {
                v[a[i]] = i;
            }
        }
        for(int i = 1; i <= m; i++) {
            cout << v[i] << " ";
        }
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        memset(cv, 0, sizeof(cv));
        memset(vis, 0, sizeof(vis));
        int len = 0;
        for(int j = i; j <= n; j++) {
            if(!vis[a[j]]) {
                len++;
               cv[len] = a[j];
                vis[a[j]] = 1;
            }
            else {
                while(true) {
                    if(cv[len] == a[j]) {
                        break;
                    }
                    vis[cv[len]]  = 0;
                len--;
                }
            }
        }
        for(int j = 1; j <= m; j++) {
            if(vis[j]) ans[j]++;
        }
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << " ";
}
