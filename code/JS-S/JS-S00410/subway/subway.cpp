#include<bits/stdc++.h>
using namespace std;
long long c,m,n,d,q,ans;
long long v[500005],dis[500505];
long long ti[500005][3];
struct edge{
    long long v,w;
};
struct cmp{
    bool operator ()(edge A,edge B){
        return A.w>B.w;
    }
};
vector <edge> G[500505];
bool vis[500505];
void dij(int s){
    for (int i=1;i<=n+m;i++) vis[i]=0,dis[i]=LONG_LONG_MAX;
    dis[s]=0;
    priority_queue <edge,vector <edge>,cmp > q;
    q.push({s,0});
    while (!q.empty()){
        int u=q.top().v;
        q.pop();
        //cout<<dis[2]<<' '<<q.top().v<<endl;
        if (vis[u]) continue;
        vis[u]=1;
        for (auto x:G[u]){
            int newv=x.v;
            //if (vis[newv]) continue;
            if (dis[u]+x.w<dis[newv]){
                dis[newv]=dis[u]+x.w;
                //cout<<newv<<"\n";
                if (!vis[newv])q.push({newv,dis[newv]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++) cin>>v[i];
    for (int i=1;i<=n;i++){
        int k;
        cin>>k;
        while (k--){
            long long v,w;
            cin>>v>>w;
            G[m+i].push_back({v,w});
            G[v].push_back({m+i,w});
            if (c==20 || c==21) {
                ti[v][i]=w;
            }
        }
    }
    //cout<<G[2].size()<<endl;
    if (c<=25){
        while (q--){
            int s,t;
            cin>>s>>t;
            dij(s);
            cout<<dis[t]+v[s]+v[t]<<"\n";
        }
    }
    return 0;
}
//wei sha dou shi tu lun ti
//wo zhen fu le
//freopen gunmu
//freopen
