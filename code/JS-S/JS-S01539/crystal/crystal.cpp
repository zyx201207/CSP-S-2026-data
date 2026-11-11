#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n, m, a[500005], ans;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (ll l = 1, r = 1, s = 0; l <= n; l++){
        while (r <= n && a[r] * (r - l) - s <= m){
            s += a[r];
            r++;
        }
        ans = max(ans, r - l);
        s -= a[l];
    }
    cout << ans;
    return 0;
}
