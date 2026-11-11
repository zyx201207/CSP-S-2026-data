// migrate

#include <bits/stdc++.h>
using namespace std;
#define int long long

bool mbegin;

const int N = 2e6 + 10, LOG = 25, INF = 0x3f3f3f3f3f3f3f3f;
struct T {
    int mn, cnt;
}gF[N], inf;
int gA[N], gL[N], gR[N], gFa[N][LOG], gDep[N], fgx[N], lyx[N];
vector<int> gVec[N];

T operator + (const T &x, const T &y) {
    if (x.mn < y.mn) return x;
    if (x.mn > y.mn) return y;
    return (T){x.mn, min(3LL, x.cnt + y.cnt)};
}

void Dfs(int x, int fa) {
    gFa[x][0] = fa;
    for (int i = 1; i < LOG; i++) gFa[x][i] = gFa[gFa[x][i - 1]][i - 1];
    for (auto to : gVec[x]) {
        if (to == fa) continue;
        Dfs(to, x);
    }
}

bool mend;

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    inf.mn = INF;
    inf.cnt = 1;

    int t;
    cin >> t >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;

        int lim = 1e18; gA[0] = -lim - 1, gA[n + 1] = lim + 1;
        for (int i = 1; i <= n; i++)
            cin >> gA[i];
        
        for (int i = 1; i <= n; i++) {
            int l = 0, r = i;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (gA[i] - gA[mid] <= d) r = mid - 1;
                else l = mid + 1;
            } gL[i] = l;

            l = i, r = n + 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (gA[mid] - gA[i] <= d) l = mid + 1;
                else r = mid - 1;
            } gR[i] = r;
        }
        
        for (int i = 1; i <= n; i++) {
            if (gR[i] == i) gR[i] = n + 1;
            gVec[gR[i]].push_back(i);
        }
        
        for (int i = 2; i <= n; i++)
            if (gA[gR[i]] - gA[i - 2] <= d) fgx[i] = 1;
        
        for (int i = 3; i <= n; i++)
            if (gA[gR[gR[i]]] - gA[gR[i] - 1] <= d) lyx[i] = 1;
        
        for (int i = 0; i <= n + 5; i++)
            for (int j = 0; j < LOG; j++)
                gFa[i][j] = n + 1;
        
        Dfs(n + 1, 0);

        int pre = 1, ans = 0;
        for (int p = 2; p <= n + 1; p++)
            if (gA[p] - gA[p - 1] > d || p == n + 1) {
                int L = pre, R = p - 1; pre = p;
                for (int i = L; i <= R; i++)
                    for (int j = i + 1; j <= R; j++) {
                        if (j - i <= 6) {
                            vector<int> route; int now = i;
                            while (1) {
                                route.push_back(min(now, j));
                                if (now >= j) break;
                                now = gR[now];
                            }

                            int len = route.size(), cnt = 0;
                            for (int k = len - 2; k >= 1; k--) {
                                int b = route[k], c = route[k + 1];
                                if (gA[c] - gA[b - 2] <= d) goto bad;
                            }

                            for (int k = len - 3; k >= 1; k--) {
                                int a = route[k], b = route[k + 1], c = route[k + 2];
                                if (gA[c] - gA[b - 1] <= d && gA[b - 1] - gA[a - 1] <= d) goto bad;
                            }

                            for (int k = len - 3; k >= 0; k--) {
                                int a = route[k], b = route[k + 1], c = route[k + 2];
                                if (gA[c] - gA[b - 1] <= d) cnt++;
                            }

                            if (cnt == 1) ans++;
                            bad: ;
                        }
                    }
                
                for (int j = L; j <= R; j++)
                    for (int i = L; i < j - 6; i++) {
                        vector<int> route; int now = i;
                        while (1) {
                            if (now >= j) break;
                            route.push_back(min(now, j));
                            now = gR[now];
                        }

                        int len = route.size(), cnt = 0, b = route[len - 2], c = route[len - 1];
                        if (gA[j] - gA[c - 2] <= d) goto bad2;
                        if (gA[j] - gA[c - 1] <= d && gA[c - 1] - gA[b - 1] <= d) goto bad2;
                        if (gA[j] - gA[c - 1] <= d) cnt++;

                        for (int k = len - 2; k >= 1; k--) {
                            int b = route[k], c = route[k + 1];
                            if (gA[c] - gA[b - 2] <= d) goto bad2;
                        }

                        for (int k = len - 3; k >= 1; k--) {
                            int a = route[k], b = route[k + 1], c = route[k + 2];
                            if (gA[c] - gA[b - 1] <= d && gA[b - 1] - gA[a - 1] <= d) goto bad2;
                        }

                        for (int k = len - 3; k >= 0; k--) {
                            int a = route[k], b = route[k + 1], c = route[k + 2];
                            if (gA[c] - gA[b - 1] <= d) cnt++;
                        }

                        if (cnt == 1) ans++;
                        bad2: ;
                    }
            }

        cout << ans << endl;
        for (int i = 0; i <= n + 5; i++) {
            gA[i] = gL[i] = gR[i] = fgx[i] = lyx[i] = 0, gVec[i].clear();
            for (int j = 0; j < LOG; j++) gFa[i][j] = 0;
        }
    }

    cerr << abs(&mend - &mbegin) / 1048576.0 << " " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    return 0;
}