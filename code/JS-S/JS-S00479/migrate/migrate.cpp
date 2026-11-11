#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
const int INF = 1e9;
int c, t, n, d, ans;
int a[maxn], cnt[maxn][maxn], mn[maxn][maxn], G[maxn][maxn];
bool b[maxn];
void init() {
    ans = 0;
    memset(a, 0, sizeof(a));
}
void dfs(int l, int r, int x, int y) {
    if(l == r) {
        int lst = x, sum = 0;
        for(int i = x + 1; i <= y; i++) {
            if(!b[i]) continue;
            if(G[lst][i] > d) return ;
            sum++;
        }
        if(mn[x][y] > sum) {
            cnt[x][y] = 1;
            mn[x][y] = sum;
        }
        if(mn[x][y] == sum) {
            cnt[x][y]++;
        }
        return ;
    }
    b[l] = true;
    dfs(l + 1, r, x, y);
    b[l] = false;
    dfs(l + 1, r, x, y);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("migrate1.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                G[i][j] = abs(a[i] - a[j]);
                mn[i][j] = INF;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                dfs(i + 1, j, i, j);
                ans += cnt[i][j];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
