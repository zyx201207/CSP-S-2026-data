#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2005;
const int M=4e4+10;
ll c,n,m,d,p,w[M],dis[N][N],dis1[M];
bool vis[M];
struct node{
    int to;
    ll w;
    bool operator < (const node& other) const{
        return w > other.w;
    }
};
vector<node> v[M];
priority_queue<node> q;
void diji(ll u){
    for(int i=1;i<=n+m;i++){
        dis[u][i]=INT_MAX;
        vis[i]=0;
    }
    dis[u][u]=0;
    q.push({u,0});
    while(!q.empty()){
        int x=q.top().to;
        q.pop();
        if(vis[x]==1)continue;
        vis[x]=1;
        for(int i=0;i<v[x].size();i++){
            int to=v[x][i].to;
            ll w=v[x][i].w;
            if(dis[u][to]>dis[u][x]+w){
                dis[u][to]=dis[u][x]+w;
                q.push({to,dis[u][to]});
            }
        }
    }
}
void diji1(ll u){
    for(int i=1;i<=n+m;i++){
        dis1[i]=INT_MAX;
        vis[i]=0;
    }
    dis1[u]=0;
    q.push({u,0});
    while(!q.empty()){
        int x=q.top().to;
        q.pop();
        if(vis[x]==1)continue;
        vis[x]=1;
        for(int i=0;i<v[x].size();i++){
            int to=v[x][i].to;
            ll w=v[x][i].w;
            if(dis1[to]>dis1[x]+w){
                dis1[to]=dis1[x]+w;
                q.push({to,dis1[to]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    if(m<=1500){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            ll k;
            cin>>k;
            for(int j=1;j<=k;j++){
                int a;
                ll t;
                cin>>a>>t;
                v[a].push_back({m+i,t});
                v[m+i].push_back({a,t});
            }
        }
        for(ll i=1;i<=m;i++){
            diji(i);
        }
        for(int i=1;i<=p;i++){
            int x,y;
            cin>>x>>y;
            cout<<dis[x][y]+w[x]+w[y]<<endl;
        }
        return 0;
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        ll k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a;
            ll t;
            cin>>a>>t;
            v[a].push_back({m+i,t});
            v[m+i].push_back({a,t});
        }
    }
    for(int i=1;i<=p;i++){
        int x,y;
        cin>>x>>y;
        diji1(x);
        cout<<dis1[y]+w[x]+w[y]<<endl;
    }
    return 0;
}
