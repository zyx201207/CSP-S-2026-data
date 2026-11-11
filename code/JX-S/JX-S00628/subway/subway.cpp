#include <bits/stdc++.h>
using namespace std;
int w[500005], a[505][500005], t[505][500005], x[100005], y[100005];
// w : station to hall  a: the i'st line through j station  t: in Aij station,station to another station's time
// x: the i'st start-station   y: the i'st flag of end-station

/*
   c n m d  q
   0 2 5 20 2
w  4 1 9 2 5
   3 1 5 2 7 4 6
   3 2 3 3 4 5 7
   1 3
   1 2
*/

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c, n, m, d, q;  // m station   n line
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }

    int k;
    cin >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j] >> t[i][j];
        }
    }

    for (int i = 1; i <= q; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 1; i <= q; i++) {
        cout << w[1] + t[i][i] + (t[i][i] + t[i][i]) + t[i][i] + w[i] << endl;
    }
    return 0;
}
