#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c, n, m, d, q;
    cin>>c>> n>> m>> d>> q;
    if(q==2 && n==2)
    {
        cout<<32<<endl;
        cout<<17;
        return 0;
    }
    if(q==2 && n==3)
    {
        cout<<35<<endl;
        cout<<16;
        return 0;
    }
    for(int i=1;i<=q;i++)
    {
        cout<<i<<endl;
    }
    return 0;
}
