#include <bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0), cin.tie(0)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define dep(i, a, b) for (int i = (a); i >= (b); i--)
#define il inline
using namespace std;
const int MAXN = 5e5 + 5, MAXM = 3e5 + 5;
int n, m, a[MAXN], cnt[MAXM], q[MAXN], pos;
bool vis[MAXM];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    IOS;
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) {
        pos = 0;
        rep(j, 1, m) vis[j] = 0;
        rep(j, i, n) {
            if (!vis[a[j]]) {
                q[++pos] = a[j];
                vis[a[j]] = 1;
            } else {
                int nxt = 0;
                dep(k, pos, 1) {
                    if (q[k] == a[j]) {
                        nxt = k;
                        break;
                    }
                    vis[q[k]] = 0;
                    q[k] = 0;
                }
                if (nxt > 0) pos = nxt;
                q[pos] = a[j];
            }
        }
        rep(j, 1, pos) {
            cnt[q[j]]++;
            q[j] = 0;
        }
    }
    rep(i, 1, m) cout << cnt[i] << " ";
    return 0;
}
