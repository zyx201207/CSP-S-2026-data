#include <bits/stdc++.h>
#define gc() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin))),*p1++)
#define pii pair<int,int>
using ll=long long;
using namespace std;
char buf[1<<20],*p1,*p2;
ll read()
{
    ll s=0,f=1,c=gc();
    for(; !isdigit(c); c=gc()) if(c=='-') f=-1;
    for(; isdigit(c); c=gc()) s=s*10+(c^48);
    return s*f;
}
const int N=505;
const int M=1e3+10;
struct node
{
    int v,l;
    node() {}
    node(int a,int b):v(a),l(b) {}
};
ll c,n,m,d,q,id;
vector<node> adj[2*M];
int ins[N];
int sp[M][2*M];
bool vis[2*M];
void dji(int p)
{
    memset(vis,0,sizeof(vis));
    priority_queue<pii,vector<pii>,greater<pii>> q;
    sp[p][p]=0;
    q.push(make_pair(0,p));
    while(!q.empty())
    {
        int s=q.top().second;
        q.pop();
        if(vis[s]) continue;
        vis[s]=1;
        for(node i:adj[s])
        {
            int v=i.v,l=i.l;
            if(!vis[v]&&sp[p][v]>sp[p][s]+l)
            {
                sp[p][v]=sp[p][s]+l;
                q.push(make_pair(sp[p][v],v));
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(sp,0x3f,sizeof(sp));
    c=read();
    n=read();
    m=read();
    d=read();
    q=read();
    for(int i=1; i<=m; i++)
    {
        ins[i]=read();
    }
        id=m+1;
        for(int i=1; i<=n; i++)
        {
            int k,las=0,v,t;
            k=read();
            for(int j=1; j<=k; j++)
            {
                v=read();t=read();
                id++;
                adj[v].push_back(node(id,t));
                adj[id].push_back(node(v,t));
                if(j!=1){
                    adj[id].push_back(node(las,0));
                    adj[las].push_back(node(id,0));
                }
                las=id;

            }
        }
        for(int i=1;i<=m;i++){
            dji(i);
        }
        while(q--){
            int u,v;
            u=read();v=read();
            ll ans=sp[u][v]+ins[u]+ins[v];
            cout<<ans<<'\n';
        }
    return 0;
}
