#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, u, ans;
long long m, t, a[N], k[N];
long long f[N];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    bool v = 1;
    f[1] = a[2] - a[1];
    for (int i = 2; i < n; i++){
        f[i] = a[i + 1] - a[i];
        if(f[i] != f[i - 1]) v = 0;
    }
    if(v){
        u = 1;
        for (; u <= n; u++){
            if(f[1] * u * (u + 1) > 2 * m){
                break;
            }
        }
        cout << u;
        return 0;
    }
    for (int i = 1; i <= n; i++){
        t = m;
        u = i - 1;
        for (; u >= 1; u--){
            if(a[i] - a[u] > t)break;
            t -= a[i] - a[u];
        }
        ans = max(ans, i - u);
    }
    cout << ans;
    return 0;
}
