#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int c,n,m,d,q,k,a,t,st,to,ans,w[500010],dis[500510];
bool vis[500510];
vector<pii> g[500510];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            g[m+i].push_back(make_pair(a,t));
            g[a].push_back(make_pair(m+i,t));
        }
    }
    for(int i=1;i<=q;i++){
        cin>>st>>to;
        memset(vis,0,sizeof(vis));
        memset(dis,0x3f,sizeof(dis));
        priority_queue<pii,vector<pii>,greater<pii> > q;
        q.push(make_pair(0,st));
        dis[st]=0;
        while(!q.empty()){
            pii tp=q.top();
            int u=tp.second;
            q.pop();
            if(u==to)break;
            if(vis[u])continue;
            vis[u]=1;
            for(int i=0;i<g[u].size();i++){
                int v=g[u][i].first,ww=g[u][i].second;
                if(dis[u]+ww<dis[v]){
                    dis[v]=dis[u]+ww;
                    q.push(make_pair(dis[v],v));
                }
            }
        }
        cout<<dis[to]+w[st]+w[to]<<'\n';
    }
    return 0;
}
