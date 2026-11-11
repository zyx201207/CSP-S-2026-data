#include <bits/stdc++.h>
using namespace std;

int n, m, maxn;
int a[200010];
int op[200010];

void num(int b, int d)
{
    if (b == 0)
    {
        int x = a[op[1]];
        for (int i = 2; i <= m; i++)
        {
            x = x & a[op[i]];
        }
        maxn = max(maxn, x);
        return;
    }
    for (int i = d + 1; i <= n - b + 1; i++)
    {
        op[b] = i;
        num(b - 1, i);
        op[b] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    num(m, 0);
    cout << maxn << "\n";
    return 0;
}
