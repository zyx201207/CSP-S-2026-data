#include<bits/stdc++.h>
#define int long long
using namespace std;
/* define & const */
using ll = long long;
const int N = 2e5 + 10;
/* struct */

/* Variables */
ll n, m;
ll a[N];
bool used[N];
ll ans = LONG_LONG_MIN;
/* Function */
void brute_dfs(int id, int cnt)
{
    if (cnt == m)
    {
        int flag = 1;
        ll res;
        int cnt2 = 0;
        for (int i = 0; i <= id; i++)
        {
            if (used[i] == 1)
            {
                cnt2 ++;
                // cout << a[i] << ", ";
                if (flag == 1)
                {
                    res = a[i];
                    flag = 0;
                }
                else
                {
                    res &= a[i];
                }
            }
        }
        // cout << "\n";
        assert(cnt2 == cnt);
        ans = max(ans, res);
        return;
    }
    if (id == n - 1)
    {
        return;
    }
    used[id + 1] = 1;
    brute_dfs(id + 1, cnt + 1);
    used[id + 1] = 0;
    brute_dfs(id + 1, cnt);
    return;
}
void case1()
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ans = a[i];
        }
        else
        {
            ans &= a[i];
        }
    }
    
}
void case2()
{
    for (int i = 0; i < n; i++)
    {
        ll res;
        int flag = 1;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            if (flag == 1)
            {
                res = a[j];
                flag = 0;
            }
            else
            {
                res &= a[j];
            }
        }
        ans = max(ans, res);
    }
    
}
bool cmp(ll a, ll b)
{
    return a > b;
}
void case3()
{
    sort(a, a + n, cmp);
    for (int i = 0; i < m; i++)
    {
        if (i == 0)
        {
            ans = a[i];
        }
        else
        {
            ans &= a[i];
        }
    }
}
/* main */

signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (m == n)
    {
        case1();
        cout << ans;
        return 0;
    }
    if (m == n - 1)
    {
        case2();
        cout << ans;
        return 0;
    }
    if (n <= 2005)
    {
        brute_dfs(-1, 0);
        cout << ans;
        return 0;
    }
    case3();
    cout << ans;
    return 0;
}