#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int MAXP=1e7+1;
vector<int> g[MAXP];
long long w0[MAXP];
long long w[MAXP];
int p=0,lst=0;
long long dis[MAXP];
const long long INF=1e18;
set<int> st[MAXP];
long long dijkstra(int s,int t)
{
    for(int i=1;i<=MAXP-1;i++) dis[i]=INF;
    dis[s]=0;
    priority_queue<pair<long long,int>> q;
    q.push({0,s});
    while(!q.empty())
    {
        auto x=q.top();
        q.pop();
        int u=x.second;
        for(auto v:g[u])
        {
            if(dis[v]>dis[u]+w[u])
            {
                dis[v]=dis[u]+w[u];
                q.push({dis[v],v});
            }
        }
        //cout<<"u="<<u<<",dis[]=";
        //for(int i=1;i<=p;i++) cout<<dis[i]<<' ';
        //cout<<endl;
    }
    //cout<<dis[t]<<" "<<w[t]<<endl;
    return dis[t]+w[t];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w0[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            p++;
            w[p]=t;
            st[a].insert(p);
            //cout<<"new node "<<p<<",id="<<a<<",with the same id:";
            for(int l=1;l<p;l++)
            {
                if(st[a].count(l))
                {
                    g[p].push_back(l);
                    g[l].push_back(p);
                    //cout<<l<<' ';
                }
            }
            //cout<<",in one line:";
            for(int l=lst+1;l<p;l++)
            {
                g[l].push_back(p);
                g[p].push_back(l);
                //cout<<l<<' ';
            }
            //cout<<endl;
        }
        lst=p;
    }
    for(int i=1;i<=q;i++)
    {
        int u,v;
        cin>>u>>v;
        long long dist=INF;
        for(auto ut=st[u].begin();ut!=st[u].end();ut=next(ut))
            for(auto vt=st[v].begin();vt!=st[v].end();vt=next(vt))
                dist=min(dist,dijkstra(*ut,*vt));
        //cout<<dist<<'\n';
        cout<<dist+w0[u]+w0[v]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
