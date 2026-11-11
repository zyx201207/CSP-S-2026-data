#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005],w,v,u;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        w = max(w,a[i]);
    }
    if(m == 1)
    {
        cout << w;
    }
    if(m == 2)
    {
        for(int i = 1;i < n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                v = max(v,a[i] & a[j]);
            }
        }
        cout << v;
    }
    if(m == n)
    {
        v = a[1] & a[2];
        for(int i = 3;i <= n;i++)
        {
            v = v & a[i];
        }
        cout << v;
    }
    if((m + 1 == n) && (m != 1) && (m != 2))
    {
        v = a[1];
        for(int i = 3;i <= n;i++)
        {
            v = v & a[i];
        }
        u = max(u,v);
        v = a[2];
        for(int i = 3;i <= n;i++)
        {
            v = v & a[i];
        }
        u = max(u,v);
        for(int j = 3;j <= n;j++)
        {
            v = a[1] & a[2];
            for(int i = 3;i <= n;i++)
            {
                if(i == j)
                {
                    continue;
                }
                v = v & a[i];
            }
            u = max(u,v);
        }
        cout << u;
    }
    return 0;
}
