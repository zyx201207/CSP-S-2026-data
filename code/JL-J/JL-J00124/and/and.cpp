#include <bits/stdc++.h>
using namespace std;

int bit(int x)
{
    int m = 0;
    while (x > 0)
    {
        if (x % 2 == 1)
        {
            m++;
        }
        x /= 2;
    }
    cout << m << endl;
    return m;
}

struct Treat
{
    int num, bite;
} b[20010];

bool cmp(Treat x1, Treat x2)
{
    if(x1.bite > x2.bite)
    {
        return x1.bite > x2.bite;
    }
    else
    {
        return x1.num > x2.num;
    }
}

int n, m, ans;
int a[20100];

int main()
{
    freopen("and,in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i].num = a[i];
        b[i].bite = bit(a[i]);
    }

    sort(b + 1, b + n + 1, cmp);

    for (int i = 1; i <= n; i++)
    {
        cout << b[i].num << " " << b[i].bite << endl;
    }

    ans = b[1].num;
    for (int i = 2; i <= m; i++)
    {
        ans &= b[i].num;
    }

    cout << ans << "\n";

    return 0;
}
