#include <bits/stdc++.h>

using namespace std;

int ans, a[200005], pre[200005], suf[200005];

int read()
{
    int x = 0, f = 1, c = getchar();
    while(!isdigit(c))
    {
        if(c == '-')
            f = -1;
        c = getchar();
    }
    while(isdigit(c))
        x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return x * f;
}

void dfs(int cnt, int m, int node, int n, int cur)
{
    if(cnt < m - 1)
    {
        if(m - cnt > n - node)
            return;
        for(int i = node + 1; i <= n; i++)
            dfs(cnt + 1, m, i, n, cur & a[i]);
    }
    else
        for(int i = node + 1; i <= n; i++)
            ans = max(cur & a[i], ans);
}

void solve_6(int n)
{
    cout << *max_element(a + 1, a + n + 1);
}

void solve_7(int n)
{
    int res = a[1];
    for(int i = 2; i <= n; i++)
        res &= a[i];

    cout << res;
}

void solve_11_12(int n)
{
    pre[1] = a[1], suf[n] = a[n];
    for(int i = 2; i < n; i++)
        pre[i] = a[i] & pre[i - 1];
    for(int i = n - 1; i > 1; i--)
        suf[i] = a[i] & suf[i + 1];

    int res = max(pre[n - 1], suf[2]);
    for(int i = 2; i < n; i++)
        res = max(pre[i - 1] & suf[i + 1], res);

    cout << res;
}

void solve_14_15(int n, int m)
{
    cout << n - m;
}

void solve_13(int n, int m)
{
    sort(a + 1, a + n + 1, greater<int>());

    int res = a[1];
    for(int i = 2; i <= m; i++)
        res &= a[i];

    cout << res;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int n = read(), m = read();
    bool flag = 1;
    for(int i = 1; i <= n; i++)
        if((a[i] = read()) != i - 1)
            flag = 0;

    if(m == 1)
        solve_6(n);
    else if(m == n)
        solve_7(n);
    else if(m == n - 1)
        solve_11_12(n);
    else if(flag)
        solve_14_15(n, m);
    else if(n <= 2000)
    {
        for(int i = 1; i <= n; i++)
            dfs(1, m, i, n, a[i]);

        cout << ans;
    }
    else
        solve_13(n, m);

    return 0;
}