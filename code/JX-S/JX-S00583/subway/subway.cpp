#include<bits/stdc++.h>
using namespace std;
struct A{
    int cnt,num;
}c[514514];
int C,n,m,f,q,w[514514],k,a[514514],t[514514],id,x[514514],y[514514],p[514514];
long long d1[514514][210],d2[514514];
vector<pair<int,int>>G[1114514];
bool vis[514514],fl[514514];
bool cmp(A p,A q){
    if(p.cnt-q.cnt) return p.cnt>q.cnt;
    return p.num>q.num;
}
void dij1(int s,int i){
    priority_queue<pair<long long,int>>q;
    memset(vis,0,sizeof(vis));
    q.push({0,s});d1[s][i]=0;
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v,w]:G[u]){
            if(d1[v][i]>d1[u][i]+w) d1[v][i]=d1[u][i]+w,q.push({-d1[v][i],v});
        }
    }
    return ;
}
void dij2(int s){
    priority_queue<pair<long long,int>>q;
    memset(vis,0,sizeof(vis));
    memset(d2,0x3f,sizeof(d2));
    q.push({0,s});d2[s]=0;
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v,w]:G[u]){
            if(d2[v]>d2[u]+w) d2[v]=d2[u]+w,q.push({-d2[v],v});
        }
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>f>>q;
    memset(d1,0x3f,sizeof(d1));
    for(int i=1;i<=m;i++) cin>>w[i],G[i].push_back({i+m,w[i]}),G[i+m].push_back({i,w[i]}),c[i].num=i;
    id=2*m;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
            G[++id].push_back({a[j]+m,t[j]});
            G[a[j]+m].push_back({id,t[j]});
            if(j!=1) G[id].push_back({id-1,0}),G[id-1].push_back({id,0});
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        c[x[i]].cnt++;c[y[i]].cnt++;
    }
    sort(c+1,c+m+1,cmp);
    for(int i=1;i<=205;i++){
        p[c[i].num]=i;
        if(!p[i]) break;
        dij1(c[i].num,i);
        fl[c[i].num]=1;
    }
    for(int i=1;i<=q;i++){
        if(fl[y[i]]) cout<<d1[x[i]][p[y[i]]]<<'\n';
        else if(fl[x[i]]) cout<<d1[y[i]][p[x[i]]]<<'\n';
        else {
            dij2(x[i]);
            cout<<d2[y[i]]<<'\n';
        }
    }
    return 0;
}
