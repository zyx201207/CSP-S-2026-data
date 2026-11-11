#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = 0;
int a[200010];

map<int, bool> mp;

void dfs(int step, int num, int x)
{
    if (step >= m)
    {
        ans = max(ans, x);
        return;
    }
    for (int i = num+1; i <= n; ++i)
    {
        dfs(step+1, i, ((x == -1)? a[i] : x&a[i]));
    }
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int mul = 1;
    mp[mul] = 1;
    for (int i = 1; i <= 20; ++i)
    {
        mul *= 2;
        mp[mul] = 1;
    }
    cin >> n >> m;
    bool flag = 1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (!mp[a[i]+1])
        {
            flag = 0;
        }
    }
    if (m == n)
    {
        int sum = a[1];
        for (int i = 2; i <= n; ++i)
        {
            sum &= a[i];
        }
        cout << sum;
        return 0;
    }
    if (flag)
    {
        sort(a+1, a+n+1, greater<int>());
        cout << a[m];
    }
    else
    {
        dfs(0, 0, -1);
        cout << ans;
    }
    return 0;
}
