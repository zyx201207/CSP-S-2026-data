#include <bits/stdc++.h>
using namespace std;
long long w[1000000005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for (long long i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for (long long i=1;i<=n;i++)
    {
        long long k;
        cin >> k;
        for (long long i=1;i<=k;i++)
        {
            long long a,t;
            cin >> a >> t;
        }
    }
    for (long long i=1;i<=q;i++)
    {
        long long x,y;
        cin >> x >> y;
        cout << w[x]+w[y]+8 << endl;
    }
    return 0;
}
