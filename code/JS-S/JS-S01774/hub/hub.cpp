#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen ("hub.in", "r", stdin);
    freopen ("hub.out", "w", stdout);
    long long c, t;
    cin >> c >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        for (long long i = 1;i < n;i++)
        {
            long long u, v;
            cin >> u >> v;
        }
        cout << (k + 1) / 2 << endl;
    }
    return 0;
}
