#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e5 + 9;
ll a[N], sum[N];
int n, ans;
ll m;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int l = n;
    for(int r = n; r >= 1; r--){//(l, r]
        while(l > 0 && 1ll * (r - l + 1) * a[r] - (sum[r] - sum[l - 1]) <= m) l--;
        //cout << l << ' ' << r << '\n';
        ans = max(ans, r - l);
    }
    cout << ans;
    return 0;
}
