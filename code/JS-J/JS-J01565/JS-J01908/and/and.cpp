#include <bits/stdc++.h>
using namespace std;
long long a[200010];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    cout << a[m];
    return 0;
}
