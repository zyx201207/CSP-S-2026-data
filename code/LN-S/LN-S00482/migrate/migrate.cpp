#include <bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d,x[5005],dis[5005],ans;
bool vis[5005];
void dij(int s,int e,vector<pair<int,int> > v[]){
    priority_queue<pair<int,int> ,vector<pair<int,int> > , greater<int> > pq;
    for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f;
    for(int i=1;i<=n;i++) vis[i]=0;
    pq.push({0,s});
    while(!pq.empty()){
        auto tmp=pq.top();
        pq.pop();
        int u=tmp.second,di=tmp.first;
        if(vis[u]) continue;
        vis[u]=1;
        if(u==e) return;
        for(int i=0;i<v[u].size();i++){
            int to=v[u][i].first,w=v[u][i].second;
            if(di+w<dis[to]){
                dis[to]=di+w;
                pq.push({dis[to],to});
            }
        }
    }
}
long long bfs(int a,int b,vector<pair<int,int> > v[]){
    long long cnt=0;
    queue<pair<int,int> > q;
    q.push({a,0});
    while(!q.empty()){
        int x=q.front().first,sum=q.front().second;
        q.pop();
        if(x==b&&sum==dis[b]){
            cnt++;
            continue;
        }
        for(int i=0;i<v[x].size();i++)
            q.push({v[x][i].first,sum+v[x][i].second});
    }
    return cnt;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        vector<pair<int,int> > g[5005];
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(x[j]-x[i]<=d)
                    g[i].push_back({j,x[j]-x[i]});
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                dij(i,j,g);
                long long route=bfs(i,j,g);
                cout<<route<<" ";
                if(route==2)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
