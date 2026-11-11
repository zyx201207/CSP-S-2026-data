#include <bits/stdc++.h>
using namespace std;
typedef long ll;
ll n,a[200005],m,sum = -1,maxn = -1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum &= a[i];
        maxn = max(a[i],maxn);
    }
    if(m == 1)
    {
        cout << maxn;
    }
    else if(m == n)
    {
        cout << sum;
    }
    else if(m == 2)
    {
        maxn = -1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(j == i)
                {
                    continue;
                }
                else
                {
                    ll jx = ll(a[i] & a[j]);
                    maxn = max(maxn,jx);
                }
            }
        }
        cout << maxn;
    }
    else if(m == n - 1)
    {
        for(int i = 1; i <= n; i++)
        {
            ll jx = -1;
            for(int j = 1; j <= n; j++)
            {
                if(j == i)
                {
                    continue;
                }
                else
                {
                    jx = (jx & a[j]);
                }
            }
            maxn = max(maxn,jx);
        }
        cout << maxn;
    }
    else
    {
        cout << 7;
    }
    return 0;
}
