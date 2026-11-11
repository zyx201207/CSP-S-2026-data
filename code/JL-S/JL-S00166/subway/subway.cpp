

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=5e5+10,M=510;

int read(){
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x;
}

struct node{
    int road,val,dt;
};

struct Node{
    long long val;
    int road,dt;
    friend bool operator<(Node x,Node y){
        return x.val>y.val;
    }
};

int c,n,m,d,q,w[N];
unordered_map<int,int> mp[M];
vector<int> dot[N];
vector<pii> G[M];
long long dis[M];
bool vis[M];

void dij(int st,int ed){
    memset(dis,0x3f3f3f3f,sizeof dis);
    memset(vis,0,sizeof vis);
    priority_queue<Node> q;
    for(auto u:dot[st]){
        dis[u]=mp[u][st];
        q.push({dis[u],u,st});
    }
    while(q.size()){
        int u=q.top().road,dd=q.top().dt;
        q.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(pair<int,int> j:G[u]){
            int v=j.first,w=j.second;
            if(dis[v]>dis[u]+1ll*w){
                dis[v]=dis[u]+1ll*w;
                if(mp[v][ed]){
                    dis[v]+=mp[v][ed];
                }
                else{
                    q.push({dis[v],v});
                }
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i=-~i){
        w[i]=read();
    }
    for(int i=1,k;i<=n;i=-~i){
        k=read();
        for(int j=1,a,t;j<=k;j=-~j){
            a=read(),t=read();
            dot[a].push_back(i);
            mp[i][a]=t;
        }
    }
    for(int i=1;i<=m;i=-~i){
        for(auto u:dot[i]){
            for(auto v:dot[i]){
                if(u==v){
                    continue;
                }
                G[u].push_back({v,mp[u][i]+mp[v][i]});
            }
        }
    }
    while(q--){
        int x,y;
        long long ans=1e18;
        scanf("%d%d",&x,&y);
        dij(x,y);
        for(int i=1;i<=n;i=-~i){
            if(mp[i][y]){
                if(mp[i][x]){
                    ans=min(ans,1ll*mp[i][x]+1ll*mp[i][y]);
                }
                else{
                    ans=min(ans,dis[i]);
                }
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

