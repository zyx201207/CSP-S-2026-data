#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= x - 1; i++)
    {
        cout << a[i] + n << " ";
    }
    cout << n;
    return 0;
}

