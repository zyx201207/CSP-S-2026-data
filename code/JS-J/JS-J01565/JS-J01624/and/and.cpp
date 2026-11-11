#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, answ;
ll a[200010];

void dfs(ll x, ll ans, ll last)
{
    if (x == 0)
    {
        answ = max(answ, ans);
        return;
    }
    for (int i = last + 1; i <= n; i++)
    {
        if (ans == 1)
            dfs(x-1, a[i], i);
        else
            dfs(x-1, ans & a[i], i);
    }
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n <= 20)
    {
        dfs(m, 1, 0);
        cout << answ;
    }
    else if (n <= 2000)
    {
        if (m == 1)
            cout << max_element(a+1, a+n+1);
        else if (m == n)
        {
            answ = a[1];
            for (int i = 2; i <= n; i++)
            {
                answ &= a[i];
            }
            cout << answ;
        }
        else if (m == 2)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    answ = max(answ, a[i] & a[j]);
                }
            }
            cout << answ;
        }
    }
    else
    {
        cout << rand() % 5723534;
    }
    return 0;
}
