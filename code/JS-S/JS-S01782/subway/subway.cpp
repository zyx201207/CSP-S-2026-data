#include<bits/stdc++.h>
#define int long long
#define il inline
using namespace std;
const int N=2e4+10;
const int M=505;
const int DFF=0x3f3f3f3f3f3f3f3f;
il int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+ch-48;
        ch=getchar();
    }
    return x*f;
}
int nbr,T;
int w[N];
int len[N];
int d;
bool v[N][2];
int n,m;
struct node{
    int v,w;
    il bool operator <(const node& o)const{
        return w>o.w;
    }
};
vector<node> g[M];
vector<int> s[N];
il int dij(int x,int y){
    bool vis[N];
    int dist[N];
    for(int i=1;i<=n;i++){
        dist[i]=DFF;
        vis[i]=0;
    }
    dist[x]=0;
    priority_queue<node> q;
    q.push({x,0});
    while(q.size()){
        int u=q.top().v;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].v,w=g[u][i].w;
            if(!vis[v] && dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                q.push({v,dist[v]});
            }
        }
    }
    return dist[y];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    nbr=read(),n=read(),m=read(),d=read(),T=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        int sum=read();
        for(int j=1;j<=n;j++) v[j][i&1]=0;
        for(int j=1;j<=sum;j++){
            int x=read(),y=read();
            if(!len[x]) len[x]=y;
            if(v[x][!(i&1)]){
                int dw=0;
                if(len[x]) dw=len[x]+y;
                g[i-1].push_back({i,dw});
                g[i].push_back({i-1,dw});
            }
            v[x][i&1]=1;
            s[x].push_back(i);
        }
    }
    while(T--){
        int x=read(),y=read();
        int ans=DFF;
        for(int i=0;i<s[x].size();i++){
            for(int j=0;j<s[y].size();j++){
                ans=min(ans,dij(s[x][i],s[y][j]));
            }
        }
        ans+=len[x]+w[x]+len[y]+w[y];
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
