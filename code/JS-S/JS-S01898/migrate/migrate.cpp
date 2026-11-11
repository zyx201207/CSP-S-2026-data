#include<bits/stdc++.h>
using namespace std;
int c,T,n,dix;
int dis[200002];
int cnt[200002];
struct node{
    int v,w;
    bool operator<(const node &rhs)const{
        return w > rhs.w;
    }
};
vector<node> e[200002];
vector<node> g[200002];
bool vis[200002];
int d[200002];
inline void dj(int s){
    for(int i=1;i<=n;++i){
        d[i] = 0x3f3f3f3f;
        vis[i] = 0;
    }
    d[s] = 0;
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
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({v,d[v]});
            }
        }
    }
}
inline void dj2(int s){
    for(int i=1;i<=n;++i){
        d[i] = 0x3f3f3f3f;
        vis[i] = 0;
        cnt[i] = 0;
    }
    d[s] = 0;
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
        for(auto ed:g[u]){
            v = ed.v;
            w = ed.w;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                cnt[v] = 1;
                q.push({v,d[v]});
            }
            else if(d[v] == d[u]+w){
                ++cnt[v];
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>c>>T;
    while(T--){
        cin>>n>>dix;
        for(int i=1;i<=n;++i) e[i].clear();
        for(int i=1;i<=n;++i) cin>>dis[i];

        int x;
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                x = abs(dis[i]-dis[j]);
                if(x <= dix){
                    e[i].push_back({j,x});
                    e[j].push_back({i,x});
                    //cout<<"edge:"<<i<<' '<<j<<'\n';
                }
            }
        }
        for(int i=1;i<=n;++i){
            dj(i);
            for(int j=i+1;j<=n;++j){
                //if(d[j] == 1061109567) continue;
                g[i].push_back({j,d[j]-1});
                g[j].push_back({i,d[j]-1});
                //cout<<"gdge:"<<i<<' '<<j<<' '<<d[j]-1<<'\n';
            }
        }
        int ans = 0;
        for(int i=1;i<=n;++i){
            dj2(i);
            for(int j=i+1;j<=n;++j){
                if(cnt[j] == 2) ++ans;
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}
/*
0 1
4 2
1 2 3 4
*/

