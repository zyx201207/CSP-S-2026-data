#include<bits/stdc++.h>
using namespace std;
int w[500005];
int a[500005];
int t[500005];
int c,n,m,d,q;
int qi,zz;
int ti;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    while(1)
    {
        cin>>c>>n>>m>>d>>q;
        for(int i=1;i<=m;i++)
        {
            cin>>w[i];
        }
        for(int i=1;i<=m;i++)
        {
            int k;
            cin>>k;
            for(int i=1;i<=k;i++)
            {
                cin>>a[i]>>t[i];
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>qi>>zz;
        }
        for(int i=1;i<=k;i++)
        {
            ti+=w[i]*2;
        }
        cout<<ti;
    }

    return 0;
}
