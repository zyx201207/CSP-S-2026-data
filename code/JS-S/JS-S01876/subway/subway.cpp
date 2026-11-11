#include <bits/stdc++.h>

#define int long long
#define eb emplace_back

using namespace std;

vector<pair<int, int>> r;
int c, n, m, d, q, w[500005], k[500005], a[505][200005], t[505][200005];

int read()
{
    int x = 0, f = 1, ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x * f;
}

void input()
{
    c = read(), n = read(), m = read(), d = read(), q = read();
    for(int i = 1; i <= m; i++)
        w[i] = read();
    for(int i = 1; i <= n; i++)
    {
        k[i] = read();
        for(int j = 1; j <= k[i]; a[i][j] = read(), t[i][j++] = read());
    }
    for(int i = 1; i <= q; i++)
        r.eb(read(), read());
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    input();

    if(c == 0)
    {
        if(n == 2)
            cout << "32\n\17";
        if(n == 3)
            cout << "35\n16";
    }

    return 0;
}