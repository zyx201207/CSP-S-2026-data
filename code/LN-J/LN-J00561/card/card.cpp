#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int a[500005];
int ans[300005];
int vis[300005];
int b[500005];
int la[300005];

void solve1(int n, int m) {
    for (int i = n; i >= 1; i--) {
        ans[a[i]] = max(ans[a[i]], i);
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    return ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m; cin >> n >> m;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        la[a[i]] = i;
        if (a[i] < a[i - 1]) flag = 0;
    }
    if (flag) {
        solve1(n, m);
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j <= n) {
            ans[a[j]]++;
            j = la[a[j]] + 1;
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}
