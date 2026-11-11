#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],ans = 0,c[200005],d[200005],g;
char b[200005],e[200005],f[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i] >> b[i];
        g += a[i];
    }
    int y,z;
    if(g % 2 == 0)
    {
        y = g/2;
        z = g/2;
    }
    else
    {
        y = (g-1)/2;
        z = (g+1)/2;
    }
    int x = 0;
    for(int i = 1;i <= n;i++)
    {
        x += a[i];
        e[i] = b[i];
        if(x >= y)
        {
            c[i] = a[i] + y -x;
            break;
        }
        c[i] = a[i];
    }
    x = g;
    for(int i = n;i >= 1;i--)
    {
        x -= a[i];
        f[i] = b[i];
        if(x <= z)
        {
            d[i] = a[i] +x-z;
            break;
        }
        d[i] = a[i];
    }
    int l = 1,r = n;
    while (1)
    {
        if ((c[l] == 0)&&(d[r] == 0))
        {
            break;
        }
        if(c[l] >= d[r])
        {
            c[l] -= d[r];
            if(e[l] != f[r])
            {
                ans += d[r];
            }

            d[r] = 0;
            r--;
        }
        if(c[l] <= d[r])
        {
            d[r] -= c[l];
            if(e[l] != f[r])
            {
                ans += c[l];
            }

            c[l] == 0;
            l++;
        }
    }
    cout << ans;
    return 0;
}
