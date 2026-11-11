#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
struct node{
    int id,dis;
};
vector<node> g[500505];
int dist[500505];
int w[500505];
int dij(int s,int e,int n){
    fill(dist+1,dist+n+1,1e18);
    dist[s]=w[s];
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({w[s],s});
    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();
        if(d>dist[u]) continue;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].id;
            int distt=g[u][i].dis;
            if(d+distt<dist[v]){
                dist[v]=d+distt;
                pq.push({dist[v],v});
            }
        }
    }
    return dist[e]+w[e];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        int k;
        k=read();
        for(int j=1;j<=k;j++){
            int to=read(),ti=read();
            g[m+i].push_back({to,ti});
            g[to].push_back({m+i,ti});
        }
    }
    for(int i=1;i<=q;i++){
        int x=read(),y=read();
        cout<<dij(x,y,n+m)<<"\n";
    }
    return 0;
}
