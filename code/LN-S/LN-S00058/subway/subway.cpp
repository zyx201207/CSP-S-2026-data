#include<bits/stdc++.h>
using namespace std;
const int N = 55,M = 305;
int cc,n,m,dd,ans,q,st,ed,k[M],w[N],vis[N][M];
pair<int,int>a[N][M];
vector<pair<int,int> >t[M];
void dfs(int u,int ln,int nw){
    if(u==ed){
        ans = min(ans,nw);
        return;
    }
    for(int i = 1;i<=k[ln];i++){
        int v = a[ln][i].first,ww = a[ln][i].second;
        if(v==u) continue;
        if(vis[v][ln]) continue;
        vis[v][ln] = 1;
        dfs(v,ln,nw+ww);
        vis[v][ln] = 0;
    }
    for(auto p:t[u]){
        int v = p.first,ww = p.second;
        if(vis[u][v]) continue;
        vis[u][v] = 1;
        dfs(u,v,nw+ww);
        vis[u][v] = 0;
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>cc>>n>>m>>dd>>q;
    for(int i = 1;i<=m;i++) cin>>w[i];
    for(int i = 1;i<=n;i++){
        cin>>k[i];
        for(int j = 1,u,v;j<=k[i];j++){
            cin>>u>>v;
            a[i][j] = {u,v};
            t[u].push_back({i,v});
        }
    }
    while(q--){
        cin>>st>>ed;
        for(auto p:t[st]){
            ans = INT_MAX;
            memset(vis,0,sizeof vis);
            vis[st][p.first] = 1;
            dfs(st,p.first,p.second);
        }
        cout<<w[st]+ans+w[ed]<<'\n';
    }
    return 0;
}
/*
g++ subway.cpp -o subway -std=c++14 -O2 -Wall -fsanitize=address,undefined

#include<bits/stdc++.h>
using namespace std;
const int N = 55,M = 305,W = 5e6+5;
int cc,n,m,dd,ans,Q,st,ed,s[N],k[M],w[N],dis[W],vis[W];
vector<pair<int,int> >a[W];
vector<pair<int,int> >t[M];
pair<int,int>e[N][M];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int main(){
    cin>>cc>>n>>m>>dd>>Q;
    for(int i = 1;i<=m;i++) cin>>w[i];
    for(int i = 1;i<=n;i++){
        cin>>k[i];
        s[i] = s[i-1]+k[i-1];
        for(int j = 1,u,v;j<=k[i];j++){
            cin>>u>>v;
            e[i][j] = {u,v};
            t[u].push_back({i,v});
        }
        for(int j = 1;j<=k[i];j++){
            for(int r = 1;r<=k[i];r++){
                if(j==r) continue;
                a[e[i][j].first].push_back({e[i][r].second,e[i][r].first});
                a[e[i][r].first].push_back({e[i][r].second,e[i][j].first});
            }
        }
    }
    for(int i = 1;i<=m;i++){
        for(auto p:t[i]){
            for(auto r:t[i]){
                if(p.first==r.first&&p.second==r.second) continue;
                int l1 = p.first,w1 = p.second,l2 = r.first,w2 = r.second;
                a[s[l1]+i].push_back({w2,s[l2]+i});
                a[s[l2]+i].push_back({w1,s[l1]+i});
            }
        }
    }
    while(Q--){
        cin>>st>>ed;
        for(auto p:t[st]){
            int l = p.first,ww = p.second;
            memset(vis,0,sizeof vis);
            memset(dis,0x3f,sizeof dis);
            dis[s[l]+st] = ww;
            q.push({ww,s[l]+st});
            while(!q.empty()){
                auto p = q.top(); q.pop();
                int u = p.second;
                if(vis[u]) continue;
                vis[u] = 1;
                for(auto r:a[u]){
                    int nw = r.first,v = r.second;
                    if(dis[u]+nw<dis[v]){
                        dis[v] = dis[u]+nw;
                        q.push({dis[v],v});
                    }
                }
            }
        }
        for(auto p:t[ed]) ans = min(ans,dis[s[p.first]+ed]);
        cout<<w[st]+ans+w[ed]<<'\n';
    }
    return 0;
}

to my dead dijkstra
i didn't use it well :(
*/