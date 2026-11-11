#include <bits/stdc++.h>
using ll = long long;
constexpr int N = 2e5 + 5;
std::vector < int > vec[31];
int a[N];
bool find(std::vector < int > &v, int j)
{
    int l = 0, r = v.size();
    while (l <= r) {
        int mid = l + r >> 1;
        if (v[mid] == j) return 1;
        if (v[mid] < j) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m; std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        for (int j = 0; j <= 30; j++) {
            if (a[i] >> j & 1) vec[j].push_back(i);
        }
    }
    int st = 0;
    for (int i = 30; i >= 0; i--) {
        if (vec[i].size() >= m) {
            st = i;
            break;
        }
    }
    std::vector < int > v = vec[st];
    int ans = (1 << st);
    for (int i = st - 1; i >= 0; i--) {
        int cnt = 0;
        std::vector < int > nxt;
        if (vec[i].size() < m) continue;
        for (int j : vec[i]) {
            if (find(v, j)) {
                cnt++;
                nxt.push_back(j);
            }
        }
        if (cnt >= m) {
            ans |= (1 << i);
            v = nxt;
        }
    }
    std::cout << ans << std::endl;

}