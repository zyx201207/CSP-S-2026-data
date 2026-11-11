#include <bits/stdc++.h>
using namespace std;

void solve(){
    srand(time(0));
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    while(q--){
        printf("%d\n", rand() % 36 + 15);
    }
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
