#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pai;
const int N=5e5+10;
int c,n,m,d,q,w[N],f[N],a[510][N],t[510][N],x,y;
ll dis[N];
vector<pai> e[N];
queue<int> p;
/*int find(int u){
    if(f[u]==u) return u;
    return f[u]=find(f[u]);
}
void join(int u,int v){
    int u=find(u);
    int v=find(v);
    if(u==v) return;
    f[v]=u;
}*/
void dijkstra(){
    while(p.size()){
        int u=p.front();
        p.pop();
        for(auto i:e[u]){
            int v=i.second;
            int w=i.first;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                p.push(v);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k,u,v,t1,t2;cin>>k>>u>>t1>>v>>t2;
        e[u].push_back({t1+t2,v});
        e[v].push_back({t1+t2,i});
    }for(int i=1;i<=q;i++){
        memset(dis,0x3f,sizeof(dis));
        cin>>x>>y;
        dis[x]=w[x];
        p.push(x);
        dijkstra();
        cout<<dis[y]+w[y]<<"\n";
    }return 0;
}