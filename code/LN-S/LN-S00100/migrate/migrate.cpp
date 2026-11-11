#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int c, n, m, d, q;
int w[N];
int a[10010][10010], t[10010][10010], k;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c;
    for (int i = 0; i < m; i ++) cin >> w[i];
    for (int i = 0; i < n; i ++) {
        cin >> k;
        for (int j = 0; j < k; j ++) cin >> a[i][j] >> t[i][j];
    }
    for (int i = 0; i < q; i ++) {
        int x, y;
        cin >> x >> y;
    }

    return 0;
}
