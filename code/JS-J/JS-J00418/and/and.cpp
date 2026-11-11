#include <bits/stdc++.h>
using namespace std;
long long n,m,g[200005];
bool vis[200005];

long long ans = 0;
void dg(long long js,int d)
{
    if (d == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                dg(g[i],d+1);
                vis[i] = 0;
            }
        }
    }
    else if (d == m)
    {
        ans = max(ans,js);
        return ;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                dg((js&g[i]),d+1);
                vis[i] = 0;
            }
        }
    }
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;
    /*for (int i = 1; i <= 100; i++)
    {
        long long c,v;
        cin >> c >> v;
        cout << an(c,v) << endl;
    }*/
    for (int i = 1; i <= n; i++)
        cin >> g[i];
    if (m == 1)
    {
        for (int i = 1; i <= n; i++)
            ans = max(ans,g[i]);
    }
    else if (m == 2)
    {
        for (int i = 1; i < n; i++)
            for (int j = i+1; j <= n; j++)
                ans = max(ans,(g[i]&g[j]));
    }
    else if (m == n-1)
    {
        for (int i = 1; i <= n; i++)
        {
            long long jsq;
            if (i == 1)
            {
                jsq = g[2];
                for (int j = 3; j <= n; j++)
                    jsq = (jsq&g[j]);
            }
            else
            {
                jsq = g[1];
                for (int j = 2; j <= n; j++)
                {
                    if (j != i) jsq = (jsq&g[j]);
                }
            }
            ans = max(ans,jsq);
        }
    }
    else if (m == n)
    {
        ans = g[1];
        for (int i = 2; i <= n; i++)
            ans = (ans&g[i]);
    }
    else
    {
        dg(0,0);
    }
    cout << ans;
    return 0;
}
