#include <bits/stdc++.h>
using namespace std;
const int N = 2000005;
int ds[N];
int n, d;
int dfs(int idx, int idy, int less)
{
    if (idx > idy) return 0;
    // cout << "dfs(" << idx << ", " << idy << ", " << less << ")" << endl;
    int cnt = 0;
    if (less == 0)
    {
        if (idx != idy) return 0;
        return 1;
    }
    if (less == -808464433)
    {
        while (idx < idy)
        {
            cnt ++ ;
            auto cc = lower_bound(ds + 1, ds + n + 1, ds[idx] + d);
            int nidx = *(cc - 1);
            idx = nidx;
        }
        less = cnt;
    }
    // cout << "less = " << less << endl;
    int ret = 0;
    for (int i = idx + 1; i <= n && i <= idy; ++ i )
    {
        if (ds[i] - ds[idx] <= d)
        {
            // cout << "oldi = " << idx << ", newi = " << i << endl;
            // cout << "ds[oldi] = " << ds[idx] << ", ds[newi] = " << ds[i] << endl;
            // cout << "ret = " << ret << endl;
            int tmp = dfs(i, idy, less - 1);
            // cout << "dfs(" << i << ", " << idy << ", " << less - 1 << ") = " << tmp << endl;
            ret += tmp;
        }
        else break;
    }
    return ret + 1;
}
void Solve()
{
    cin >> n >> d;
    for (int i = 1; i <= n; ++ i )
    {
        cin >> ds[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++ i )
    {
        for (int j = i + 1; j <= n; ++ j )
        {
            int tmp = dfs(i, j, 0xcfcfcfcf);
            // cout << "dfs(" << i << ", " << j << ") = " << tmp << endl;
            if (tmp == 2)
            {
                cnt ++ ;
            }
        }
    }
    printf("%d\n", cnt);
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int T;
    cin >> T >> T;

    while (T -- )
    {
        Solve();
    }
    return 0;
}
