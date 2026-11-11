#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define sc if(DEBUG) cerr
const bool DEBUG = false;

const int N = 2e6 + 5, inf = 1 << 30;

int n;
ll x[N], d;

namespace BF {
    pair<int, ll> dis[505][505];

    ll solve() {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j) {
                if(llabs(x[i] - x[j]) <= d) dis[i][j] = {1, 1};
                else dis[i][j] = {inf, 0};
            }
        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j) {
                    if(dis[i][k].first == inf || dis[k][j].second == inf) continue;
                    if(dis[i][k].first + dis[k][j].first < dis[i][j].first) {
                        dis[i][j].first = dis[i][k].first + dis[k][j].first;
                        dis[i][j].second = dis[i][k].second * dis[k][j].second;
                    } else if(dis[i][k].first + dis[k][j].first == dis[i][j].first)
                        dis[i][j].second++;
                }

        ll res = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = i + 1; j <= n; ++j)
                if(dis[i][j].second == 2)
                    res++;

        return res;
    }
}

namespace A {
    bool check() {
        for(int i = 3; i <= n; ++i)
            if(x[i] - x[i - 1] != x[i - 1] - x[i - 2])
                return false;
        return true;
    }

    ll solve() {
        ll D = x[2] - x[1];
        if(2 * D > d) return 0;

        ll diff = (d / D) * 2 - 1;
        return max((ll)n - diff, 0ll);
    }
}

void solve() {
    cin >> n >> d;
    for(int i = 1; i <= n; ++i) cin >> x[i];

    if(n <= 500) cout << BF::solve() << "\n";
    else if(A::check()) cout << A::solve() << "\n";
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);

    int c, T; cin >> c >> T;
    while(T--) solve();

    return 0;
}
