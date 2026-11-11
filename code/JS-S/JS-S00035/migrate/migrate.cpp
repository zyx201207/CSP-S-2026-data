#include <bits/stdc++.h>
using namespace std;

int x[5010], dis[5010], n, d;
queue <int> q;

int solve(int from, int to)
{
    int mn = 0;
    while (1)
    {
        for (int i = from + 1; i <= n; i++)
        {
            if (x[i] - x[from] > d)
            {
                if (i = from + 1) return false;
                else
                {
                    from = i - 1;
                    mn++;
                    break;
                }
            }
        }
    }
    return mn;
}

int main()
{
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    int c, T;
    cin >> c >> T;
    while (T--)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++) dis[i] = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        cout << solve(1, n - 1) << endl;
        /*for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (solve(i, j)) ans++;
            }
        }*/
    }
    return 0;
}
