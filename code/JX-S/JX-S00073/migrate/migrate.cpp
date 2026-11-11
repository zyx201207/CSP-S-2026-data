#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e6 + 5;

int c, t;
ll n, d;
ll a[MAXN];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> c >> t;

    while (t--)
    {
        memset(a, 0, sizeof a);
        cin >> n >> d;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        if (a[2] - a[0] > d)
        {
            cout << "0" << "\n";
            continue;
        }
        cout << n - 3 << "\n";
    }

    return 0;
}
