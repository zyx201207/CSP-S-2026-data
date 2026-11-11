#include <bits/stdc++.h>
using namespace std;

long long n , m , zd , zdh , lb[200005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(long long i = 1;i <= n;i++)
    {
        cin >> lb[i];
    }
    for(long long j = 1;j <= m;j++)
    {
        zd = 0;
        for(long long i = 1;i <= n;i++)
        {
            if(lb[i] > zd)
            {
                zd = lb[i];
                zdh = i;
            }
        }
        lb[zdh] = 0;
    }
    cout << zd;

    return 0;
}
