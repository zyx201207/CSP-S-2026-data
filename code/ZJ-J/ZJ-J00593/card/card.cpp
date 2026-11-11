#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
int a[500010];
int q[200010];
int ans[200010];


int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        int num = 0;
        for (int j = i; j <= n; ++j) {
            q[++num] = a[j];
            for (int k = 1; k < num; ++k) if (q[k] == a[j]) num = k;
        }
        for (int j = 1; j <= num; ++j) ++ans[q[j]];
    }

    for (int i = 1; i <= m; ++i) cout << ans[i] << " ";

    fclose(stdin);
    fclose(stdout);
    return 0;
}
