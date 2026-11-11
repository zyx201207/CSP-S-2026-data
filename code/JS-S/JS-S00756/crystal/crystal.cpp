#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
const int N = 5e5 + 10;
int n, m;
int ans(0);
int a[N];
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, n){
        cin >> a[i];
    }
    int sum(0), l = 1, now(a[1]);
    sort(a + 1, a + n + 1);
    rep(i, n){
        sum += (a[i] - now) * (i - l);
        while(sum > m){
            sum -= a[i] - a[l];
            l++;
        }
        now = a[i];
        ans = max(ans, i - l + 1);
    }
    cout << ans;
    return 0;
}
