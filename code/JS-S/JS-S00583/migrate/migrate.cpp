#include <iostream>
#include <cstdlib>

typedef long long ll;
typedef unsigned long long ull;

constexpr int N = 2e6 + 5;

int c, t, n; ll d, x[N], ans = 0;

int cnt = 0;
void dfs(int now, int t, int min, int step) {
    if(now == t && step == min) { ++cnt; return ; }
    for(int j = now + 1; j <= t; ++j) {
        if(x[j] - x[now] <= d) dfs(j, t, min, step + 1);
        else break;
    }
}

inline void sol(int l, int r) {
    int min = 0;
    for(int i = l; i <= r; ++i) {
        for(int j = i + 1; j <= r; ++j) {
            // std::cerr << i << " " << j << " " << x[j] - x[i] << "\n";
            if(x[j] - x[i] > d) {
                // std::cerr << "p!";
                if(j == i + 1) return ;
                else {
                    i = j - 2; ++min;
                    break;
                }
            } else if(j == r){
                ++min, i = r;
            }
        }
    }
    // std::cerr << l << " " << r << " " << min << "\n";
    dfs(l, r, min, 0);
    // if(cnt == 2) std::cerr << l << " " << r << '\n';
    if(cnt == 2) ++ans;
}

inline void solve() {
    std::cin >> n >> d;
    for(int i = 1; i <= n; ++i) std::cin >> x[i];
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j < i; ++j) {
        sol(j, i); cnt = 0;
    }
    std::cout << ans << '\n'; ans = 0;
}

int main() {
    std::freopen("migrate.in", "r", stdin);
    std::freopen("migrate.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> c >> t;
    while(t--) solve();

    return 0;
}
