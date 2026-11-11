#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int w[20010];

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }

    int k;
    for (int j = 1; j <= n; j++)
    {
        cin >> k;
        cout << k * 2 * w[1] << endl;
    }

    return 0;
}
