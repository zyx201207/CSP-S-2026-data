#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int n, m, Q, a[N];

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        cin >> n >> m;
        for (int j = 1, x, y; j < n; j++)
            cin >> x >> y;
        int k = log2(n) - 1;
        cout << k << "\n";
    }
    return 0;
}
