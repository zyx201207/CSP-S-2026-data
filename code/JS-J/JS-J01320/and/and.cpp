#include <bits/stdc++.h>
using namespace std;
int n, m;
int mx = -1;
int a[200005];
bool st[200005];

void dfs(int t, int cnt, int ans) {
    if (t > n) return;
    if (cnt == m) {
//      cout << ans << '\n';
        mx = max(ans, mx);
        return;
    }

    if (ans == 0) {
        dfs(t + 1, cnt, 0);
        dfs(t + 1, cnt + 1, a[t]);
    } else {
        dfs(t + 1, cnt, ans);
        dfs(t + 1, cnt + 1, a[t] & ans);
    } 
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    
    cin >> n >> m;

    if (m == n) {
        int ans;
        cin >> ans;
        for (int i = 1; i < n; i++) {
            int t;
            cin >> t;
            ans &= t;
        }

        cout << ans << '\n';

        return 0;
    } else if (m == 1) {
        int mx = -1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mx = max(a[i], mx);
        }

        cout << mx << '\n';
        return 0;
    }
    

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dfs(1, 0, 0);

    cout << mx;
    return 0;
}

/*n                                                                       
g++ and.cpp -o and -Wall -O2 -g 
time ./and

*/
