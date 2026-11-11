/*give up
    it's unlucky that my phone has became a black brick last night while normal-using
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[50005],k[505],a[505][50005],t[505][50005],dis[50005][2];
bool vis[50005];
struct edge
{
    ll to,ln;
};
vector<edge> g[50005];
void add_edge(ll u,ll v,ll ln)
{
    g[u].push_back({v,ln});
    g[v].push_back({u,ln});
}
struct sv
{
    ll to,tot,ln;
    bool operator < (const sv &s) const
    {
        return s.tot<tot;
    }
};
ll dj(ll xr,ll yr)
{
    priority_queue<sv> q;
    for(int i=1;i<=n;i++)
    {
        dis[i][0]=INT_MAX;
        dis[i][1]=INT_MAX;
    }
    dis[xr][0]=0;
    int stl=g[xr][0].ln;

    q.push({xr,0,stl});
    while(!q.empty())
    {
        sv tmp=q.top();
        ll u=tmp.to;
        //cout<<"st:"<<u<<" dis:"<<tmp.tot<<" line:"<<tmp.ln<<endl;
        q.pop();
        if(vis[u])
            continue;
        vis[u]=1;
        ll hc=0;
        for(int i=0;i<g[u].size();i++)
        {
            ll v=g[u][i].to,line=tmp.ln;
            if(!vis[v])
            {
                if(g[u][i].ln!=tmp.ln)
                {
                    line=g[u][i].ln;
                    hc+=t[u][v]+t[u][u];
                    dis[v][1]=tmp.tot+hc;

                    cout<<dis[v]<<endl;
                }
                dis[v][0]=tmp.tot;
                q.push({v,dis[v][1],line});
                q.push({v,dis[v][0],tmp.ln});
            }
        }

    }
    return t[xr][xr]+w[xr]+w[yr]+min(dis[yr][0],dis[yr][1]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];

            if(j!=1)
                add_edge(a[i][j],a[i][j-1],i);

        }
    }
    //for(int p=1;p<=m;p++)
        //cout<<p<<":"<<g[p].size()<<endl;
    while(q--)
    {
        ll xr,yr;
        memset(vis,0,sizeof(vis));

        cin>>xr>>yr;
        cout<<dj(xr,yr)<<endl;
        //cout<<endl;
    }
    return 0;
}
