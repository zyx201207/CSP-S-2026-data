#include <bits/stdc++.h>
using namespace std;
int x[2000002]={0};
vector<pair<int, int>> g;
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c, t;
    cin >> c >> t;
    while(t--)
    {
        int n, d;
        cin >> n >> d;
        for (int i=1; i<=n; i++)
        {
            cin >> x[i];
        }
        g.clear();

        for (int i=1; i<=n; i++)
        {
            for (int j=i+1; j<=n; j++)
            {
                if(x[j] - x[i] <= d)
                {
                    g.push_back({i, j});
                }
            }
        }

        int delta = x[2] - x[1];
        int ans = 0;
        int l = 1, r = 4;
        while(r <= n)
        {
            if(r - l > 2 && x[r] - x[l] >= 2*d && x[r] - x[l] < 3*d)
            {
                ans++;
                r++;
            }
            else
            {
                l++;
            }
        }
        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

