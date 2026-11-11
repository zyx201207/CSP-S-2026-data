#include <bits/stdc++.h>
using namespace std;

long long a[10000010], n, m, ans, cnt = 1;

void dfs(int step, int cnt2, int cnt1) {
    if (cnt2 >= m) {
        ans = max(ans, cnt);
        return;
    }
    if (step > n) return;
    cnt = cnt & a[step];
    dfs(step + 1, cnt2 + 1, cnt);
    cnt = cnt1;
    dfs(step + 1, cnt2, cnt1);
    
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= 31; ++i) {
        cnt = cnt * 2 + 1;
    }
    dfs(1, 0, cnt);
    cout << ans << endl;
    return 0;
}