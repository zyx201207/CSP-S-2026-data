#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],m,minn = 1e15,x,ans = 0,maxx = -1,qwq = 0,qwq2 = 0;
void f()
{
    minn = 1e15;
    for (int i = 1;i <= n;i++)
    {
        if (i >= 2)
        {
            if (minn >= a[i] - a[i-1] && a[i]- a[i-1] != 0)
            {
                minn = a[i] - a[i-1];
                x = i-1;
            }
        }
    }
    if (minn < 1e15)
    {
        a[x] += minn;
        m -= minn;
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if (i >= 2 && a[i] == a[i-1]) qwq++;
        if (i >= 3 && a[i-1] - a[i-2] == a[i] - a[i-1]) qwq2++;
    }
    if (qwq == n-1)
    {
        cout << n;
        return 0;
    }
    if (qwq2 == n-2)
    {
        int cnt = 0;
        int ans2 = 0;
        int u = a[n] - a[n-1];
        while (m > 0)
        {
            cnt += u;
            m -= cnt;
            ans2++;
            if (ans2 >= n)
            {
                cout << n;
                return 0;
            }
        }
        if (m < 0) cout << ans2;
        else cout << ans2 + 1;
        return 0;
    }
    sort(a + 1,a + n + 1);
    while (m > 0)
    {
        f();
        ans = 0;
        minn = a[x];
        for (int i = 1;i <= n;i++)
        {
            if (a[i] == minn) ans++;
        }
        maxx = max(maxx,ans);
    }
    cout << maxx;
    return 0;
}
