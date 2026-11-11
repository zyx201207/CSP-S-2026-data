#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n + 1);
    int q = a[n];
    if (x == 1)
    {
        cout << a[n];
    }
    for (int i = n; i >= 1 + x; i--)
    {
        q = q && a[i];
    }
    cout << q + 6;
    return 0;
}
