#include <bits/stdc++.h>
using namespace std;

long long n , m , ks = 1 , ps , zs[500005] , lb[500005] , ymy[300005] , cs[300005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(long long i = 1;i <= n;i++)
    {
        cin >> lb[i];
    }
    while(ks <= n)
    {
        ps = 0;
        for(long long i = ks;i <= n;i++)
        {
            if(ymy[lb[i]] != 0)
            {
                while(zs[ps] != lb[i])
                {
                    ymy[zs[ps]] = 0;
                    zs[ps] = 0;
                    ps--;
                }
            }
            else
            {
                ymy[lb[i]] = 1;
                ps++;
                zs[ps] = lb[i];
            }
        }
        for(long long i = 1;i <= m;i++)
        {
            cs[i] += ymy[i];
            ymy[i] = 0;
        }
        for(long long i = 1;i <= n;i++)
        {
            zs[i] = 0;
        }
        ks++;
    }
    for(long long i = 1;i <= m;i++)
    {
        cout << cs[i] << ' ';
    }

    return 0;
}
