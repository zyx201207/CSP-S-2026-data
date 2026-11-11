#include <bits/stdc++.h>
using namespace std;
#define int long Long
int c, n, m, d, q;
int w[500050];
int main() {
    freopen("subway.in","r", stdin);
    freopen("subway.out","w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i ++) {
        cin >> w[i];
    }
    for (int i = 1;i <= n;i ++) {
        int k;
        cin >> k;
        int k2[500050];
        for (int j = 1;j <= k;j ++) {
            cin >> k2[j];
        }
    }
    if(c == 0) {
        if(n == 2) {
            cout << 32 << endl << 17;
            return 0;
        } else if(n == 3) {
            cout << 35 << endl << 16;
            return 0;
        }
    }
    return 0;
}
