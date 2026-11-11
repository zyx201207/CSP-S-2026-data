#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n,m,a[500005],b[300005],x[300005],y[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i =1;i <= n;i++)
    {
        for(int j = i;j <= n;j++)
        {
            if (x[a[j]] == 1)
            {
                for(int p = y[x[a[j]]];p <= j;p++)
                {
                    x[a[p]] = 0;
                }
            }
            x[a[j]] = 1;
            y[x[a[j]]] = j;
        }
        for(int j = 1;j <= m;j++)
        {
            b[j]+=x[j];
        }
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
    }
    for (int i = 1;i <= m;i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
