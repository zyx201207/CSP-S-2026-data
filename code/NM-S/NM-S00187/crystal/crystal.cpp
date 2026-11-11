// 17:24 4/4 100pts
// oh...
// luogu: [px_poxiao](https://www.luogu.com.cn/user/1847473)
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
int n, m, ans;
int a[500010], val[500010];
bool ck(int mid, int now){
    int res = val[now] - val[mid-1];
    res -= (now - mid + 1) * (a[n] - a[now]);
    if(res > m)
        return 0;
    return 1;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++)
        val[i] = a[n] - a[i];
    for(int i = 1; i <= n; i++)
        val[i] += val[i-1];

    for(int i = 1; i <= n; i++){
        int l = 1, r = i;
        while(l <= r){
            int mid = l + ((r - l) >> 1);
            if(ck(mid, i))
                r = mid - 1;
            else
                l = mid + 1;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans << endl;
}