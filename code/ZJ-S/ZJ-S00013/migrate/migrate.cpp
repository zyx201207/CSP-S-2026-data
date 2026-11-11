#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 2000010;

int n;
LL d, x[N];
int to[N];
LL f[N][3];

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios_base::sync_with_stdio(false), cin.tie(0);

    int C, T; cin >> C >> T;
    for (int i = 1; i <= T; i ++ )
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i ++ ) cin >> x[i], f[i][0] = f[i][1] = f[i][2] = 0;

        LL res = 0;
        for (int i = n, j = n; i >= 1; i -- )
        {
            while (x[j] - x[i] > d) j -- ;
            to[i] = j;
            if (to[j] != j)
            {
                f[i][0] = to[j] - j;
                if (j > i + 1)
                {
                    f[i][0] -= to[j - 1] - j;
                    f[i][1] = to[j - 1] - j;
                    if (j > i + 2 && to[j - 2] >= j) f[i][1] -= to[j - 2] - j;
                }

                if (j == i + 1 || to[j - 1] < to[j]) f[i][0] += f[j][0], f[i][2] += f[j][2];
                if (f[j][1])
                {
                    if (j == i + 1 || to[j - 1] < to[j] - 1) f[i][2] += f[j][1];
                }
                if (j > i + 1)
                {
                    if (to[j - 1] >= to[j] && (j == i + 2 || to[j - 2] < to[j])) f[i][1] += f[j][0];
                }
            }
            res += f[i][1] + f[i][2];
        }
        cout << res << "\n";
    }

    return 0;
}
