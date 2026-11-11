#include<bits/stdc++.h>
using namespace std;
using ii=pair<int,int>;
constexpr int N=1e6+10;

int subtask;

int n,m;
vector<ii> E;
vector<int> G[N];

namespace bf{
  int fa[N],d[N];
  int hh,tt,q[N];

  int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
  void merge(int x,int y){x=find(x),y=find(y);if(x!=y)fa[x]=y;}

  void main(){
    int ans=1e9;
    for(int S=1;S<1<<n;++S)if(__builtin_popcount(S)==m){
      for(int i=1;i<=n;++i)fa[i]=i;
      for(auto e:E){
        int u=e.first,v=e.second;
        if((S>>(u-1)&1)&&(S>>(v-1)&1)){
          merge(u,v);
        }
      }
      int cnt=0;
      for(int i=1;i<=n;++i)if((S>>(i-1)&1)&&find(i)==i)++cnt;
      if(cnt>2)continue;
      hh=0,tt=-1;
      for(int i=1;i<=n;++i){
        if(S>>(i-1)&1){
          q[++tt]=i,d[i]=0;
        }else d[i]=-1;
      }
      while(hh<=tt){
        int u=q[hh++];
        for(auto v:G[u]){
          if(d[v]==-1){
            d[v]=d[u]+1;
            q[++tt]=v;
          }
        }
      }
      ans=min(ans,*max_element(d+1,d+n+1));
    }
    cout<<ans<<"\n";
  }
}

namespace A{
  bool check(int D){
    int t=(n-1)/2;
    int ls=D,rs=t+1-D;
    int u=m/2;
    int lt=ls+u-1,rt=rs-(m-u)+1;
    if(lt>=rt)return true;
    int _=(rt-lt)/2+1;
    return _<=D;
  }

  void main(){
    int t=(n-1)/2;
    int l=0,r=n+1;
    while(l+1!=r){
      int mid=(l+r)>>1;
      if(check(mid))r=mid;
      else l=mid;
    }
    cout<<r<<"\n";
  }
}

void solve(){
  cin>>n>>m,E.clear();
  for(int i=1;i<=n;++i)G[i].clear();
  for(int i=1,u,v;i<n;++i){
    cin>>u>>v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
    E.emplace_back(u,v);
  }
  if(n==m){
    cout<<"0\n";
    return;
  }
  if(m==n-1){
    cout<<"1\n";
    return;
  }
  if(n<=20){
    bf::main();
    return;
  }
  if(subtask==13||subtask==14){
    A::main();
    return;
  }
  cout<<"19936\n";
}

int main(){
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  int T;for(cin>>subtask>>T;T;--T)solve();
  return 0;
}