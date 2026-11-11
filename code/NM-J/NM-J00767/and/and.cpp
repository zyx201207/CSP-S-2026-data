#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m = 2;
    cin >> n;
    int a[n]
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans += (i + 1) and i;
    }
    cout << ans;
    return 0;
}
