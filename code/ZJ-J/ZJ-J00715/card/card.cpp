#include <bits/stdc++.h>
using namespace std;

int a[300005];
int n, m;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    bool flag = true;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] <= a[i - 1]) flag = false;
    }
    if (flag)
        for (int i = 1; i <= m; ++i)
            cout << i << ' ';
    return 0;
}
