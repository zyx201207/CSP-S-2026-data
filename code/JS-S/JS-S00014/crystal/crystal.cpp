#include <bits/stdc++.h>
using namespace std;

long long a[100005];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long m, bz = 0;
    int n;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long hs = 1;
    while(bz <= m)
    {
        long long cha = a[hs]-a[hs - 1];
        for(int i = hs;i <= n;i++)
        {
           if(a[i] != a[hs])
           {
               hs = i;
               break;
           }
        }
        bz = bz + cha * (hs - 1);
    }
    cout << hs - 1 << endl;
    return 0;
}
