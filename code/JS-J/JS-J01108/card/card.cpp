#include <bits/stdc++.h>
using namespace std;
int a[500005], cnt[300005];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int c[500005], sz = 0;
        for (int j = i; j <= n; j++) {
            bool flag = true;
            int fal;
            for (int k = 1; k <= sz; k++) {
                if (c[k] == a[j]) {
                    flag = false;
                    fal = k;
                    break;
                }
            }
            if (flag) {
                sz++;
                c[sz] = a[j];
            } else {
                sz -= (sz - fal);
            }
        }
        for (int i = 1; i <= sz; i++) {
            cnt[c[i]]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << " ";
    }
    return 0;
}
