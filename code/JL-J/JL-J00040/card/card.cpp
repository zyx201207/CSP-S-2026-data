#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1, 0), b(n + 1, 0), c(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        b[i] = x, a[x]++;
    }

    a[b[0]] = 0;
    int t = n, x = -1;
    while (t--) {
        x++, a[b[x]]--;
        for (int i = n; i > x; i--) {
            if (a[b[i]] > 1) {
                for (int j = i; j <= n; j++) c[b[j]]++;
                break;
            } else {
                for (int j = x + 1; j <= n; j++) c[b[j]]++;
                break;
            }
        }
    }

    return 0;
}
