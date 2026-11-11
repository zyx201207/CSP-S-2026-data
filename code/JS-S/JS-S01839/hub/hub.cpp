#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
#define st string
#define db double
#define ch char
#define bo bool
#define s2 505
#define s3 5005
#define s4 50005
#define s5 500005
#define s6 1000005
#define s7 10000005
using namespace std;
int c,t,n,k,vis[s2],dis[s2];
vector<int> g[s2],v;
void dfs(int u,int fa,int f){
    vis[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!vis[v]&&(f&(1<<v))){
            dfs(v,u,f);
        }
    }
    return ;
}
bool check(int f){
    memset(vis,0,sizeof(vis));
    int k=0;
    for(int i=1;i<=n;i++){
        if((f&(1<<i))&&!vis[i]){
            dfs(i,-1,f);
            k++;
            if(k>2) return 0;
        }
    }
    return 1;
}
struct node{
    int v,d;
    friend bool operator < (node n1,node n2){
        return n1.d>n2.d;
    }
};
void dijkstra(int s){
    bool viss[s2]={0};
    dis[s]=0;
    memset(dis,0x7f,sizeof(dis));
    priority_queue<node> pq;
    pq.push({s,0});
    while(!pq.empty()){
        node x=pq.top();
        pq.pop();
        int u=x.v;
        int d=x.d;
        if(viss[u]) continue;
        viss[u]=1;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                pq.push({v,dis[v]});
            }
        }
    }
    return ;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int minn=0x7f7f7f7f7f7f7f;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int f=1;f<(1<<n);f++){
            int sum=0;
            for(int i=1;i<=n;i++){
                if(f&(1<<i)){
                    sum++;
                }
            }
            if(sum!=k) continue;
            if(check(f)){
                v.push_back(f);
            }
        }
        for(int c=0;c<v.size();c++){
            int maxx=0;
            for(int i=1;i<=n;i++){
                if(v[c]&(1<<i)){
                    dijkstra(i);
                    for(int j=1;j<=n;j++){
                        if(v[c]&(1<<j)) continue;
                        maxx=max(maxx,dis[j]);
                    }
                }
            }
            minn=min(minn,maxx);
        }
        cout<<minn<<'\n';
    }
    return 0;
}
