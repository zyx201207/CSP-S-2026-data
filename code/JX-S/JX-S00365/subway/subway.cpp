#include<iostream>
using namespace std;
int c,n,m,d,q,w[500005],k,b[1000000],a[1000000],x[505],y[505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i += 1)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i += 1)
    {
        cin >> k;
        for (int j = 1;j <= k;j += 1)
        {
            cin >> a[j] >> b[j];
        }
    }
    for (int i = 1;i <= q;i += 1)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 1;i <= q;i += 1)
    {
        for (int j = 2;j <= m;j += 1)
        {
            a[1] += a[j];
        }
        cout << a[1] << endl;
    }
}
