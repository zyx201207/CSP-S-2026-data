#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, T;
    if (!(cin >> c >> T)) return 0;
    while (T--) {
        int n;
        ll d;
        cin >> n >> d;
        vector<ll> x(n + 1);
        for (int i = 1; i <= n; ++i) cin >> x[i];

        vector<int> reach(n + 1), left(n + 1);
        int r = 1;
        for (int i = 1; i <= n; ++i) {
            if (r < i) r = i;
            while (r + 1 <= n && x[r + 1] - x[i] <= d) ++r;
            reach[i] = r;
        }
        int l = 1;
        for (int i = 1; i <= n; ++i) {
            while (x[i] - x[l] > d) ++l;
            left[i] = l;
        }

        long long ans = 0;
        vector<unsigned char> ways(n + 1);
        vector<int> pref(n + 1);

        for (int s = 1; s < n; ++s) {
            if (reach[s] == s) continue;
            fill(ways.begin() + s, ways.begin() + reach[s] + 1, 0);
            ways[s] = 1;
            int layerL = s, layerR = s;
            while (layerR < n) {
                int nextR = reach[layerR];
                if (nextR <= layerR) break;

                pref[layerL - 1] = 0;
                for (int i = layerL; i <= layerR; ++i)
                    pref[i] = pref[i - 1] + (int)ways[i];
                int total = pref[layerR];

                int nextL = layerR + 1;
                for (int v = nextL; v <= nextR; ++v) {
                    int p = max(layerL, left[v]);
                    int cnt = total - pref[p - 1];
                    ways[v] = (unsigned char)min(cnt, 3);
                    if (ways[v] == 2) ++ans;
                }

                layerL = nextL;
                layerR = nextR;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

