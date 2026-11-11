#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
    }
    for (int i = a[1]; i <= m + a[1] - 1; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
