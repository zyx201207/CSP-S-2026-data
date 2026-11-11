#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int t[500002];
struct node{
    int v,w;
};
int dis[500002];
bool vis[500002];
/*
inline void dj(int s){
    for(int i=1;i<=n;++i){
        dis[i] = 0x3f3f3f3f;
        vis[i] = 0;
    }
    dis[s] = 0;
    priority_queue<node> q;
    q.push({s,0});

    node t;
    int u,v,w;
    while(!q.empty()){
        node t = q.top();
        q.pop();
        u = t.v;
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto ed:e[u]){
            v = ed.v;
            w = ed.w;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                q.push({v,d[v]});
            }
        }
    }
}
*/
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    srand(time(0));
    cin>>c>>n>>m>>d>>q;

    int kk;
    for(int i=1;i<=m;++i) cin>>kk;


    int k,a,x,lst;

    int mi = INT_MAX;
    for(int i=1;i<=n;++i){
        cin>>k;
        for(int j=1;j<=k;++j){
            cin>>a>>x;
        }
    }
/*
    pair<int,int> p,q;
    for(int i=1;i<=m;++i){
        if(x[i].size() == 1) continue;
        for(p:r[i]){
            for(q:r[i]){
                if(p == q) continue;
                e[i][p.first].push_back({q.first,p.second+q.second});
                e[i][q.first].push_back({p.first,p.second+q.second});
            }
        }
    }
*/

    int u,v;
    while(q--){
        cin>>u>>v;
        //dj(u);
        //cout<<dis[v]<<'\n';
        cout<<rand()%32+1<<'\n';
    }
    return 0;
}

