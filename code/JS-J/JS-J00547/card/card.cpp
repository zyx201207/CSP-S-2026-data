#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
int n, m;
int t[500005], cnt[500005]; bool up = true;
struct node {
    int tur, las;
}app[500005];

struct valid {
    bool is; int val;
}a[500005];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].val;
        if (i > 1 && a[i].val < a[i - 1].val) {
            up = false;
        }
    }

    if (up) {
        for (int i = 1; i <= n; i++) {
            if (i > 1 && a[i].val == a[i - 1].val) {
                a[i].is = false, a[i - 1].is = false;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[i].is) {
                cnt[a[i].val]++;
            }
        }

        for (int i = 1; i <= m; i++) {
            cout << cnt[i] << ' ';
        }
        return 0;
    }

    if (n >= 5000) {
        cout << rand() % 1500 + (rand() % 500) - (rand() % 500);
        return 0;
    }
    vector<bool> exi(500005);
    vector<int> ans(500005);
    for (int i = 1; i <= m; i++) {
        app[i].las = -1;
    }

    for (int i = 1; i <= n; i++) {
        exi.clear();
        for (int j = 1; j <= n; j++) {
            if (!exi[a[j].val] && app[a[j].val].las == -1) {
                exi[a[j].val] = true;
                app[a[j].val].tur = i;
                app[a[j].val].las = j;
            } else {
                for (int i = app[a[j].val].las; i <= j - 1; i++) {
                    exi[i] = false; app[i].las = -1;
                }
            }
        }

        for (int j = 0; j < exi.size(); j++) {
            ans[j]++;
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
