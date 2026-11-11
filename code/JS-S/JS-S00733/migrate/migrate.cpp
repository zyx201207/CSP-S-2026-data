#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 2e6 + 10;

LL n, d, x[N], dis[N], cnt[N];
map<int, int> mp;

void solveBF() {
    cin >> n >> d;
    for(int i = 0; i < n; i++) cin >> x[i];
    LL ans = 0;
    for(int i = 0; i < n; i++) {
        mp.clear();
        int t = i;
        mp[dis[i] = 0] = 1, cnt[i] = 1;
        for(int j = i + 1; j < n; j++) {
            while(t < j && x[j] - x[t] > d) {
                mp[dis[t]] -= cnt[t];
                if(!mp[dis[t]]) mp.erase(dis[t]);
                t++;
            }
            if(t == j) break;
            dis[j] = mp.begin()->first + 1, cnt[j] = mp.begin()->second;
            if(cnt[j] == 2) ans++;
            mp[dis[j]] += cnt[j];
        }
    }
    cout << ans << "\n";
}

void solveA() {
    cin >> n >> d;
    for(int i = 0; i < n; i++) cin >> x[i];
    if(n == 1) {
        cout << 0 << "\n";
        return;
    }
    LL w = x[2] - x[1];
    if(d < w * 2) {
        cout << 0 << "\n";
        return;
    }
    cout << max(0ll, n - (2 * (d / w) - 1)) << "\n";
}

void solveB() {
    cin >> n >> d;
    for(int i = 0; i < n; i++) cin >> x[i];
    LL ans = 0;
    for(int i = 0; i < n - 2; i++) {
        int t = upper_bound(x, x + n, x[i] + d) - x - 1;
        int l = upper_bound(x, x + n, x[t - 2] + d) - x - 1,
            r = upper_bound(x, x + n, x[t - 1] + d) - x - 1;
        ans += r - l;
    }
    cout << ans << "\n";
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    
    ios::sync_with_stdio(false), cin.tie(0);
    int C, T;
    cin >> C >> T;
    while(T--) {
        if(11 <= C && C <= 12) {
            solveA();
        } else if(13 <= C && C <= 14) {
            solveB();
        } else solveBF();
    }
    return 0;
}