#include<bits/stdc++.h>
using namespace std;
#define int long long
struct lin{
    int to;
    int w;
};
struct dit{
    int dis;
    int id;
};
bool operator<(dit a,dit b){
    return a.dis>b.dis;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[m+5];
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    if(c>=7&&c<=11){// sp A
        vector<lin> v[m+5];
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            if(k==2){
                int a1,a2,t1,t2;
                cin>>a1>>t1>>a2>>t2;
                v[a1].push_back({a2,t1+t2});
                v[a2].push_back({a1,t1+t2});
            }
        }
        int dis[m+5][m+5];
        for(int i=0;i<m+5;i++){
            for(int j=0;j<m+5;j++){
                dis[i][j]=1LL<<60;
            }
        }
        for(int i=1;i<=m;i++){
            int vis[m+5];
            memset(vis,0,sizeof(vis));
            dis[i][i]=0;
            priority_queue<dit> pq;
            pq.push({0,i});
            while(!pq.empty()){
                dit now=pq.top();
                pq.pop();
                if(vis[now.id]) continue;
                if(dis[i][now.id]<now.dis) continue;
                for(int j=0;j<v[now.id].size();j++){
                    if(dis[i][v[now.id][j].to]>dis[i][now.id]+v[now.id][j].w){
                        dis[i][v[now.id][j].to]=dis[i][now.id]+v[now.id][j].w;
                        pq.push({dis[i][v[now.id][j].to],v[now.id][j].to});
                    }
                }
                vis[now.id]=1;
            }
        }
        for(int i=0;i<q;i++){
            int x,y;
            cin>>x>>y;
            cout<<dis[x][y]+w[x]+w[y]<<"\n";
        }
        return 0;
    }
    else if(c>=12&&c<=19){//sp B
        int T;
        vector<lin> v[n+m+5];
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            for(int j=0;j<k;j++){
                int a,t;
                cin>>a>>t;
                T=t;
                v[a].push_back({m+i,t});
                v[m+i].push_back({a,t});
            }
        }
        for(int i=0;i<q;i++){
            queue<dit> bfs;
            int x,y;
            cin>>x>>y;
            bfs.push({0,x});
            int vis[m+n+5];
            int ans;
            memset(vis,0,sizeof(vis));
            while(!bfs.empty()){
                dit now=bfs.front();
                bfs.pop();
                if(vis[now.id]) continue;
                if(now.id==y){
                    ans=now.dis*T;
                    break;
                }
                vis[now.id]=1;
                for(int j=0;j<v[now.id].size();j++){
                    if(!vis[v[now.id][j].to])
                    bfs.push({now.dis+1,v[now.id][j].to});
                }
            }
            cout<<ans+w[x]+w[y]<<"\n";
        }
        return 0;
    }
    else{
        vector<lin> v[n+m+5];
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            for(int j=0;j<k;j++){
                int a,t;
                cin>>a>>t;
                v[a].push_back({m+i,t});
                v[m+i].push_back({a,t});
            }
        }
        int dis[m+n+5][m+n+5];
        for(int i=0;i<m+n+5;i++){
            for(int j=0;j<m+n+5;j++){
                dis[i][j]=1LL<<60;
            }
        }
        for(int i=1;i<=m;i++){
            int vis[m+n+5];
            memset(vis,0,sizeof(vis));
            dis[i][i]=0;
            priority_queue<dit> pq;
            pq.push({0,i});
            while(!pq.empty()){
                dit now=pq.top();
                pq.pop();
                if(vis[now.id]) continue;
                if(dis[i][now.id]<now.dis) continue;
                for(int j=0;j<v[now.id].size();j++){
                    if(dis[i][v[now.id][j].to]>dis[i][now.id]+v[now.id][j].w){
                        dis[i][v[now.id][j].to]=dis[i][now.id]+v[now.id][j].w;
                        pq.push({dis[i][v[now.id][j].to],v[now.id][j].to});
                    }
                }
                vis[now.id]=1;
            }
        }
        for(int i=0;i<q;i++){
            int x,y;
            cin>>x>>y;
            cout<<dis[x][y]+w[x]+w[y]<<"\n";
        }
        return 0;
    }
    return 0;
}