#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q,ans=INT_MAX;
    cin>>c>>n>>m>>d>>q;
    long long ting[505];
    for(long long i=1;i<=n;i++)
    {
        cin>>ting[i];
    }
    for(long long i=1;i<=m;i++)
    {
        long long jie;
        cin>>jie;
        while(jie--)
        {
            long long che;
            cin>>che;
            for(long long j=1;j<=che;j++)
            {
                int u,w;
                cin>>u>>w;
            }
        }
        while(q--)
        {
            int x,y;
            cin>>x>>y;
        }
    }
    return 0;
}
