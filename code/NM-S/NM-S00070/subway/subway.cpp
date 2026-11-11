#include<iostream>
#include<algorithm>
#include<vector>
using ll=long long;
const int sz=1e6+10;
const int lgsz=std::__lg(sz)+10;
std::vector<std::pair<int,ll>>graph[sz];
ll w[sz],cnt[sz];
std::vector<std::pair<ll,std::pair<int,int>>>edges;
struct UFS{
  int fa[sz],ssz[sz];
  void clear(int n){
    for(int i=1;i<=n;i++)fa[i]=i,ssz[i]=1;
  }
  int find(int u){
    if(fa[u]==u)return u;
    return fa[u]=find(fa[u]);
  }
  void merge(int u,int v){
    int fu=find(u),fv=find(v);
    if(fu==fv)return;
    if(ssz[fu]>ssz[fv])std::swap(fu,fv);
    fa[fu]=fv,ssz[fv]+=ssz[fu];
  }
}ufs;
int dep[sz],anc[sz][lgsz];
ll dis[sz];
void dfs(int u,int fau){
  dep[u]=dep[fau]+1,anc[u][0]=fau;
  for(int i=1;i<=std::__lg(dep[u]);i++)anc[u][i]=anc[anc[u][i-1]][i-1];
  for(auto [v,w]:graph[u]){
    if(v==fau)continue;
    dis[v]=dis[u]+w;
    dfs(v,u);
  }
}
int lca(int u,int v){
  if(dep[u]<dep[v])std::swap(u,v);
  while(dep[u]>dep[v])u=anc[u][std::__lg(dep[u]-dep[v])];
  if(u==v)return u;
  for(int i=std::__lg(dep[u]);i>=0;i--)
    if(anc[u][i]!=anc[v][i])u=anc[u][i],v=anc[v][i];
  return anc[u][0];
}
int main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int c,n,m,d,q,N=0;
  std::cin>>c>>n>>m>>d>>q;
  for(int i=1;i<=m;i++)std::cin>>w[i];
  N=m;
  for(int i=1,k;i<=n;i++){
    std::cin>>k;
    for(int j=0,a,t,lst=0;j<k;j++){
      std::cin>>a>>t;
      edges.emplace_back(t,std::make_pair(a,++N));
      if(lst!=0){
        graph[lst].emplace_back(N,0);
        graph[N].emplace_back(lst,0);
      }
      lst=N;
    }
  }
  ufs.clear(N);
  for(int i=m+1;i<=N;i++)
    for(auto [v,w]:graph[i])ufs.merge(i,v);
  std::sort(edges.begin(),edges.end());
  for(auto [w,p]:edges){
    auto [u,v]=p;
    if(ufs.find(u)==ufs.find(v))continue;
    ufs.merge(u,v);
    graph[u].emplace_back(v,w);
    graph[v].emplace_back(u,w);
  }
  dfs(1,0);
  while(q--){
    int x,y;
    std::cin>>x>>y;
    std::cout<<dis[x]+dis[y]-2*dis[lca(x,y)]+w[x]+w[y]<<"\n";
  }
  return 0;
}