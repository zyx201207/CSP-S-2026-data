#include <bits/stdc++.h>
using namespace std;

int a[200005];
bool choose[200005];
int n, m;

int dfs(int m, int last)
{
    if (m == 0)
    {
        return last;
    }
    int mx = INT_MIN;
    for (int i = 1; i <= n; ++i)
        if (!choose[i])
        {
            choose[i] = true;
            int res = dfs(m - 1, last & a[i]);
            if (res > mx)
                mx = res;
            choose[i] = false;
        }
    return mx;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    cout << dfs(m, 0xFFFFFFFF);
    return 0;
}
