#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=505;
const int M=5e5+5;

struct edge{
    int v;
    ll w;
};

struct node{
    int id;
    ll val;
    bool operator<(const node& other)const
    {
        return val>other.val;
    }
};

int c,n,m,d,q;
ll t[N],dis[N+N+N][N+N+N];
vector<edge> g[M+N];

void solve1(){
    for(int k=1;k<=n+m;k++){
        for(int i=1;i<=n+m;i++){
            for(int j=1;j<=n+m;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

    for(int r=1;r<=q;r++){
        int st,ed;
        cin>>st>>ed;
        cout<<t[st]+t[ed]+dis[st][ed]<<"\n";
    }
}

ll dist[M+N];
int vis[M+N];

void solve2(){
    for(int r=1;r<=q;r++){
        int st,ed;
        cin>>st>>ed;
        priority_queue<node> q;
        memset(dist,0x3f,sizeof(dist));
        memset(vis,0,sizeof(vis));
        dist[st]=0;
        q.push((node){st,dist[st]});
        while(!q.empty()){
            int u=q.top().id;
            ll disw=q.top().val;
            q.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(int i=0;i<g[u].size();i++){
                int v=g[u][i].v;
                ll w=g[u][i].w;
                if(dist[v]>disw+w){
                    dist[v]=disw+w;
                    q.push((node){v,dist[v]});
                }
            }
        }
        cout<<t[st]+t[ed]+dist[ed]<<"\n";
    }
}

void solve3(){
    for(int r=1;r<=q;r++){
        int st,ed;
        cin>>st>>ed;
        cout<<t[st]+t[ed]+dis[m+1][st]+dis[m+1][ed]<<"\n";
    }
}

int fa[M];

void solve4(){
    ll minn=1e18;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int v;ll w;
            cin>>v>>w;
            dis[i+m][v]=w;
            dis[v][i+m]=w;
            if(fa[v]){
                minn=min(minn,dis[fa[v]+m][v]+dis[i+m][v]);
                fa[v]=3;
            }else{
                fa[v]=i;
            }
        }
    }
    for(int r=1;r<=q;r++){
        int st,ed;
        cin>>st>>ed;
        if(fa[st]==fa[ed]&&fa[st]==3){
            cout<<t[st]+t[ed]+min(dis[1+m][st]+dis[1+m][ed],dis[2+m][st]+dis[2+m][ed])<<"\n";
        }else if(fa[st]==fa[ed]){
            cout<<t[st]+t[ed]+dis[fa[st]+m][st]+dis[fa[ed]+m][ed]<<"\n";
        }else if(fa[st]==3){
            cout<<t[st]+t[ed]+dis[fa[ed]+m][st]+dis[fa[ed]+m][ed]<<"\n";
        }else if(fa[ed]==3){
            cout<<t[st]+t[ed]+dis[fa[st]+m][st]+dis[fa[st]+m][ed]<<"\n";
        }else{
            cout<<t[st]+t[ed]+dis[fa[st]+m][st]+dis[fa[ed]+m][ed]+minn<<"\n";
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++) cin>>t[i];

    if(n==2){
        solve4();
        return 0;
    }

    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int v;ll w;
            cin>>v>>w;
            g[i+m].push_back((edge){v,w});
            g[v].push_back((edge){i+m,w});
            dis[i+m][v]=w;
            dis[v][i+m]=w;
        }
    }

    if(n==1){
        solve3();
        return 0;
    }
    
    if(n<=200&&m<=400){
        solve1();
        return 0;
    }

    if(q<=2000){
        solve2();
        return 0;
    }

    solve1();

    return 0;
}

/*

g++ -o subway subway.cpp -std=c++14 -O2 -static

./subway <subway5.in >subway5.out

diff subway5.out subway5.ans

*/