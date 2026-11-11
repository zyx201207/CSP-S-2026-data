#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int TaskId, T;
int n;
ll d;
ll a[2000010];
bool b[2000010];
ll dp[510][510];

int main (){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &TaskId, &T);
    while(T--) {
        scanf("%d%lld", &n, &d);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        int ans = 0;
        for (int l = 1; l <= n; l++) {
            int j = l;
            vector<int> idx;
            while(1) {
                if (j == n) break;
                int L = j, R = n + 1;
                while(L + 1 < R) {
                    int mid = (L + R) / 2;
                    if (a[mid] - a[j] <= d)
                        L = mid;
                    else
                        R = mid;
                }
                if (L == j) break;
                idx.push_back(L);
                j = L;
            }
            if (idx.empty()) continue;
            int Lim = idx.back();
            j = 0;
            int sz = (int)idx.size() + 1;
            for (int r = l; r <= Lim; r++) {
                for (int x = 0; x <= sz + 1; x++)
                    dp[r][x] = 0;
            }
            dp[l][0] = 1;
            int kkk = l;
            for (int r = l + 1; r <= Lim; r++) {
                while(j + 1 < (int)idx.size() && idx[j] < r) j++;
                while(a[r] - a[kkk] > d) kkk++;
                for (int c = 0; c <= sz + 1; c++) {
                    dp[r][c] = (dp[r][c] + dp[kkk][c - 1]);
                    if (kkk + 1 <= r) dp[r][c] = (dp[r][c] + dp[kkk + 1][c - 1]);
                    if (kkk + 2 <= r) dp[r][c] = (dp[r][c] + dp[kkk + 2][c - 1]);
                    dp[r][c] = min(dp[r][c], 5LL);
                }
                if (dp[r][j + 1] == 2) {
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
}
// 24 pts
