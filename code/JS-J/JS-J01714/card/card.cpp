#include <bits/stdc++.h>

using namespace std;

int a[500005], pos[500005], ans[500005];

void turn(int n, int s)
{
    memset(pos, 0, sizeof pos);
    int cnt = 0;
    for(int i = s; i <= n; i++)
    {
        for(int j = 1; j <= cnt; j++)
            if(pos[j] == a[i])
            {
                for(int k = j; k <= cnt; pos[k++] = 0, cnt--);
                break;
            }
        pos[++cnt] = a[i];
    }

    for(int i = 1; i <= cnt; i++)
        ans[pos[i]]++;
}

void solve(int n, int m)
{
    for(int i = 1; i <= n; i++)
        turn(n, i);

    for(int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
}

void solve_A(int n, int m)
{
    for(int i = 1; i <= n; i++)
    {
        if(a[i] != a[i - 1])
            ans[a[i]] = ans[a[i] - 1];
        ans[a[i]]++;
    }

    for(int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
}

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    bool flag = 1;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i != 1 && a[i] < a[i - 1])
            flag = 0;
    }

    if(flag)
        solve_A(n, m);
    else
        solve(n, m);

    return 0;
}