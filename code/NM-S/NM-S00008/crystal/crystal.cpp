#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n, m, a[N], ans = -1;
ll getVal() {
    int res = -1;
    for (int i = 1; i <= n; i++) {
        int pos = a[i];
        int cnt = 0;
        for (int j = i; j <= n; j++) {
            if (pos == a[j]) {
                cnt++;
            }
        }
        res = max(res, cnt);
    }
    return res;
}
void print() {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    puts("");
}
void dfs(ll pos, ll cnt) {
    //if (a[1] == 4 && a[2] == 4 && a[3] == 4) cout << endl << cnt << endl;
    if (cnt > m + 1) {
        return ;
    }
    ans = max(ans, getVal());
    a[pos]++;
    dfs(pos, cnt + 1);
    dfs(pos + 1, cnt + 1);
    a[pos]--;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}
