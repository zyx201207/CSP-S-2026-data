#include<bits/stdc++.h>
using namespace std;

int C;
int n,m,d,q;
long long w[500009];
vector<pair<int,long long> > a[500009];
long long f[509][509];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>C>>n>>m>>d>>q;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    int num,u,v,t;
    for(int i=1;i<=n;i++)
    {
        cin>>num;
        f[i][i]=0;
        for(int j=1;j<=num;j++)
        {
            cin>>u>>t;
            a[u].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            for(int k=0;k<a[i].size();k++)
            {
                f[a[i][j].first][a[i][k].first]=min(f[a[i][j].first][a[i][k].first],a[i][j].second+a[i][k].second);
            }
        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }

    long long ans;
    while(q--)
    {
        cin>>u>>v;
        ans=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i<a[u].size();i++)
        {
            for(int j=0;j<a[v].size();j++)
            {
                ans=min(ans,f[a[u][i].first][a[v][j].first]+a[u][i].second+a[v][j].second);
            }
        }
        cout<<ans+w[u]+w[v]<<"\n";
    }


    return 0;
}
