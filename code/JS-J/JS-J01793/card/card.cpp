#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], cnt[N], vis[N];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (n--) {
        for (int i = 1; i <= n; i++) {
            cnt[a[i]]++;
            if (vis[a[i]]) {
                for (int j = 1; j < i; j++) {
                    if (a[j] == a[i]) {
                        for (int k = j; k < i; k++) {
                            cnt[a[k]]--;
                        }
                    }
                }
            }
            vis[a[i]] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << " ";
    }

    return 0;
}
