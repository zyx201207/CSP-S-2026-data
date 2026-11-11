#include <iostream>
#include <algorithm>
using namespace std;

using LL = long long;

LL a[500005], pre[500005];
LL n, m;

bool check (int x) {
    LL ans = 1e18;
    for (int i = x; i <= n; i++){
        ans = min(ans, a[i] * x - (pre[i] - pre[i-x]));
    }
    return ans <= m;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i-1] + a[i];
    }
    int l = 0, r = n + 1;
    while (l + 1 < r){
        int mid = l + (r - l) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
    return 0;
}
