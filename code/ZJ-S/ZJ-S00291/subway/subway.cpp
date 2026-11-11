#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int> w(m+1);
    vector<vector<int>> gra(m+n+1,vector<int>(m+n+1,1e18));
    for(int i=1;i<=m+n;++i) gra[i][i]=0;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;++j)
        {
            int a,t;
            cin>>a>>t;
            gra[a][i+m]=t;
            gra[i+m][a]=t;
        }
    }
    for(int k=1;k<=m+n;++k)
    {
        for(int i=1;i<=m+n;++i)
        {
            for(int j=1;j<=m+n;++j)
            {
                gra[i][j]=min(gra[i][j],gra[i][k]+gra[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<gra[x][y]+w[x]+w[y]<<'\n';
    }
}