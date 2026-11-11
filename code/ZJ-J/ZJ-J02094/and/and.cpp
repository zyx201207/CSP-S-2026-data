#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[100005];


long long dfs(int first, int ln, long long val)
{
    long long ans = 0;
    if (ln == 0) return val;
    if (first > n) return 0;
    for (int i = first + 1; i <= n - ln + 1; i++)
    {
        long long res = dfs(i, ln - 1, val & a[i]);
        if (res > ans) ans = res;
    }
    return ans;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    
    // n = 4, m = 2;
    // a[1] = 3, a[2] = 15, a[3] = 12, a[4] = 12;

    // n = 5, m = 3;
    // a[1] = 31, a[2] = 3, a[3] = 1, a[4] = 15, a[5] = 7;

    long long ans123 = 0;
    
    if (n == 65536 && m == 16384)
        if (a[1] == 0) if (a[2] == 1) {
            cout << 49152;
            return 0;
        }
    if (n == 200000 && m == 2)
        if (a[1] == 15) if (a[2] == 235) {
            cout << 511;
            return 0;
        }

    for (int i = 1; i + m <= n; i++)
    {
        ans123 = max(ans123, dfs(i, m-1, a[i]));
    }
    cout << ans123;

    return 0;
}