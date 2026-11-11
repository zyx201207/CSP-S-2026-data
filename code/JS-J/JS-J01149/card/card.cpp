#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int a[N] = {};
int cnt[M] = {};
bool vis[M];
int last[M] = {};
int n, m;
signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(vis));
        int s = i;
        for (int j = i; j <= n; ++j) {
            if (vis[a[j]]) {
                s = last[a[j]] + 1;
                for (int k = 1; k <= s; ++k)
                    vis[a[k]] = 0;
            }
            vis[a[j]] = 1;
            last[a[j]] = j;
        }
        for (int j = s; j <= n; ++j) {
            cout << a[j] << " ";
            ++cnt[a[j]];
        }
        cout << endl;
    }
//    for (int i = 1; i <= m; ++i)
//        cout << cnt[i] << " ";
    for (int i = 1; i <= m; ++i)
        cout << i << " ";
    return 0;
}
/*
cards on the right out if repeated
*/