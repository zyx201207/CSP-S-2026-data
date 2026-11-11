#include <bits/stdc++.h>
using namespace std;
#define int long long

bool f[200010];
int n, m, ans = -1;
int a[200010];

void dfs(int step, int sum){
    if (step > m){
        ans = max(ans, sum);
        return ;
    }
    for (int i = 1; i <= n; i++){
        if (f[i]) continue;
        f[i] = true;
        dfs(step + 1, sum & a[i]);
        f[i] = false;
    }
}

signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    int summ;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1) summ = a[i];
        else summ &= a[i];
    }
    if (m == n){
        cout << summ << "\n";
        return 0;
    }
    for (int i = 1; i <= n; i++){
        f[i] = true;
        dfs(2, a[i]);
        f[i] = false;
    }
    cout << ans << "\n";
    return 0;
}
