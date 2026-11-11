#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[500010];
long long ans[300010];
int sum[500010];

void add (int x, int y) {
    int len = n - y + 1;
    int k = 0;
    for (int i = 1; i <= len; i++) {
        if (sum[i] == 0) {
            k = i;
            break;
        }
        if (sum[i] == x) {
            for (int j = i + 1; j <= len; j++) {
                sum[j] = 0;
            }
            return;
        }
    }
    sum[k] = x;
}

int main () {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        fill(sum, sum + n + 1, 0);
        for (int j = i; j <= n; j++) {
            add(a[j], i);
        }
        for (int j = 1; j <= n - i + 1; j++) {
            if (sum[j] == 0) {
                break;
            }
            ans[sum[j]]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
