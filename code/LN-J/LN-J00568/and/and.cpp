#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
using Int = long long;
const Int N = 2e5 + 10;
Int read()
{
    Int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + (ch - '0'), ch = getchar();
    return x * f;
}
void write(Int x)
{
    if (x == 0)
    {
        putchar('0');
        return;
    }
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    Int len = 0;
    char tmp[20];
    while (x)
        tmp[len++] = x % 10 + '0', x /= 10;
    while (len)
        putchar(tmp[--len]);
}
Int n, m, a[N], x, ans;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    n = read(), m = read();
    if (m == 1)
    {
        for (Int i = 1; i <= n; i++)
            x = read(), ans = max(ans, x);
        write(ans);
        return 0;
    }
    for (Int i = 1; i <= n; i++)
        a[i] = read();
    if (m == 2)
    {
        for (Int i = 1; i <= n; i++)
            for (Int j = i + 1; j <= n; j++)
                ans = max(ans, (a[i] & a[j]));
        write(ans);
        return 0;
    }
    if (m == n)
    {
        ans = a[1];
        for (Int i = 2; i <= n; i++)
            ans &= a[i];
        write(ans);
        return 0;
    }
    if (m == n - 1)
    {
        sort(a + 1, a + n + 1, greater<Int>());
        ans = a[1];
        for (Int i = 2; i < n; i++)
            ans &= a[i];
        write(ans);
        return 0;
    }
    bool flag = true, flag2 = true, flag3 = true;
    for (Int i = 1; i <= n && (flag || flag2 || flag3); i++)
    {
        if (a[i] >= 4)
            flag = false;
        if (a[i] != 1 && a[i] != 3 && a[i] != 7 && a[i] != 15 && a[i] != 31 && a[i] != 63 && a[i] != 127 && a[i] != 255 && a[i] != 511 && a[i] != 1023 && a[i] != 2047 && a[i] != 4095 && a[i] != 8191 && a[i] != 16383 && a[i] != 32767 && a[i] != 65535 && a[i] != 131071 && a[i] != 262143)
            flag2 = false;
        if (a[i] != i - 1)
            flag3 = false;
    }
    if (flag)
    {
        Int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (Int i = 1; i <= n; i++)
            if (a[i] == 1)
                ++cnt1;
            else if (a[i] == 2)
                ++cnt2;
            else
                ++cnt3;
        if (m <= cnt3)
            write(3);
        else if (m <= cnt3 + cnt2)
            write(2);
        else
            write(1);
        return 0;
    }
    if (flag2)
    {
        sort(a + 1, a + n + 1, greater<Int>());
        ans = a[1];
        for (Int i = 1; i <= m; i++)
            ans = min(ans, a[i]);
        write(ans);
        return 0;
    }
    if (flag3)
    {
        ans = a[n];
        for (Int i = n - 1; i > n - m; i--)
            ans &= a[i];
        write(ans);
        return 0;
    }
    sort(a + 1, a + n + 1);
    do
    {
        Int cur = a[1];
        for (Int i = 2; i <= m; i++)
            cur &= a[i];
        ans = max(ans, cur);
    }
    while (next_permutation(a + 1, a + n + 1));
    return 0;
}
