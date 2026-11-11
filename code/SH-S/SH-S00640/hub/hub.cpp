// hub

#include <bits/stdc++.h>
using namespace std;
#define int long long

bool mbegin;

const int N = 4e6 + 10;
int gDep[N], gDist[N], gSz[N], gDfn[N], gFan[N], gA[N], gB[N], dfn, n, K;
vector<int> gVec[N];
bool gVis[N];

void Dfs(int x, int bit) {
    gVis[x] = true;
    for (auto to : gVec[x]) {
        if (gVis[to] || !(bit & (1LL << to - 1))) continue;
        Dfs(to, bit);
    }
}

bool mend;

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t >> t;

    while (t--) {
        cin >> n >> K;

        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;

            gVec[a].push_back(b);
            gVec[b].push_back(a);
        }

        int mxn = (1LL << n), ans = 1e18;
        for (int i = 0; i < mxn; i++) {
            if (__builtin_popcountll(i) != K) continue;

            int cnt = 0;
            for (int j = 1; j <= n; j++)
                if (i & (1LL << j - 1) && !gVis[j]) Dfs(j, i), cnt++;
            
            if (cnt <= 2) {
                queue<int> que;
                for (int j = 1; j <= n; j++) gDist[j] = 1e18;
                for (int j = 1; j <= n; j++)
                    if (i & (1LL << j - 1)) que.push(j), gDist[j] = 0;
                
                while (!que.empty()) {
                    int u = que.front();
                    que.pop();

                    for (auto to : gVec[u])
                        if (gDist[to] == 1e18) {
                            gDist[to] = gDist[u] + 1;
                            que.push(to);
                        }
                }

                int mx = 0;
                for (int j = 1; j <= n; j++)
                    mx = max(mx, gDist[j]);
                
                ans = min(ans, mx);
            }
            
            for (int j = 0; j <= n + 5; j++)
                gVis[j] = false, gDist[i] = 0;
        }

        cout << ans << endl;
        for (int i = 0; i <= n + 5; i++)
            gVec[i].clear();
    }

    cerr << abs(&mend - &mbegin) / 1048576.0 << " " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    return 0;
}