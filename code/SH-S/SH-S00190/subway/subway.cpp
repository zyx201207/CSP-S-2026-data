#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500005], a, t, k, tts[505][500005];
bool stop[500005][505];

int div(int st, int ed, int alr, int banned[]) {
    int ans = 0x7f7f7f7f;
    for (int i = 1; i <= n; ++i) {
        if (stop[i][st] && !banned[i]) {
            if (stop[i][ed]) ans = alr + tts[ed][i] + tts[st][i];
            for (int j = 1; j <= m; ++j) {
                if (stop[i][j]) {
                    int x[505];
                    for (int l = 1; l <= m; ++l) x[l] = banned[l];
                    x[i] = true;
                    ans = min(ans, div(j, ed, alr + tts[st][i] + tts[j][i], x));
                }
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) {
        cin >> w[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            cin >> a >> t;
            tts[a][i] = t;
            stop[i][a] = true;
        }
    }

    for (int i = 1; i <= q; ++i) {
        cin >> a >> t;
        int tmp[505] = {};
        cout << div(a, t, w[a] + w[t], tmp) << "\n";
    }

    return 0;
}