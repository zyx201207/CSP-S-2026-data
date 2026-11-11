#include <bits/stdc++.h>
#define ll long long
#define maxn 501
#define maxm 500002
using namespace std;
bool vis[maxm];
ll c,n,m,d,q,w[maxm],dis[maxm];
struct node{
    ll u,v,w;
};
struct kr{
    ll v,w;
    bool operator < (const kr&oth)const{
        return w>oth.w;
    }
};
vector<node> g[maxm];
priority_queue<kr> pq;
void choose(ll x)
{
    vis[x]=1;
    for(node i:g[x]){
        ll u=i.u,v=i.v,w=i.w;
        if(dis[u]+w<dis[v]){
            dis[v]=dis[u]+w;
            pq.push({v,dis[v]});
        }
    }
}
void query(ll s)
{
    for(int i=1;i<=m;i++) dis[i]=INT_MAX-1000;
    dis[s]=0;
    pq.push({s,0});
    choose(s);
    while(pq.size())
    {
        kr tmp=pq.top();
        pq.pop();
        ll v=tmp.v,w=tmp.w;
        if(!vis[v]) choose(v);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        ll k,x,t;
        cin>>k;
        for(int i=1;i<=k;i++){
            ll a,b;
            cin>>a>>b;
            if(i<2){
                g[0].push_back({0,a,b});
                x=a,t=b;
            }
            else{
                g[x].push_back({x,a,b});
                g[a].push_back({a,x,b});
                x=a,t=b;
            }
        }
    }
    query(0);
    while(q--){
        ll x,y;
        cin>>x>>y;
        cout<<dis[y]+w[x]+w[y]<<"\n";
    }
    return 0;
}
