#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[500000];
int table[300000];
int exist[300001];
int ex[300001];
int lasti = -1;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        lasti  = -1;
        memset(ex, -1, sizeof(ex));
        for (int j = i; j < n; ++j) {
            if (ex[a[j]] != -1) {
                for (int k = ex[a[j]] + 1; k <= lasti; ++k) {  // clear
                    ex[table[k]] = -1;
                }
                lasti = ex[a[j]];
            } else {
                table[++lasti] = a[j];
                ex[a[j]] = lasti;
            }
        }
        for (int j = 0; j <= lasti; ++j) {
            ++exist[table[j]];
        }
    }

    for (int i = 1; i <= m; ++i) {
        cout << exist[i] << ' ';
    }

    return 0;
}
