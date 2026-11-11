#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define check(x) (m >= pre[s - mid])

using namespace std;

vector<int> pos;
int a[500005], val[205], pre[500005];

int read()
{
    int x = 0, f = 1, c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (isdigit(c))
        x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return x * f;
}

int cnt(int n, int m, int s)
{
    int ans = 0;
    for(int i = s - 1; i; i--)
        if(m >= a[s] - a[i])
            m -= a[s] - a[i], ans++;
        else
            break;

    return ans;
}

void solve(int n, int m)
{
    stable_sort(a + 1, a + n + 1);

    int ans = 0;
    for(auto &&x : pos)
        ans = max(cnt(n, m, x), ans);

    cout << ans + 1;
}

int cnt_heap(int n, int m, int s)
{
    int ans = 0;
    for(int i = s - 1; i >= 0; i--)
        if(m >= (s - i) * val[i])
            m -= (s - i) * val[i], ans += val[i];
        else
        {
            ans += m / (s - i);
            break;
        }

    return ans + val[s];
}

void solve_heap(int n, int m)
{
    for(int i = 1; i <= n; i++)
        val[a[i] + 100]++;

    int ans = 0;
    for(int i = 1; i <= 200; i++)
        ans = max(cnt_heap(n, m, i), ans);

    cout << ans;
}

int cnt_equal_minus(int n, int m, int s)
{
    int l = 1, r = s;
    while(l <= r)
    {
        int mid = l + r >> 1;
        if(check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }

    return s - l;
}

void solve_equal_minus(int n, int m)
{
    int minus = a[2] - a[1];
    for(int i = 1; i <= n; i++)
        pre[i] = minus + pre[i - 1];
    for(int i = 2; i <= n; i++)
        pre[i] += pre[i - 1];

    int ans = 0;
    for(int i = 2; i <= n; i++)
        ans = max(cnt_equal_minus(n, m, i), ans);

    cout << ans;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n = read(), m = read();
    bool flag1 = 1, flag2 = 1;
    for(int i = 1; i <= n; i++)
    {
        a[i] = read();
        if(i != 1 && a[i] != a[i - 1])
            pos.pb(i - 1);
        if(abs(a[i]) > 100)
            flag1 = 0;
    }

    if(flag1)
        solve_heap(n, m);
    else
    {
        sort(a + 1, a + n + 1);
        for(int i = 3; i <= n; i++)
            if(a[i] - a[i - 1] != a[2] - a[1])
            {
                flag2 = 0;
                break;
            }

        if(flag2)
            solve_equal_minus(n, m);
        else
            solve(n, m);
    }

    return 0;
}