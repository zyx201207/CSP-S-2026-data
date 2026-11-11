#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], ans;
signed main(){
    // freopen("ex_crystal/crystal4.in", "r", stdin);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1, j = 1, sum = 0; i <= n; i++){
        sum += a[i];
        while((i - j + 1) * a[i] - sum > m && j < i)
            sum -= a[j], j++;
        if((i - j + 1) * a[i] - sum <= m) ans = max(ans, i - j + 1);
        // cout << sum << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
/*
5 8
-3 -1 2 2 7
*/