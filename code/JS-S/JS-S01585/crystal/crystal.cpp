#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500001],n,m;
int ans = 0;
bool check()
{
    int t = a[2]-a[1];
    for (int i = 3;i<=n;i++)
    {
        if (a[i]-a[i-1]!=t)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if (check())
    {
        for (int i = 2;i<=n;i++)
        {
            int t = (i-1)*(a[i]-a[i-1]);
            if (m >= t)
            {
                m -= t;
                ans++;
            }
            else
            {
                break;
            }
        }
        cout << ans;
    }
    else
    {
        for (int k = 1;k<(n-ans);k++)
        {
            int s = 1,v = m;
            for(int i = k+1;i<=n;i++)
            {
                int t = (i-1)*(a[i]-a[i-1]);
                if (v >= t)
                {
                    v -= t;
                    s++;
                }
                else
                {
                    break;
                }
            }
            ans = max(ans,s);
        }
        cout << ans;
    }
    return 0;
}
