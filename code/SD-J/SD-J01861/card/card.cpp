#include <iostream>
#include <cstdio>
using namespace std;

int a[500010], lst[500010], cnt[500010];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        lst[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j <= n) {
            cnt[a[j]]++;
            if (lst[a[j]] && lst[a[j]] != j) {
                j = lst[a[j]] + 1;
            }
            else {
                j++;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << ' ';
    }
    return 0;
}
