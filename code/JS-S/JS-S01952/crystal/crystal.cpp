#include <bits/stdc++.h>
using namespace std;
long long a[500010] , s[500010];
int main()
{
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    int n;
    long long m;
    scanf("%d%lld" , &n , &m);
    bool flag = true , flag2 = true , d = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        scanf("%lld" , &a[i]);
        if (a[i] != i) flag = false;
        if (i == 2) d = a[i] - a[i - 1];
        else if (i > 2 && a[i] - a[i - 1] != d) flag2 = false;
    }
    if (flag)
    {
        long long sum = 0;
        int t = 0;
        while (sum <= m)
        {
            sum += ++t;
        }
        cout << t;
        return 0;
    }
    sort(a + 1 , a + n + 1);
    if (flag2)
    {
        int x = a[2] - a[1];
        long long sum = 0;
        int t = 0 , cnt = 0;
        while (sum <= m)
        {
            t += x;
            sum += t;
            cnt++;
        }
        cout << cnt - 1;
    }
    long long last = 0 , lastpos = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        s[i] = s[i - 1] + (i - 1) * (a[i] - a[i - 1]);
    }
    int ans = 0;
    for (int i = 1; i <= n ; i++)
    {
        if (ans >= n - i + 1) break;
        for (int j = i ; j <= n ; j++)
        {
            if (s[j] - s[i] - 1ll * (i - 1) * (a[j] - a[i]) <= m) ans = max(ans , j - i + 1);
            else break;
        }
    }
    cout << ans;
    return 0;
}
