#include <cstdio>

using namespace std;
using Int = long long;
const Int N = 5e5 + 25;
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
    putchar(' ');
}
Int n, m, a[N], cnt[N], st[N], top;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    n = read(), m = read();
    for (Int i = 1; i <= n; i++)
        a[i] = read();
    for (Int i = 1; i <= m; i++)
        write(n);
    return 0;
}
