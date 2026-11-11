#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=1e6+5;
const ll inf=1e18;
ll W[M];
vector<ll>a[N],t[N],id[M];
ll tot,k[N],sum[N];
struct node{
    int u;
    ll w;
    bool operator<(const node PK)const{
        return PK.w<w;
    }
};
ll dis[M];
bool vis[M];
vector<node>g[M];
ll dijkstra(int s,int t){
    ll mins=inf;
    for(int u:id[s]){
        priority_queue<node>q;
        q.push({u,0});
        for(int i=1;i<=tot;i++)dis[i]=inf;
        fill(vis+1,vis+tot+1,0);
        dis[u]=0;
        while(!q.empty()){
            int s=q.top().u;
            q.pop();
            if(vis[s])continue;
            vis[s]=1;
            for(auto it:g[s]){
                int v=it.u;
                if(dis[v]>dis[s]+it.w){
                    dis[v]=dis[s]+it.w;
                    q.push({v,dis[v]});
                }
            }
        }
        for(int po:id[t])mins=min(mins,dis[po]);
    }
    return mins;
}
struct Pair{
    int a,b;
};
vector<Pair>lis[M];
/*
ll g[1005][1005];
ll calc(int s,int t){
    ll mins=inf;
    for(int u:id[s]){
        for(int v:id[t]){
            cout<<u<<" "<<v<<endl;
            if(g[u][v]<mins)mins=g[u][v];
        }
    }
    return mins;
}
*/
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>W[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        sum[i]=sum[i-1]+k[i];
        for(int j=1;j<=k[i];j++){
            int u,w;
            cin>>u>>w;
            a[i].push_back(u);
            t[i].push_back(w);
            lis[u].push_back({i,j});
            id[u].push_back(++tot);
        }
    }
    int idx=0,edge=0;
    for(int i=1;i<=n;i++){
        for(int u:a[i]){
            ++idx;
            if(idx!=sum[i]){
                g[idx+tot].push_back({idx+tot+1,0});
                g[idx+tot+1].push_back({idx+tot,0});
                edge++;
            }
            for(auto it:lis[u]){
                int a=it.a,b=it.b;
                //g[tot].push_back({sum[a-1]+b,t[a][b-1]});
                //cout<<tot<<" "<<sum[a-1]+b<<" "<<t[a][b-1]<<endl;
               // g[idx][sum[a-1]+b+tot]=g[sum[a-1]+b+tot][idx]=t[a][b-1];
                g[idx].push_back({sum[a-1]+b+tot,t[a][b-1]});
                g[sum[a-1]+b+tot].push_back({idx,t[a][b-1]});
                edge++;

            }
        }
        //cout<<endl;
    }
    tot*=2;
    /*
    cout<<tot<<" "<<edge<<endl;
    for(int i=1;i<=tot;i++){
        for(int j=1;j<=tot;j++)cout<<g[i][j]<<" ";
        cout<<endl;
    }
    for(int i=1;i<=tot;i++){
        for(int j=1;j<=tot;j++){
            for(int k=1;k<=tot;k++){
                if(g[i][j]>g[i][k]+g[k][j])g[i][j]=g[i][k]+g[k][j];
            }
        }
    }
    */
    //cout<<endl;
    while(q--){
        int s,t;
        cin>>s>>t;
        cout<<W[s]+W[t]+dijkstra(s,t)<<endl;
        //cout<<W[s]+W[t]+calc(s,t)<<endl;
    }
    return 0;
}
