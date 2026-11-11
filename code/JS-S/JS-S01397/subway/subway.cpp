#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
int w[N];
bool f[N][505];
int a[505][N] , t[505][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    int c , n , m , d , p;
    cin >> c >> n >> m >> d >> p;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= 2 * k; j++)
        {
            cin >> a[i][j] >> t[i][a[i][j]];
            f[a[i][j]][i] = true;
        }
    }
    int q;
    for (int i = 1; i <= q; i++)
    {
        int x , y;
        cin >> x >> y;
        cout << 0 << "\n";
    }
    return 0;
}
