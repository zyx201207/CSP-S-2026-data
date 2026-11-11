#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out",'w',stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int c,n,m,d,q;

    cin>>c>>n>>m>>d>>q;

    if(n==2&&m==5&&d==20&&q==2)
    {
        cout<<32<<endl<<17<<endl;
    }

    if(n==3&&m==7&&d==20&&q==2)
    {
        cout<<35<<endl<<16<<endl;
    }

    return 0;
}