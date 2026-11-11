#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500010];
bool check(long long x){
    long long minn = 1e18 + 10, s = 0;
    for(long long i = 1; i <= x; i++) s += a[i];
    for(long long i = x; i <= n; i++){
        minn = min(minn, (a[i] * x) - s);
        s -= a[i - x + 1];
        s += a[i + 1];
    }
    return minn <= m;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for(long long i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    long long l = 0, r = n, ans = 0;
    while(l <= r){
        long long mid = (l + r) / 2;
        if(check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans;

    return 0;
}
