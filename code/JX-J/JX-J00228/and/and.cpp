#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
ll n, m, ans, a[MAXN], c[MAXN];
bool vis[MAXN];
ll cnt, sum;
void dfs(int x) {
    if(cnt == m) {
        ans = max(ans, sum);
        return;
    }
    for(int i = x; i <= n; i ++) {
        if(vis[a[i]] != true) {
            cnt ++;
            if(cnt == 1) sum = a[i];
            else sum = sum & a[i];
            vis[a[i]] = true;
            c[cnt] = sum;
            dfs(x + 1);
            cnt --;
            sum = c[cnt];
            vis[a[i]] = false;
        }
    }
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(vis, false, sizeof(vis));
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    dfs(1);
    cout << ans;
    return 0;
}
