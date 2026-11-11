#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005], ans = LLONG_MAX;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 0; i < m; i++)
        ans = ans & a[n-i];
    cout << ans;
    return 0;
}
