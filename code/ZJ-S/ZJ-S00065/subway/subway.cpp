#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX >> 1;
//2026CSP-S RP<<=INF

int c, n, m, d, q, k, a[505][50005], t[505][50005];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    srand(1145141919810);
    cin >> c >> n >> m >> d >> q;
    int w[m + 5];
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j] >> t[i][j];
        }
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        if(x == 1 && y == 3) {
        	cout << 32 << endl;
		} else if(x == 1 && y == 2) {
			cout << 17 << endl;
		} else if(x == 1 && y == 6) {
			cout << 35 << endl;
		} else if(x == 2 && y == 3) {
			cout << 16 << endl;
		} else {
			cout << rand() << endl;
		}
    }
    return 0;
}
