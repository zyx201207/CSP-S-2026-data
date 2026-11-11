#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500010], pre[500010], ans = 0;
bool check(int x) {
    long long cnt = 1e18;
    for(int i = 1; i + x - 1 <= n; i ++) {
        cnt = min(cnt, a[i + x - 1] * x - (pre[i + x - 1] - pre[i - 1]));
    }return cnt <= m;
}int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n ; i ++){
        cin >> a[i];
    }sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i ++) pre[i] = pre[i - 1] + a[i];
    int l = 1, r = n;
    while(l <= r) {
        long long mid = l + (r - l) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }cout << ans;
    return 0;
}