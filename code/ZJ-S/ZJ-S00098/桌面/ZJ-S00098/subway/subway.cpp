#include<bits/stdc++.h>
using namespace std;
using i64=long long;
using ll=pair<long long,long long>;
constexpr i64 INF=0x3f3f3f3f3f3f3f3f;
constexpr int N=510,M=5e5+10,D=20;

i64 dis[N][N];
vector<ll> bel[M];
int subtask,n,m,d,q,w[M];

int main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin>>subtask>>n>>m>>d>>q,memset(dis,0x3f,sizeof dis);
  for(int i=1;i<=n;++i)dis[i][i]=0;
  for(int i=1;i<=m;++i)cin>>w[i];
  for(int i=1;i<=n;++i){// Line i
    int s;cin>>s;
    for(int j=0,u,t;j<s;++j){
      cin>>u>>t;
      bel[u].emplace_back(i,t);
    }
  }
  for(int i=1;i<=m;++i){
    auto &t=bel[i];
    int sz=(int)t.size();
    for(int j=0;j<sz;++j){
      i64 u=t[j].first,ut=t[j].second;
      for(int k=j+1;k<sz;++k){
        i64 v=t[k].first,vt=t[k].second;
        dis[u][v]=min<i64>(dis[u][v],ut+vt);
        dis[v][u]=min<i64>(dis[v][u],ut+vt);
      }
    }
  }
  for(int k=1;k<=n;++k)
    for(int i=1;i<=n;++i)
      for(int j=1;j<=n;++j)
        dis[i][j]=min<i64>(dis[i][j],dis[i][k]+dis[k][j]);
  for(int u,v;q;--q){
    cin>>u>>v;
    i64 now=INF;
    for(auto pu:bel[u])for(auto pv:bel[v]){
      now=min<i64>(now,dis[pu.first][pv.first]+pu.second+pv.second);
    }
    cout<<now+w[u]+w[v]<<"\n";
  }
  return 0;
}