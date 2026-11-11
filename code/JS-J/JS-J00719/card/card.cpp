#include <bits/stdc++.h>
using namespace std;

const int N = 500010;
int n, m, a[N];

struct Node
{
    bool flag = false;
    int num = 0;
};

bool solve(int i, int q)
{
    int cur = 0;
    Node f[N];
    int c[N] = {};
    for (int k = i; k <= n; k++)
    {
        int x = a[k];
        if (!f[x].flag)
        {
            f[x].flag = true;
            c[++cur] = x;
            f[x].num = cur;
        }
        else
        {
            for (int j = f[x].num + 1; j <= cur; j++)
            {
                f[c[j]].flag = false;
                c[j] = 0;
            }
            cur = f[x].num;
        }
    }
    if (f[q].flag) return true;
    return false;
}

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int ans = 0;
        for (int j = 1; j <= n; j++)
        {
            ans += solve(j, i);
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}
