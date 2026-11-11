#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5;
int n, m, a[N];
bool check(int x){
    for(int i = 1; i + x - 1 <= n; ++i){
        int cnt = 0, k = a[i + x - 1];
        for(int j = i; j <= i + x - 1; ++j) cnt += k - a[j];
        if(cnt <= m) return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = n, ans = 1;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
