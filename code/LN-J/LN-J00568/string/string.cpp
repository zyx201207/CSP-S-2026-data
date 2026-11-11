#include <cstdio>
#include <string>
#include <algorithm>
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
Int n, a, c, ans;
string s;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    n = read();
    if (n == 1)
    {
        write(0);
        return 0;
    }
    for (Int i = 1; i <= n; i++)
    {
        a = read();
        c = getchar();
        for (Int j = 1; j <= a; j++)
            s += c;
    }
    for (Int i = 0; i < (s.size() >> 1ll); i++)
        if (s[i] != s[s.size() - i - 1])
            ++ans;
    write(ans);
    return 0;
}
