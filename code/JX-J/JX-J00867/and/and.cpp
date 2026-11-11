#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], flag = 1;
bool cmp(int x, int y){
    if(!x) return 0;
    if(!y) return 1;
    int t1 = __builtin_popcount(x), t2 = __builtin_popcount(y);
    if(t1 == t2) return x > y;
    return t1 > t2;
}
void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        if(flag && a[i] != i - 1) flag = 0;
    }
    if(!flag){
        sort(a + 1, a + n + 1, cmp);
        int ans = a[1];
        for(int i = 2;i <= m;++i) ans &= a[i];
        cout << ans;
    }else{
        int ans = n - 1;
        for(int i = n - 2;i >= n - m;--i) ans &= i;
        cout << ans;
    }
}

signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
