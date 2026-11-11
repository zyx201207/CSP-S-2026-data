#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll m, a[500005], maxn = 1ll, b[500005];

// 1 ~ 9
void solve1 (){
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i++){
        ll num = 0, k = m, cur = i;
        while(a[i] - a[cur] <= k && cur){
            k -= a[i] - a[cur];
            num++, cur--;
        }
        maxn = max(maxn, num);
    }
    cout << maxn;
}

// 10 ~ 20
void solve2 (){
    sort (a + 1, a + n + 1);
    for (int i = 1; i < n; i++) b[i] = a[i + 1] - a[i];
    for (int l = 1, r = 1; l <= n; l++){
        while (r <= n){
            if (m >= 1ll * b[r] * (r - l + 1)) m -= 1ll * b[r] * (r - l + 1), maxn = max(maxn, 0ll + r - l + 2);
            else break;
            r++;
        }
        m += a[r] - a[l];
    }
    cout << maxn;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n <= 5000) solve1();
    else solve2();
    return 0;
}
