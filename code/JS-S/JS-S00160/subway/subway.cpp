#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=5e5+5;
vector<pii> g[N+500*21];
long long dis[N+500*21];
int c,n,m,d,q,last[N];
//long long ans;
inline int read(){
    int x=0,f=1;
    char ch=getchar_unlocked();
    while(ch<'0' || ch>'9'){
        if(ch==EOF) return 0;
        if(ch=='-') f=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar_unlocked();
        if(ch==EOF) break;
    }
    return x*f;
}
void Dijkstra(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    priority_queue<pii> q;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        for(auto it:g[u]){
            int v=it.first,w=it.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++) last[i]=read();
    int idx=m;
    for(int i=1;i<=n;i++){
        int k;k=read();
        idx++;
        while(k--){
            int v,w;
            v=read();w=read();
            g[idx].push_back({v,w});
            g[v].push_back({idx,w});
        }
    }/*
    for(int i=1;i<=idx;i++){
        for(auto [v,w]:g[i]) cout<<i<<"->"<<v<<" "<<w<<"\n";
    }
    for(int i=1;i<=m;i++){
        g[0].push_back({i,last[i]});
        g[i].push_back({0,last[i]});
    }
    Dijkstra(0);*/
    while(q--){
        int s,e;
        s=read();e=read();
        Dijkstra(s);
        printf("%lld\n",dis[e]+(long long)(last[s]+last[e]));
    }
    return 0;
}
