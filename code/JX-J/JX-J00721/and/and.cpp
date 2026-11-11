#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, m, a[N], ans = 0, mp[N];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int j = 29; j >= 0; j--) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!mp[i] && a[i] & (1 << j)) cnt++;
        }
        if (cnt >= m) {
            ans += (1 << j);
            for (int i = 1; i <= n; i++) {
                if (!(a[i] & (1 << j))) mp[i] = 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
