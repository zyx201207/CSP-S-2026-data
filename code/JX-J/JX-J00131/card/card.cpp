#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005], cnt[500005], xiaochu[500005];
bool f[500005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] == a[j]) {
                xiaochu[i] = j;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        memset(f, 1, sizeof(f));
        for (int j = i; j <= n; j++) {
            if (xiaochu[j] != 0) {
                for (int k = j; k < xiaochu[j]; k++) {
                    f[k] = 0;
                }
                j = xiaochu[j];
            }
        }
        unordered_set<int> s;
        for (int j = i; j <= n; j++) {
            if (f[j] == 1) {
                s.insert(a[j]);
            }
        }
        for (int j : s) {
            cnt[j]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << " ";
    }
    return 0;
}
