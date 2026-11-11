#include <bits/stdc++.h>
using namespace std;
main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<1;
    }
    if(m==1)
    {
        cout<<n;
    }
    if(m==n)
    {
        for(int i=n;i>=1;i--)
        {
        cout<<i<<" ";
        }
    }
    return 0;
}
