#include<iostream>
#include<vector>
#define AK return
#define CSP 0;
#define int long long
using namespace std;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    int c,t;
    cin >> c >> t;
if(c == 11 || c == 12)
{
while(t--)
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    int c = m/(a[2]-a[1]);
    if(c <= 1)
    {
        cout << 0 << '\n';
        continue;
    }
    int s = 0;
    for(int i = 1;i <= n;i++)
    {
        if(i+c+c-1 <= n)
        {
            s++;
        }
    }
    cout << s << '\n';
}
AK CSP
}
if(c == 13 || c == 14)
{
while(t--)
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    int md = -1;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] - a[1] <= m && a[n] - a[i] <= m)
        {
            md = i;
            break;
        }
    }
    vector<int> l(n+1);
    l[md] = 1;
    int p = 1,s = 0;
    for(int i = md+1;i <= n;i++)
    {
        while(p < i && a[i]-a[p] > m)
        {
            p++;
        }
        l[i] = p;
        if(l[i] >= md-1)
        {
            s += l[md+1]-1;
        }
    }
}
}
while(t--)
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> d(n+1,vector<int>(n+1,1e9)),ds(n+1,vector<int>(n+1));
    vector<int> a(n+1);
    int s = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        int l;
        for(l = i-1;l > 0 && a[i]-a[l] <= m;l--)
        {
            //ef yv si kei si si ef
        }
        for(int j = i-1;j > l;j--)
        {
            d[i][j] = 1;
            ds[i][j] = 1;
            for(int k = l;k > 0;k--)
            {
                if(d[j][k]+1 < d[i][k])
                {
                    d[i][k] = d[j][k]+1;
                    ds[i][k] = ds[j][k];
                }
                else if(d[j][k]+1 == d[i][k])
                {
                    ds[i][k] += ds[j][k];
                }
            }
        }
        for(int j = l;j > 0;j--)
        {
            if(ds[i][j] == 2)
            {
                //cout << i << ',' << j << ',' << d[i][j] << ' ';
                s++;
            }
        }
    }
    cout << s << '\n';
}
    AK CSP
}
