#include <bits/stdc++.h>
using namespace std;
long long w[500005],a[505][500005],t[505][500005],k[505],x[100005],y[100005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;

    cin >> c >> n >> m >> d >> q;
    for(int i = 0;i < m;i++)cin >> w[i];
    for(int i = 0;i < n;i++)
    {
        cin >> k[i];
        for(int j = 0;j < k[i];j++)cin >> a[i][j] >> t[i][j];

    }
    for(int i = 0;i < q;i++)cin >> x[i] >> y[i];
    long long Xl,Xr,Yl,Yr;
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < k[i];j++)
        {
            for(int l = 0;l < q;l++)
            {
                if(x[l] == a[i][j])
                {
                    Xl = i;
                    Xr = j;
                }
            }
        }
    }
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < k[i];j++)
        {
            for(int l = 0;l < q;l++)
            {
                if(y[l] == a[i][j])
                {
                    Yl = i;
                    Yr = j;
                }
            }
        }
    }
    for(int i = 0;i < q;i++)
    {
        if(n == 1)cout << w[x[i]] + w[y[i]] + t[Xl][Xr] + t[Yl][Yr];
        else cout << 0;
    }
    return 0;
}
