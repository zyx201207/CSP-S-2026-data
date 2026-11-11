#include <bits/stdc++.h>
using namespace std;
int c,n,m,p,q,d[505][505],w[500005],x[505][500005],t[505][500005];
vector<pair<int,int>> a[505];
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>p>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    memset(d,sizeof(d),0x3f);
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x,t;
            cin>>x>>t;
            a[i].push_back({x,t});
        }
    }
    for(int i=1;i<=n;i++)
    {
        sort(a[i].begin(),a[i].end());
        for(int j=0;j<a[i].size();j++)
        {
            x[i][j+1]=a[i][j].first;
            t[i][j+1]=a[i][j].second;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=1;k<=a[i].size();k++)
            {
                if(binary_search(x[j]+1,x[j]+a[j].size()+1,x[i][k]))
                {
                    int l=lower_bound(x[j]+1,x[j]+a[j].size()+1,x[i][k])-x[j];
                    d[i][j]=t[i][k]+t[j][l];
                    d[j][i]=t[i][k]+t[j][l];
                }
            }
        }
    }
    floyd();
    while(q--)
    {
        int s,f;
        cin>>s>>f;
        vector<int> so,fo;
        for(int i=1;i<=n;i++)
        {
            if(binary_search(x[i]+1,x[i]+a[i].size()+1,s))
            {
                so.push_back(i);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(binary_search(x[i]+1,x[i]+a[i].size()+1,f))
            {
                fo.push_back(i);
            }
        }
        int minn=0x3f3f3f3f;
        for(int u:so)
        {
            for(int v:fo)
            {
                minn=min(minn,w[s]+t[u][s]+d[u][v]+t[v][f]+w[f]);
            }
        }
        cout<<minn<<"\n";
    }
}
