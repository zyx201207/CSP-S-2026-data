#include<bits/stdc++.h>
using namespace std;
const long long N=5e6+10;
long long c,n,m,d,q,T=0,cnt;
long long ww[N],dis[N];
bool vis[N];
struct Node{
    int u,w;
};
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >pq;
vector<pair<long long,long long> >v[N];
vector<long long>tmp[N];
long long dij(long long x,long long y){
    pq.push({0,x});
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        long long w=it.first,u=it.second;
        if(w>dis[u])continue;
        dis[u]=w;
        for(auto p:v[u]){
            long long to=p.first,cost=p.second;
            if(dis[u]+cost<dis[to]){
                dis[to]=dis[u]+cost;
                pq.push({dis[to],to});
            }
        }
    }
    return dis[y];
}
void solve(){
    for(long long i=1;i<=m;i++){
        cin>>ww[i];
    }
    cnt=m;
    for(long long i=1;i<=n;i++){
        long long k;
        cin>>k;
        int u,w,U,W;
        cin>>u>>w>>U>>W;
        if(k==1)continue;
        v[u].push_back({U,w+W});
        v[U].push_back({u,w+W});
    }
    while(q--){
        long long x,y;
        cin>>x>>y;
        for(long long i=1;i<=cnt;i++)dis[i]=2e9;
        long long ans=ww[x]+ww[y];
        if(tmp[x].size()!=0){
            cout<<ans+tmp[x][y]<<endl;
            continue;
        }
        ans+=dij(x,y);
        tmp[x].push_back(0);
        for(int i=1;i<=cnt;i++){
            tmp[x].push_back(dis[i]);
        }
        cout<<ans<<endl;
    }
}
long long bfs(long long x,long long y){
    queue<Node>q;
    q.push({x,0});
    vis[x]=1;
    while(!q.empty()){
        Node f=q.front();
        q.pop();
        int u=f.u,w=f.w;
        if(u==y)return w;
        for(auto p:v[u]){
            int to=p.first;
            if(!vis[to]){
                vis[to]=1;
                q.push({to,w+1});
            }
        }
    }
}
void solveB(){
    while(q--){
        long long x,y;
        cin>>x>>y;
        for(int i=1;i<=cnt;i++)vis[i]=0;
        long long ans=ww[x]+ww[y];
        ans+=bfs(x,y)*T;
        cout<<ans<<endl;
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    if(c>=7&&c<=11){
        solve();
        return 0;
    }
    for(long long i=1;i<=m;i++){
        cin>>ww[i];
    }
    cnt=m;
    for(long long i=1;i<=n;i++){
        long long k;
        cin>>k;
        if(k==1)continue;
        cnt++;
        for(long long j=1;j<=k;j++){
            long long u,w;
            cin>>u>>w;
            T=w;
            v[cnt].push_back({u,w});
            v[u].push_back({cnt,w});
        }
    }
    if(c>=12&&c<=19){
        solveB();
        return 0;
    }
    while(q--){
        long long x,y;
        cin>>x>>y;
        for(long long i=1;i<=cnt;i++)dis[i]=2e9;
        long long ans=ww[x]+ww[y];
        if(tmp[x].size()!=0){
            cout<<ans+tmp[x][y]<<endl;
            continue;
        }
        ans+=dij(x,y);
        tmp[x].push_back(0);
        for(int i=1;i<=cnt;i++){
            tmp[x].push_back(dis[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
