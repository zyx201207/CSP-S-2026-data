#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int c,n,m,q,d[505][505],t[500005],num[500005],a,b;
vector<pair<int,int> > ve[500005];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>c>>q;
    for(int i=1;i<=m;i++)cin>>t[i];
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        for(int j=1;j<=c;j++)
        {
            cin>>a>>b;
            ve[a].push_back({i,b}),num[a]++;
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)d[i][j]=inf;
    for(int i=1;i<=m;i++)for(int j=1;j<num[i];j++)for(int k=0;k<j;k++)a=ve[i][j].first,b=ve[i][k].first,d[a][b]=min(d[a][b],ve[i][j].second+ve[i][k].second);
    for(int i=1;i<=n;i++)for(int j=1;j<i;j++)d[j][i]=d[i][j];
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for(int i=1;i<=q;i++)
    {
        cin>>a>>b;
        c=inf;
        for(int j=0;j<num[a];j++)for(int k=0;k<num[b];k++)c=min(c,ve[a][j].second+ve[b][k].second+d[ve[a][j].first][ve[b][k].first]);
        cout<<t[a]+t[b]+c<<'\n';
    }
    return 0;
}
