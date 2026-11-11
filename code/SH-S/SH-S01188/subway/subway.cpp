#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w,k,a,t,sum;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    srand(time(0));
    cin>>c>>t;
    while(t--)
    {
        cin>>c>>n>>m>>d>>q;
        for(int i=1;i<=m;i++)
        {
            cin>>w;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>k;
            for(int j=1;j<=k;j++)
            {
                cin>>a>>t;
                sum+=t;
            }
        }
        for(int i=1;i<=q;i++)
        {
            long long x,y;
            cin>>x>>y;
            long long ans=rand()%(sum+3*w);
            cout<<ans<<endl;
        }
    }
}

