#include<bits/stdc++.h>
using namespace std;
int c,n,m,d1,q,b[500010];
int main()
{
    vector<int>a;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d1>>q;
    a.push_back(0);
    for(int i=1;i<=m;i++)
    {
        int bb;
        cin>>bb;
        a.push_back(bb);
    }
    if(n==2)
    {
        int k,sum=1e9;
        int v,w,d[500010];
        cin>>k;
        for(int i=1;i<=k;i++)
        {
            cin>>v>>w;
            b[v]++;
            d[v]=w;
        }
        cin>>k;
        for(int i=1;i<=k;i++)
        {
            cin>>v>>w;
            if(b[v])
            {
                d[v]=w+d[v];
                sum=min(sum,d[v]);
            }
        }
        int x,y,ans;
        for(int i=1;i<=q;i++)
        {
            cin>>x>>y;
            ans=a[x]+a[y]+sum;
            cout<<ans<<endl;
        }
    }
    /*else
    {
        int t;
        for(int i=1;i<=n;i++)
        {
            cin>>k;
            int v,w;
            cin>>v>>w;
            t=w;
            w=v;
            for(int j=1;j<k;j++)
            {
                cin>>v;
                ne[v][w]=0
            }
        }
    }*/
    return 0;
}
