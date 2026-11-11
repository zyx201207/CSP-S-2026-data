#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N], lst[N], n, m, card[N], ans[N], num[N], tmp[N];
void play(int i)
{
    int x = 0, st = i;
    for (int j = 1; j <= m; j++)
        lst[j] = -1;
    for (; i <= n; i++)
    {
        if (lst[a[i]] != -1)
        {
            for (int j = lst[a[i]] + 1; j <= x; j++)
                lst[card[j]] = -1;
            x = lst[a[i]] - 1;
        }
        x++;
        lst[a[i]] = x;
        card[x] = a[i];
    }
    for (int j = 1; j <= x; j++)
        ans[card[j]] += num[st];
}
signed main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    bool special_A = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < a[i - 1])
            special_A = 0;
    }
    if (m == 1)
    {
        cout << n;
        return 0;
    }
    else if (m == 2)
    {
        int num1 = 0, num2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 1)
                num1++;
            else
                num2++;
        }
        if (a[n] == 1)
            num1 = n;
        else
            num2 = n;
        cout << num1 << " " << num2;
        return 0;
    }
    if (special_A)
    {
        for (int i = 1; i <= n; i++)
            ans[a[i]] = i;
        for (int i = 1; i <= m; i++)
            cout << ans[i] << " ";
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[i - 1])
            num[cnt]++;
        else
        {
            cnt++;
            tmp[cnt] = a[i];
            num[cnt] = 1;
        }
    }
    for (int i = 1; i <= cnt; i++)
        a[i] = tmp[i];
    n = cnt;
    for (int i = 1; i <= n; i++)
        play(i);
    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    return 0;
}