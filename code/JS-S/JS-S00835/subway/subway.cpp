#include <bits/stdc++.h>
using namespace std;
const int M = 1e4 + 7;
int c, n, m, d, q;
int w[M], a[M][M], t[M][M];
int solve(int bg, int ed)
{
    int ans;
    //I don't know
    return ans;
}
int main()
{
    freopen("sybway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i ++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j ++)
        {
            cin >> a[i][j] >> t[i][j];
        }
    }
    while (q --)
    {
        int x, y;
        cin >> x >> y;
        cout << solve(x,y) << endl;
    }
    return 0;
}