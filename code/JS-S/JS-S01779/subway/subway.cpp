#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=5e5;
const int inf=0x3f3f3f3f;
int c,n,m,d,q,ww[N+5],dis[N+505],vis[N+505],cnt[N+505],s[N+5],de[N+5],o;
vector<pii> g[N+505];
map<pii,int> di;
bool f=false;
bool tf=true,fi=true;
void dij(int s){
    for(int i=1;i<=n+m;i++){
        di[{s,i}]=inf;
        vis[i]=0;
    }
    di[{s,s}]=0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,s});
    while(pq.size()){
        int u=pq.top().second,dd=pq.top().first;
        pq.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].first,w=g[u][i].second;
            if(di[{s,v}]>di[{s,u}]+w){
                di[{s,v}]=di[{s,u}]+w;
                pq.push({di[{s,v}],v});
            }
        }
    }
}
void dfs(int u,int fa){
    for(int i=0;i<g[u].size();i++){
        if(de[g[u][i].first]){
            continue;
        }
        de[g[u][i].first]=de[u]+1;
        if(g[u][i].first!=fa){
            dfs(g[u][i].first,u);
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> ww[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        for(int j=1;j<=k;j++){
            int u,v;
            cin >> u >> v;
            if(fi){
                o=v;
                fi=false;
            }
            if(v!=o){
                tf=false;
            }
            g[m+i].push_back({u,v});
            g[u].push_back({m+i,v});
        }
    }
    if(tf){
        dfs(1,0);
        for(int i=1;i<=q;i++){
            int x,y;
            cin >> x >> y;
            cout << abs(de[x]-de[y])*o << "\n";
        }
        return 0;
    }
    for(int i=1;i<=n+m;i++){
        g[0].push_back({i,0});
        dis[i]=inf;
    }
    queue<int> qq;
    qq.push(0);
    dis[0]=0,vis[0]=1,cnt[0]=0;
    while(qq.size()){
        int u=qq.front();
        qq.pop();
        vis[u]=0;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].first,w=g[u][i].second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n+m){
                    f=true;
                    break;
                }
                if(!vis[v]){
                    qq.push(v);
                    vis[v]=1;
                }
            }
        }
        if(f){
            break;
        }
    }
    for(int i=1;i<=n+m;i++){
        for(int j=0;j<g[i].size();j++){
            int v=g[i][j].first,w=g[i][j].second;
            g[i][j].second=w+dis[i]-dis[v];
        }
    }

    for(int i=1;i<=q;i++){
        int x,y;
        cin >> x >> y;
        if(s[x]){
            cout << di[{x,y}]-dis[x]+dis[y]+ww[x]+ww[y] << "\n";
        }else if(s[y]){
            cout << di[{y,x}]-dis[y]+dis[x]+ww[x]+ww[y] << "\n";
        }else{
            dij(x);
            s[x]=1;
            cout << di[{x,y}]-dis[x]+dis[y]+ww[x]+ww[y] << "\n";
        }
    }
    return 0;
}