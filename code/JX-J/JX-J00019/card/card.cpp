#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 5;
const int MAXM = 3e5 + 5;

int n, m;
int a[MAXN]

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= m; ++i)
    {
        ll ans = 0;
        for (int j = 1;j <= n; ++j)
        {
            if (a[j] == i)
            {
                ans = j;
            }
        }
    }

    return 0;
}
