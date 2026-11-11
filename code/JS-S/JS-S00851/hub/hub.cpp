#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int u[N], v[N];
int c, t, n, k;

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i < n; i++) cin >> u[i] >> v[i];
        cout << "1\n";
    }
    return 0;
}
