#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10;
vector<pair<int,int> > a[M];
int f[N][N],w[M];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        while(k--)
        {
            int p,t;
            cin>>p>>t;
            a[p].emplace_back(i,t);
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++)
        for(int j=0;j<a[i].size();j++)
            for(int k=j+1;k<a[i].size();k++)
            {
                auto [x,u]=a[i][j];
                auto [y,v]=a[i][k];
                if(f[x][y]>u+v) f[x][y]=f[y][x]=u+v;
            }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--)
    {
        int s,t;
        cin>>s>>t;
        int ans=1e18;
        for(auto [x,u]:a[s])
            for(auto [y,v]:a[t])
                ans=min(ans,u+v+f[x][y]);
        ans+=w[s]+w[t];
        cout<<ans<<'\n';
    }
    return 0;
}