#include <bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define ll long long
int const MAXN = 5e5 + 5;
ll n, a[MAXN], m, ans, pre[MAXN],;
bool check(int x) {
    ll sum = 1e18 + 1;
    for(int i = x; i<= n; i++)
        sum = min(sum, a[i] * x - (pre[i] - pre[i - x - 1]));
    if(sum <= m) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0),cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out", "w" ,stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n); 
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    int l = 0, r = n; 
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
