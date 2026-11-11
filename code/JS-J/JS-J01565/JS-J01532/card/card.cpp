#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m, a[500005], cnt[300005] = {};
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int y[300005] = {};
    for (int i = 1; i <= n; i++)
    {
        for (int j = y[i]; j <= n; j++)
        {
            if (a[i] == a[j])
            {
                y[i] = j;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = y[i]; j <= n; j++)
        {
            cnt[a[j]]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
