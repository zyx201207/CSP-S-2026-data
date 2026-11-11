#include <bits/stdc++.h>
using namespace std;
int a[500001];
int t[101];
int b[101];
int x[500001];
int s[11];
int g[11];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long n,m,d,q,c,ans = 0;
    cin >> c >> n >> m >> d >> q;

    for(int i = 1;i <= m;i++)
    {
        cin >> a[i];
    }
    x[0] = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> x[i];
        for(int j = 1;j <= x[i];j++)
        {
            cin >> b[j + x[i - 1]] >> t[j + x[i - 1]];
        }
    }
    int y,e;
    for(int i = 1;i <= q;i++)
    {
        cin >> s[i] >> g[i];
        for(int j = 1;j <= x[i];i++)
        {
            if(s[i] == b[j])
            {
                y = j;
            }
            else if(g[i] == b[j])
            {
                e = j;
            }
        }
    }
    if(n == 1)
    {
        for(int i = 1;i <= q;i++)
        {
            for(int j = 1;j <= x[i];j++)
            {
                if(s[i] == b[j])
                {
                     ans = ans + a[j] + t[j];
                }
                if(g[i] == b[j])
                {
                    ans = ans + a[j] + t[j];
                }
            }
        }
    }
    if(n == 2)
    {
        if(y <= x[1] && e <= x[1] || y >= x[1] && e >= x[1])
        {
            ans = ans + a[y] + t[y] + a[e] + t[e];
        }
    }
    cout << ans;


return 0;
}
