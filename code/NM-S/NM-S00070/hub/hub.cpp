#include<iostream>
#include<algorithm>
const int sz=1e6+10;
const int lgsz=std::__lg(sz);
std::basic_string<int>graph[sz];
int dis[1010][1010],max[sz];
void dfs(int u,int fau,int *dis){
  for(int v:graph[u]){
    if(v==fau)continue;
    dis[v]=dis[u]+1;
    dfs(v,u,dis);
  }
}
int main(){
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int c,t;
  std::cin>>c>>t;
  while(t--){
    int n,k;
    std::cin>>n>>k;
    for(int i=1,u,v;i<n;i++)
      std::cin>>u>>v,graph[u]+=v,graph[v]+=u;
    for(int i=1;i<=n;i++)dfs(i,0,dis[i]);
    int ans=n;
    for(int x=1;x<=n;x++){
      for(int y=1;y<=n;y++){
        int res=0;
        for(int i=1;i<=n;i++)
          res=std::max(res,std::min(dis[x][i],dis[y][i]));
        ans=std::min(ans,res);
      }
    }
    std::cout<<ans<<"\n";
  }
  return 0;
}