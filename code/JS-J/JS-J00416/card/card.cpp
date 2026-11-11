#include <bits/stdc++.h>
using namespace std;

long long n, m, a[10000010], b[1000010], c[1000010];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        memset(b, 0, sizeof(b));
        for (int j = i; j <= n; ++j) {
            if (b[a[j]] == 0) {
                b[a[j]]++;
            } else {
                memset(b, 0, sizeof(b));
                b[a[j]]++;
            }
        }
        for (int j = 1; j <= m; ++j) {
            if (b[j] != 0) {
                c[j]++;
            }
        }
    }
    for (int j = 1; j <= m; ++j) {
        cout << c[j] << ' ';
    }
    cout << endl;
    return 0;
}