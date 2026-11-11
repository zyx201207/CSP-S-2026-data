#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXX = 5e5 + 5;

int n, m, a[MAXX], sum[MAXX], ans;

bool check(int l, int r){
    if(abs(a[r] * (r - l + 1) - (sum[r] - sum[l - 1])) <= m) return 1;
    return 0;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for(int i = 1; i <= n; i++){
        int l = 1, r = i, id = i;
        while(l <= r){
            int mid = (l + r) / 2;
            if(check(mid, i)) id = mid, r = mid - 1;
            else l = mid + 1;
        } ans = max(ans, i - id + 1);
        // cout << i << " " << id << '\n';
    } cout << ans << '\n';
    return 0;
}