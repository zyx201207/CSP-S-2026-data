#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], pre[N];

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    int ans = 0, l = 1;
    for(int r = 1; r <= n; r++){
        while(l < r && a[r] * (r - l + 1) - (pre[r] - pre[l - 1]) > m){
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
    return 0;
}


/*
双指针
不是样例怎么这么小。

高二了，学了一年了。
再不拿S1就成滚木了。
*/