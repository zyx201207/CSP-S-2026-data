#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m, a[500010];
ll ans[500010];
vector<pair<int, int>> res[300010];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    map<int, int> lst, cnt;
    for (int i = 1; i <= n; i++)
        lst[a[i]] = i, cnt[a[i]]++;
    vector<pair<int, int>> pos;
    for (auto zip : lst)
        pos.push_back({zip.second, zip.first});
    sort(pos.begin(), pos.end(), greater<pair<int, int>>());
    for (auto zip : pos) {
        res[zip.first] = res[lst[a[zip.first + 1]]];
        res[zip.first].push_back({zip.second, 1});
        for (auto x : res[zip.first])
            ans[x.first] += 1ll * x.second * cnt[zip.second];
    }
    for (int i = 1; i <= m; i++)
        printf("%lld ", ans[i]);
    return 0;
}
