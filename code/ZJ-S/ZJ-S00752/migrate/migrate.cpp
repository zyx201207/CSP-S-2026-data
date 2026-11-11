#include <bits/stdc++.h>
#define fir first
#define sec second
using namespace std;

int s, T;
int n;
unsigned long long d;
long long x[2000005];
int main()
{
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    ios::sync_with_stdio (false);
    cin.tie (0), cout.tie (0);
    cin >> s >> T;
    while (T --)
    {
        cin >> n >> d;
        long long c;
        bool f = true;
        for (int i = 1; i <= n; i ++)
            cin >> x[i];
        if (n <= 3)
        {
            cout << 0 << '\n';
            continue;
        }
        c = x[2] - x[1];
        for (int i = 3; i <= n; i ++)
            if (x[i] - x[i - 1] != c)
                f = false;
        if (f)
        {
            int tmp = d / c;
            int ans = 0;
            for (int i = 1; i <= n; i ++)
                if (i + tmp + tmp - 1 <= n)
                    ans ++;
            cout << ans << '\n';
        }
        else
        {
            int ans = 0;
            for (int i = 1; i <= n; i ++)
            {
                long long maxn = -1;
                vector <pair <int, int> > ve;
                ve.push_back ({i, i});
                for (int j = i + 1; j <= n; j ++)
                {
                    maxn = max (maxn, x[j] - x[j - 1]);
                    if (maxn > d)
                        break;
                    if (x[j] - x[ve[ve.size() - 1].fir] <= d)
                        ve[ve.size() - 1].sec = j;
                    else
                        ve.push_back ({j - 1, j});
                    if (ve.size() == 2)
                    {
                        if (x[ve[1].sec] - x[ve[1].fir - 1] <= d && x[ve[1].sec] - x[ve[1].fir - 2] > d)
                            ans ++;
                    }
                    else if (ve.size() > 2)
                    {
                        if (x[ve[ve.size() - 1].sec] - x[ve[ve.size() - 1].fir - 1] <= d && x[ve[ve.size() - 1].sec] - x[ve[ve.size() - 1].fir - 2] > d &&
                            x[ve[ve.size() - 2].sec - 1] - x[ve[ve.size() - 2].fir - 1] > d)
                                ans ++;
                    }
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}