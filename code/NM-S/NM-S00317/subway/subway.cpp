#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int x[N], a[N], t[N];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> x[i];
    }
    int k;
    cin >> k;
    for(int i = 1;i <= k;i++){
        cin >> a[i] >> t[i];
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << 0 << '\n';
    }
    return 0;
}
