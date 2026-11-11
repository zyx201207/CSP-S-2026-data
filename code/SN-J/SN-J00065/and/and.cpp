#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,x=0,y = 0;
    long long s[n];
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> s[i];
    }
    for (int i = 0;i < n;i++)
        if(s[i] > x) x = s[i];
    for (int i = 0;i < n;i++)
        if(s[i] < x && s[i] > y) y = s[i];
    long long a[x],b[y],k[100000000005],an=0,bn=0,p = 0;
    for(int i = x;i >= 0;i++)
    {
        if(x / 2 != 0) an++;
        a[i] = x % 2;
        x /= 2;
    }
    for(int i = y;i >= 0;i++)
    {
        if(y / 2 != 0) bn++;
        b[i] = x % 2;
        y /= 2;
    }
    if(an > bn || an == bn)
    {
        for (int i = an-1;i >= 0;i--)
        {
            if(a[i] == 1 && b[i] == 1)
                k[i] == 1;
            else
                k[i] == 0;
        }
        for(int i = 0;i < an-1;i++)
        {
            for(int i = 1;i <= an-1;i++)
                k[i] *= 2;
            p += k[i];
            an--;
        }
        p += k[an-1];
    }
    else
    {
        for (int i = bn-1;i >= 0;i--)
        {
            if(a[i] == 1 && b[i] == 1)
                k[i] == 1;
            else
                k[i] == 0;
        }
        for(int i = 0;i < bn-1;i++)
        {
            for(int i = 1;i <= bn-1;i++)
                k[i] *= 2;
            p += k[i];
            bn--;
        }
        p += k[bn-1];
    }
    cout << p;
    return 0;
}

