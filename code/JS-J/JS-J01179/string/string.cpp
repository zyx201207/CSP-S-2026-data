#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int a[200010];
char c[200010];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    long long L = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> c[i], L += 1ll * a[i];
    int x = 1, y = n;
    long long i = 1, j = L, ans = 0;
    while (i <= j && x < y)
    {
        int delta = min(a[x], a[y]);
        if (c[x] != c[y])
            ans += 1ll * delta;
        a[x] -= delta, a[y] -= delta;
        i += delta, j -= delta;
        if (a[x] == 0) x++;
        if (a[y] == 0) y--;
    }
    cout << ans << '\n';
    return 0;
}
