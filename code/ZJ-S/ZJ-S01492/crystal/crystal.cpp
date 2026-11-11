#include<bits/stdc++.h>
#define int long long
#define rep(i, r) for(int i = 1; i <= r; i++)
#define Rep(i, l, r) for(int i = l; i <= r; i++)
#define lep(i, r) for(int i = r; i; i--)
#define Lep(i, l, r) for(int i = r; i >= l; i--)
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], sum[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    stable_sort(a + 1, a + n + 1); 
    int ans = 0, j = 1;
    rep(i, n) {
        sum[i] = sum[i - 1] + a[i];
        while(j < i && (i - j) * a[i] - sum[i - 1] + sum[j - 1] > m) j++;
        ans = max(ans, i - j + 1);
    }
    cout << ans;
    return 0;
}