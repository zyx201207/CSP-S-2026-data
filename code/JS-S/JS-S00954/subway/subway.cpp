#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10,N=505;
#define int long long
int c,n,m,d,q;// qiu yin hai zai zhui wo ,chu ti ren yuan qi max (deque)
int w[M];
struct node{
    int a,t;
};
vector<node> g[M];//subway
int f[N][N];//floyd
signed main()
{
    //freopen wo yao shang mihuo 
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++)
    {
        int k;cin>>k;
        while(k--){
            int a,t;cin>>a>>t;
            g[a].push_back({i,t});//{name,time}
        }
    }
    memset(f,0x3f,sizeof(f));
    for (int x=1;x<=m;x++)
    {
        //400m so easy
        for (int i=0;i<(int)g[x].size();i++)
        {
            for (int j=0;j<(int)g[x].size();j++)
            {
                if (i==j) continue;
                int u=g[x][i].a,ut=g[x][i].t;
                int v=g[x][j].a,vt=g[x][j].t;
                f[u][v]=min(f[u][v],ut+vt);
                f[v][u]=min(f[v][u],ut+vt);
            }
        }
    }
    //floyd
    for (int i=1;i<=n;i++) f[i][i]=0;
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;cin>>x>>y;
        long long ans=1e18;
        //O(d^2)
        for (int i=0;i<(int)g[x].size();i++)
        {
            for (int j=0;j<(int)g[y].size();j++)
            {
                int u=g[x][i].a,ut=g[x][i].t;
                int v=g[y][j].a,vt=g[y][j].t;
                long long tmp=w[x]+w[y]+ut+vt+f[u][v];
                ans=min(ans,tmp);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}