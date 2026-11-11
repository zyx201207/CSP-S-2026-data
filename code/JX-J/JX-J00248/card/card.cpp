#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[200005], v[200005], c[200005], ans[200005];
signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        v[a[i]] ++;
        if (v[a[i]] > 1) c[a[i]] = i;
    }
    for (int i = 1; i <= n; i ++){
        for (int j = i; j <= n; ){
            ans[a[j]] ++;
            if (c[a[j]]) j = c[a[j]] + 1;
            else j += 1;
        }
    }
    for (int i = 1; i <= m; i ++){
        cout << ans[i] << " ";
    }

    return 0;
}
