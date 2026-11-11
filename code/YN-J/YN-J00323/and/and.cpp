#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2E5 + 10;
int n, m, a[MAXN], answer = 0;

void dfs(int i, int cnt, int s, bool f) {
    if (f && s < answer) {
        return;
    }
    if (i == n) {
        if (cnt == m) answer = max(answer, s);
        return;
    }
    if ((n - i + cnt < m) || cnt > m) {
        return;
    }
    dfs(i + 1, cnt + 1, f ? (s & a[i]) : a[i], true);
    dfs(i + 1, cnt, s, f);
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dfs(0, 0, 0, false);
    cout << answer << endl;
    return 0;
}
