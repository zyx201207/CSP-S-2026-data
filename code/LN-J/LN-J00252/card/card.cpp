#include <bits/stdc++.h>
using ll = long long;
constexpr int N = 5e5 + 5;
int a[N], stk[N];
bool st[N];
int ans[N];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m; std::cin >> n >> m;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    bool f = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < a[i - 1]) { f = 1; break; }
    }
    if (!f) {
        for (int i = 1; i <= n; i++) if (a[i] != a[i + 1]) ans[a[i]] = i;
        for (int i = 1; i <= m; i++) std::cout << ans[i] << " \n"[i == m];
        return 0;
    }
    std::vector < std::pair < int, int > > vec;
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1]) vec.push_back({a[i], 1});
        else vec[vec.size() - 1].second++;
    }
    for (int i = 0; i < vec.size(); i++) {
        int tp = 0;
        for (int j = i; j < vec.size(); j++) {
            if (!st[vec[j].first]) { stk[++tp] = vec[j].first; st[vec[j].first] = 1; }
            else {
                while (stk[tp] != vec[j].first) {
                    st[stk[tp]] = 0;
                    tp--;
                }
            }
        }
        for (int j = 1; j <= m; j++) { ans[j] += st[j] * vec[i].second; st[j] = 0; }
    }
    for (int i = 1; i <= m; i++) std::cout << ans[i] << " \n"[i == m];
}