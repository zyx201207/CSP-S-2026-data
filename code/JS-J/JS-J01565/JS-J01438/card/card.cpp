#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int a[N];
int pos[N];
int cnt[N];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    unordered_map<int, int> vis;
    for (int k = 1; k <= n; k++) {
        for (int i = k; i <= n; i++) {
            if (pos[a[i]] > i) {
                if (vis[a[i]] == 0) {
                    vis[a[i]] = 1;
                    cnt[a[i]]++;
                }
                i = pos[a[i]];
            } else {
                if (vis[a[i]] == 0) {
                    vis[a[i]] = 1;
                    cnt[a[i]]++;
                }
            }
        }
        for (int i = k; i <= n; i++) {
            vis[a[i]] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << " ";
    }

    return 0;
}
