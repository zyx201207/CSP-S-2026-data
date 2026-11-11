#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5E5 + 10, MAXM = 3E5 + 10;
int n, m, a[MAXN], cnt[MAXM], f[MAXM], tail;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        memset(f, -1, sizeof(f));
        tail = 0;
        for (int j = i; j < n; j++) {
            if (f[a[j]] != -1) {
                memset(f + a[j] + 1, -1, sizeof(f) - ((a[j] + 1) << 2));
                tail = f[a[j]] + 1;
            } else {
                f[a[j]] = tail++;
            }
        }
        for (int j = 1; j <= m; j++) {
            if (f[j] != -1 && f[j] < tail) {
                cnt[j]++;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << " ";
    }
    cout << endl;
    return 0;
}
