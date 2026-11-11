#include<iostream>
#include<algorithm>
#include<queue>
using ll=long long;
const int sz=2e6+10;
const ll inf=0x3fffffffffffffff;
ll p[sz],f[sz];
int dis[sz];
std::basic_string<int>graph[sz];
int main(){
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int c,t;
  std::cin>>c>>t;
  while(t--){
    int n;
    ll d;
    std::cin>>n>>d;
    for(int i=1;i<=n;i++)std::cin>>p[i];
    ll ans=0;
    for(int c=1;c<=n;c++){
      for(int i=1;i<=n;i++)graph[i].clear();
      std::fill(dis+1,dis+n+1,0);
      for(int i=c;i<=n;i++){
        for(int j=i+1;j<=n&&p[j]-p[i]<=d;j++){
          if(dis[j]==0)dis[j]=dis[i]+1;
          if(dis[j]==dis[i]+1)graph[i]+=j;
        }
      }
      std::fill(f+1,f+n+1,0);
      f[c]=1;
      for(int u=c;u<=n;u++)
        for(int v:graph[u])f[v]=std::min(inf,f[u]+f[v]);
      ans+=std::count(f+c,f+n+1,2);
    }
    std::cout<<ans<<"\n";
  }
  return 0;
}