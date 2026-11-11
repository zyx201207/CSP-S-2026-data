#include <bits/stdc++.h>
using namespace std;
int cnt[250000];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >>  m;
    for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
    for (int i = 1; i <= m; i++) {
        if (i == a[n]) cout <<10;
        else cout << cnt[i];
        cout << ' ';
    }
    return 0;
}
