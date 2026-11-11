#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int c, n, m, d, q, w[N], sum[N], k;

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> k;
        for (int j = 1; j <= 2 * k; j++)
        {
            cin >> w[j];
            sum[i] += w[j];
        }
    }
    for (int i = 1; i <= q; i++)
    {
        cout << sum << "\n";
    }
    return 0;
}
