#include <bits/stdc++.h>
using namespace std;
#define FIO(filename) freopen(filename".in","r",stdin);freopen(filename".out","w",stdout);
#define getchar() p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++
char buf[1000000], *p1 = buf, *p2 = buf;
template <typename T>
void read(T &x)
{
    x = 0;
    int f = 1;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-')
            f = -f;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + (c ^ '0');
    x *= f;
}
template <typename T, typename... Args>
void read(T &x, Args &...y)
{
    read(x);
    read(y...);
}
template <typename T>
void chkmx(T &x,T y){x=max(x,y);}
template <typename T>
void chkmn(T &x,T y){x=min(x,y);}
using ll = long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
int cid,n,m,d,q;
vector<tuple<int,ll>>vec[520]; // id, t
vector<tuple<int,ll>>cev[500020]; // col, t
ll val[500020];
ll dis[520][520];
ll vis[500020];
int main()
{
    FIO("subway");
    read(cid,n,m,d,q);
    for(int i=1;i<=m;i++)read(val[i]);
    for(int i=1;i<=n;i++)
    {
        int k;read(k);
        vec[i].resize(k);
        // cerr<<k<<'\n';
        for(auto&[j,t]:vec[i])
        {
            read(j,t);
            // cerr<<j<<' '<<t<<'\n';
            cev[j].emplace_back(i,t);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)dis[i][i]=0;
    memset(vis,-1,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        for(auto[k,t]:vec[i])
            vis[k]=t;
        for(int j=i+1;j<=n;j++)
        {
            ll best=inf;   
            for(auto[k,t]:vec[j])
            {
                if(~vis[k])
                    chkmn(best,vis[k]+t);
            }
            dis[i][j]=dis[j][i]=best;
            // for(int k=1;k<=m;k++)
            //     cerr<<vis[k]<<' ';
            // cerr<<'\n';
            // cerr<<i<<' '<<j<<' '<<best<<'\n';
        }
        for(auto[k,t]:vec[i])
            vis[k]=-1;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                chkmn(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    while(q--)
    {
        int u,v;read(u,v);
        ll ans=inf;
        for(auto[i,tu]:cev[u])
        {
            for(auto[j,tv]:cev[v])
                chkmn(ans,val[u]+tu+dis[i][j]+tv+val[v]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}