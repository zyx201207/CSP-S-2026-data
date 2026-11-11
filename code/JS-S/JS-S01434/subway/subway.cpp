#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,int>
int c,n,m,d,q;
ll w[500005];
struct node{
    int v;ll w;
};
ll dis[2005][2005];
int vis[2005];
vector<node>mp[500005];
void di(int i){
    priority_queue<pii,vector<pii>,greater<pii>>q;
    memset(vis,0,sizeof(vis));
    dis[i][i]=0;
    q.push({0,i});
    while(!q.empty()){
        int u=q.top().second;
        vis[u]=1;q.pop();
        for(node e:mp[u]){
            int v=e.v,w=e.w;
            if(vis[v])continue;
            if(dis[i][v]>dis[i][u]+w){
                dis[i][v]=dis[i][u]+w;
                q.push({dis[i][v],v});
            }
        }
    }
}
ll dis2[500505];
int vis2[500505];
void di2(int i){
    priority_queue<pii,vector<pii>,greater<pii>>q;
    for(int j=1;j<=n+m;++j)vis2[j]=0,dis2[j]=0x3f3f3f3f3f3f3f3f;
    dis2[i]=0;
    q.push({0,i});
    while(!q.empty()){
        int u=q.top().second;
        vis2[u]=1;q.pop();
        for(node e:mp[u]){
            int v=e.v,w=e.w;
            if(vis2[v])continue;
            if(dis2[v]>dis2[u]+w){
                dis2[v]=dis2[u]+w;
                q.push({dis2[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        int k;cin>>k;
        for(int j=1;j<=k;++j){
            int a;ll t;
            cin>>a>>t;
            mp[a].push_back({m+i,t});
            mp[m+i].push_back({a,t});
        }
    }
    if(c<=11){
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=m;++i){
            di(i);
        }
        while(q--){
            int x,y;cin>>x>>y;
            cout<<w[x]+w[y]+dis[x][y]<<endl;
        }
    }
    else {
        while(q--){
            int x,y;cin>>x>>y;
            di2(x);
            cout<<w[x]+w[y]+dis2[y]<<endl;
        }
    }
    return 0;
}