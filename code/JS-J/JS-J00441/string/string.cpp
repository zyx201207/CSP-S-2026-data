#include <bits/stdc++.h>
using namespace std;

long long n , dj = 1 , zs , xgcs = 0 , sz[200005];
char zm[200005] , lb[1000000005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(long long i = 1;i <= n;i++)
    {
        cin >> sz[i] >> zm[i];
    }
    for(long long i = 1;i <= n;i++)
    {
        for(long long j = 1;j <= sz[i];j++)
        {
            lb[dj] = zm[i];
            dj++;
        }
    }
    dj--;
    zs = dj;
    if(dj % 2 == 0)
    {
        dj /= 2;
    }
    else
    {
        dj--;
        dj /= 2;
    }
    for(long long i = 1;i <= dj;i++)
    {
        if(lb[i] != lb[zs + 1 - i])
        {
            xgcs++;
        }
    }
    cout << xgcs;

    return 0;
}
