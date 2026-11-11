#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int c,n,m,d,q;
const int N=5e5+5,M=505;
int w[N];
int k[M];
//vector<int> a[2*M],t[2*M];
vector<pii> e[N];
int val[N],im[N],dis[N],im2[N];
struct node
{
    int u,w;
    bool operator>(const node &o)const{
        return w>o.w;
    }
};
void topo(int cur)
{
    queue<int> q;
    for(int i=1;i<=m;i++)
    {
        if(!im[i])
        {
            q.push(i);
            //cout<<i<<" "<<dis[i]<<" "<<dis2[i]<<"\n";
        }
        //cout<<i<<" "<<im[i]<<"\n";
    }
    //cout<<"\n";
    q.push(cur);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(pii p:e[u])
        {
            int v=p.fi,w=p.se;
            if(!--im[v])q.push(v);
            dis[v]=min(dis[v],dis[u]+w+val[u]);
            //dis2[v]=max(dis2[v],dis2[u]+w+val[u]);
        }
    }
}
void dij(int s)
{
    priority_queue<node,vector<node>,greater<node>> q;
    q.push({s,dis[s]});
    while(!q.empty())
    {
        node p=q.top();
        q.pop();
        int u=p.u;
        if(dis[u]<p.w)continue;
        for(pii cur:e[u])
        {
            int v=cur.fi,w=cur.se;
            if(dis[u]+val[u]+w<dis[v])
            {
                dis[v]=dis[u]+w+val[u];
                q.push({v,dis[v]});
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    //memset(dis,0x3f,sizeof(dis));
    //memset(dis2,-0x3f,sizeof(dis2));
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
        //dis[i]=dis2[i]=w[i];
        //e[0].push_back({i,w[i]});
        //im[i]++;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        int lst=i;
        for(int j=1;j<=k[i];j++)
        {
            int aa,tt;
            cin>>aa>>tt;
            if(aa==lst)
            {
                val[aa]=tt;
            }
            else
            {
                e[i].push_back({aa,tt});
                e[aa].push_back({i,tt});
                //im[aa]++;
            }
            //lst=aa;
        }
    }
    memcpy(im2,im,sizeof(im));
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        memset(dis,0x3f,sizeof(dis));
        //memcpy(im,im2,sizeof(im2));
        dis[x]=w[x];
        //cout<<dis[x]<<"\n";
        //topo(x);
        //cout<<dis2[y]-dis[x]+w[y]+w[x]<<"\n";
        //cout<<dis[y]+w[y]<<"\n";
        //if(dis[y]==0x3f3f3f3f3f3f3f3f)cout<<"NO\n";
        //else cout<<dis[y]+w[y]<<"\n";
        dij(x);
        //cout<<dis[y]<<"\n";
        cout<<dis[y]+w[y]<<"\n";
    }
    return 0;
}
