#include <bits/stdc++.h>
using namespace std;
main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x;
    string s = {};
    string y;
    cin>>n;

    if(n==1)
    {
        cout<<0;
    }



    for(int i = 1;i<=n;i++)
    {
        cin>>x>>y;
        if(x==1)
        {
            cout<<n/2;
        }

    }
    return 0;
}
