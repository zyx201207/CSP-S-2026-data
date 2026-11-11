#include <bits/stdc++.h>
using namespace std;

int n, m, a[500010], lst[500010], ans[500010], in[500010], q[500010], ft = 1, rr = 0;
vector <int> edges[500010];

int main () {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        lst[i] = n + 1;
    for (int i = n; i; i--)
        if (lst[a[i]] == n + 1)
            lst[a[i]] = i;
    if (1ll * n * m <= 100000000ll) {
        for (int i = 1; i <= n; i++) {
            int now = i;
            while (now <= n) {
                now = lst[a[now]];
                ans[a[now]]++, now++;
            }
        }
        for (int i = 1; i <= m; i++)
            cout << ans[i] << ' ';
        return 0;
    }
    for (int i = 1; i < n; i++)
        if (i != lst[a[i]])
            edges[i].push_back(lst[a[i]]), in[lst[a[i]]]++;
        else
            edges[i].push_back(i + 1), in[i + 1]++;
    for (int i = 1; i <= n; ans[i] = 1, i++)
        if (!in[i])
            q[++rr] = i;
    while (ft <= rr) {
        int x = q[ft++];
        for (auto y : edges[x]) {
            in[y]--;
            if (!in[y]) {
                q[++rr] = y;
                ans[y] += ans[x];
            }
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ans[lst[i]] << ' ';
    return 0;
}
