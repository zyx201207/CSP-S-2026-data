#include <bits/stdc++.h>
using namespace std;

int a[500005];
long long diff[500005];
long long s[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n;
    cin >> n;
    long long m;
    cin >> m;
    bool f = 1;
    bool d = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != i)
        {
            f = 0;
        }
        if (i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2])
        {
            d = 0;
        }
    }

    if (f)
    {
        long long sum = 0;
        bool flag = 1;
        for (int i = 1; i <= n; i++)
        {
            sum += (i - 1);
            if (sum > m)
            {
                cout << i - 1;
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << n << '\n';
    }
    else if (d)
    {
        int x = a[2] - a[1];
        int sum = 0;
        bool flag = 1;
        for (int i = 1; i <= n; i++)
        {
            sum += (x * (i - 1));
            if (sum > m)
            {
                cout << i - 1;
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << n << '\n';
    }
    else
    {
        sort(a + 1, a + n + 1);

        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
                diff[i] = 0;
            else
                diff[i] = a[i] - a[i - 1];
        }

        for (int i = 1; i <= n; i++)
        {
            s[i] = s[i - 1] + diff[i];
        }
        int ans = -1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                long long sum = 0;
                for (int k = i; k < j; k++)
                {
                    sum += s[j] - s[k];
                    //cout << s[j] - s[k] << '\n';
                }
                if (sum > m)
                {
                    continue;
                }
                ans = max(ans, j - i + 1);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
