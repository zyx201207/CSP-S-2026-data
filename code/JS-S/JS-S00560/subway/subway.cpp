#include<vector>
#include<cstring>
#include<iostream>
#define int long long
using namespace std;
bool mst;
const int N=505,M=5e5+5,inf=1e18;
int c,n,m,d,q,kk[N],f[N][N],w[M];
vector<pair<int,int> > a[N],id[M];
bool med;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>kk[i];
        a[i].resize(kk[i]+5);
        for(int j=1;j<=kk[i];j++)
        {
            cin>>a[i][j].first>>a[i][j].second;
            id[a[i][j].first].push_back({i,a[i][j].second});
        }
    }
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=m;i++)
        for(auto sx:id[i])
            for(auto sy:id[i])
            {
                int lx=sx.first,ly=sy.first;
                if(lx==ly)continue;
                int vx=sx.second,vy=sy.second;
                f[lx][ly]=min(f[lx][ly],vx+vy);
            }
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--)
    {
        int x,y,ans=inf;cin>>x>>y;
        for(auto sx:id[x])
            for(auto sy:id[y])
            {
                int lx=sx.first,ly=sy.first;
                int vx=sx.second,vy=sy.second;
                ans=min(ans,vx+f[lx][ly]+vy);
            }
        ans+=w[x]+w[y];
        cout<<ans<<endl;
    }
    cerr<<(1.0*clock())/CLOCKS_PER_SEC<<endl;
    cerr<<abs(&mst-&med)/1024.0/1024.0<<"MB\n";
}